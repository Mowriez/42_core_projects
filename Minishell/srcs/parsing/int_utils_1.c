/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:22:11 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/05 14:51:06 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_token	*iterate_lex_ll(t_cmd *cmd_node, t_token **token_ll, int *cntr)
{
	t_token	*token;

	token = *token_ll;
	while (token != NULL && token->type != PIPE)
	{
		if (token->type == STRING)
			token = interpret_string(cmd_node, &token, cntr);
		else if (token->type == DIV)
			token = interpret_div(cmd_node, &token, cntr);
		else if (token->type <= H_DOC && token->type >= I_REDIR)
			token = interpret_redir(&token, cmd_node);
	}
	return (token);
}

		// if (!cmd->cmd) //maurice
		// 	return (NULL);
t_token	*interpret_string(t_cmd *cmd, t_token **token_ll, int *cntr)
{
	char	*temp_cmd_str;
	t_token	*token;

	token = *token_ll;
	temp_cmd_str = strjoin_cmd_arr(cmd->cmd_arr[*cntr], token->value);
	free(cmd->cmd_arr[*cntr]);
	cmd->cmd_arr[*cntr] = temp_cmd_str;
	if (*cntr == 0)
	{
		set_cmd_path(cmd);
	}
	return (token->next);
}

t_token	*interpret_div(t_cmd *cmd, t_token **token_ll, int *cntr)
{
	t_token	*token;
	char	*temp_cmd_str;

	token = *token_ll;
	token = token->next;
	if (token && token->type == STRING)
	{
		if (*cntr == 0 && cmd->cmd_arr[0] == NULL)
			;
		else
			*cntr += 1;
		temp_cmd_str = strjoin_cmd_arr(cmd->cmd_arr[*cntr], token->value);
		free(cmd->cmd_arr[*cntr]);
		cmd->cmd_arr[*cntr] = temp_cmd_str;
		if (*cntr == 0)
		{
			set_cmd_path(cmd);
			if (!cmd->cmd)
				return (NULL);
		}
		token = token->next;
	}
	return (token);
}

/*changes cmd to represent redirections*/
t_token	*interpret_redir(t_token **token_ll, t_cmd *cmd)
{
	t_token	*token;

	token = *token_ll;
	if (token && token->type == I_REDIR)
		input_redir(&cmd->input_fd, token->value);
	else if (token && token->type == O_REDIR)
		output_redir(&cmd->output_fd, token->value);
	else if (token && token->type == APPEND_REDIR)
		append_redir(&cmd->output_fd, token->value);
	else if (token && token->type == H_DOC)
		ft_heredoc(cmd, token->value);
	return (token->next);
}

/*strjoin function that does not free the join-target string*/
char	*strjoin_cmd_arr(char *target, char *addition)
{
	int		i;
	int		k;
	char	*j;

	i = 0;
	k = 0;
	j = (char *)malloc((ft_strlen(target) + ft_strlen(addition) + 1) * \
		sizeof(char));
	if (!j)
	{
		ft_exit_status("malloc failed in strjoin\n", 1, "ft_strjoin_arr");
		return (NULL);
	}
	while (target && target[i])
	{
		j[i] = target[i];
		i++;
	}
	while (addition[k])
		j[i++] = addition[k++];
	j[i] = '\0';
	return (j);
}
