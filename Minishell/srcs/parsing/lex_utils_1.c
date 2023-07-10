/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:12:35 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/05 03:03:56 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*builds a token for string snippet of type DOUBLE REDIRECTION. (>>/<<)*/
t_token	*tokenize_redir_double(char *exp_str, int *i, char redir_type)
{
	t_token	*token;
	int		len_val;

	token = malloc(sizeof(t_token));
	*i = *i + len_spaces(&exp_str[*i + 2]) + 2;
	len_val = len_redir_token(&exp_str[*i]);
	token->value = ft_substr(exp_str, *i, len_val);
	if (redir_type == '>')
		token->type = APPEND_REDIR;
	else if (redir_type == '<')
		token->type = H_DOC;
	token->next = NULL;
	*i = *i + len_val;
	return (token);
}

/*builds a token for string snippet of type PIPE. (|)*/
t_token	*tokenize_pipe(int *i)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	token->value = malloc(1 * sizeof(char));
	token->value[0] = '\0';
	token->type = PIPE;
	token->next = NULL;
	*i = *i + 1;
	return (token);
}

/*adds new_node to the end of token_head linked list*/
void	add_token_to_end(t_token **token_head, t_token *new_node)
{
	t_token	*current;

	if (*token_head == NULL)
		*token_head = new_node;
	else
	{
		current = *token_head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
	}
}

/*returns the lenght of exp_str minus number of quotes of type "quote type"*/
int	len_w_o_quotes(char *exp_str, char quote_type)
{
	int	i;

	i = 1;
	while (exp_str[i] != quote_type)
		i++;
	return (i - 1);
}

/*calculates the len of the string in the lexer_token.*/
int	len_str_token(char *exp_str)
{
	int		i;
	int		j;
	char	*delimiter;

	i = 0;
	delimiter = " ><|\"'";
	while (exp_str[i] != '\0')
	{
		j = 0;
		while (delimiter[j] != '\0')
		{
			if (exp_str[i] == delimiter[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
