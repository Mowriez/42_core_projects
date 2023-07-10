/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:12:35 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/05 17:54:27 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*investigates the input string and divides it into separated tokens of a cer-
tain type.*/
void	lexer(char *exp_str, t_token **token_head)
{
	t_token	*token;
	int		i;

	token = NULL;
	i = 0;
	while (exp_str[i] != '\0')
	{
		if (exp_str[i] == ' ')
			token = tokenize_divider(&exp_str[i], &i);
		else if (exp_str[i] == '|')
			token = tokenize_pipe(&i);
		else if (exp_str[i] == '\'' || exp_str[i] == '"')
			token = tokenize_quotes(&exp_str[i], &i, exp_str[i]);
		else if ((exp_str[i] == '<' && exp_str[i + 1] != '<') || \
			(exp_str[i] == '>' && exp_str[i + 1] != '>'))
			token = tokenize_redir_single(exp_str, &i, exp_str[i]);
		else if ((exp_str[i] == '<' && exp_str[i + 1] == '<') || \
			(exp_str[i] == '>' && exp_str[i + 1] == '>'))
			token = tokenize_redir_double(exp_str, &i, exp_str[i]);
		else
			token = tokenize_string(&exp_str[i], &i);
		add_token_to_end(token_head, token);
	}
}

/*builds a token for string snippet of type quotes. (From open to closed
quotes)*/
t_token	*tokenize_quotes(char *exp_str, int *i, char quote_type)
{
	t_token	*token;
	int		len_val;

	len_val = len_w_o_quotes(exp_str, quote_type);
	token = malloc(sizeof(t_token));
	token->value = ft_substr(exp_str, 1, len_val);
	token->type = STRING;
	token->next = NULL;
	*i = *i + len_val + 2;
	return (token);
}

/*builds a token for string snippet of type string. (Space separated)*/
t_token	*tokenize_string(char *exp_str, int *i)
{
	t_token	*token;
	int		len_str;

	len_str = len_str_token(exp_str);
	token = malloc(sizeof(t_token));
	token->value = ft_substr(exp_str, 0, len_str);
	token->type = STRING;
	token->next = NULL;
	*i = *i + len_str;
	return (token);
}

/*builds a token for string snippet of type DIVIDER. (Spaces)*/
t_token	*tokenize_divider(char *exp_str, int *i)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	token->value = malloc(1 * sizeof(char));
	token->value[0] = '\0';
	token->type = DIV;
	token->next = NULL;
	*i = *i + len_spaces(exp_str);
	return (token);
}

/*builds a token for string snippet of type SINGLE REDIRECION. (>/<)*/
t_token	*tokenize_redir_single(char *exp_str, int *i, char redir_type)
{
	t_token	*token;
	int		len_val;

	token = malloc(sizeof(t_token));
	*i = *i + len_spaces(&exp_str[*i + 1]) + 1;
	len_val = len_redir_token(&exp_str[*i]);
	token->value = ft_substr(exp_str, *i, len_val);
	if (redir_type == '>')
		token->type = O_REDIR;
	else if (redir_type == '<')
		token->type = I_REDIR;
	token->next = NULL;
	*i = *i + len_val;
	return (token);
}
