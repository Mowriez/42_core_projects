/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_check_input_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 21:15:58 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/05 14:55:21 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*basic lexer error message function*/
int	lex_err_msg(char *description)
{
	ft_exit_status(description, 2, "syntax error");
	ft_printf("\n");
	return (-1);
}

/*checks for missused pipe char combinations*/
int	check_empty_pipes(char *rl_input)
{
	int	i;

	i = 0;
	while (rl_input[i] == ' ')
		i++;
	if (rl_input[i] == '|')
		return (lex_err_msg("near unexpected token `|'"));
	while (rl_input[i] != '\0')
	{
		if (rl_input[i] == '"')
			i += skip_char(&rl_input[i], '"');
		else if (rl_input[i] == '\'')
			i += skip_char(&rl_input[i], '\'');
		else if (rl_input[i] == '|')
		{
			i++;
			while (rl_input[i] == ' ')
				i++;
			if (rl_input[i] == '|' || rl_input[i] == '\0')
				return (lex_err_msg("near unexpected token `|'"));
		}
		else
			i++;
	}
	return (0);
}

/*skips one instance of char c in string input, doesn't check the first
occurence, if its the firs char in input (to not stop on the beginning
of a quoted string snippet)*/
int	skip_char(char *input, char c)
{
	int	i;

	i = 0;
	if (input[i] == c)
		i = 1;
	while (input[i] != c)
		i++;
	return (i + 1);
}

/*checks for bad combinations of redir chars*/
int	check_redirs(char *input)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (input[i] != '\0' && k != -1)
	{
		if (input[i] == '\'')
			i += skip_char(&input[i], '\'');
		else if (input[i] == '"')
			i += skip_char(&input[i], '"');
		else if (input[i] == '<' && input[i + 1] != '<')
			k = check_single(input, &i, 1);
		else if (input[i] == '<' && input[i + 1] == '<')
			k = check_double(input, &i, 1);
		else if (input[i] == '>' && input[i + 1] != '>')
			k = check_single(input, &i, 2);
		else if (input[i] == '>' && input[i + 1] == '>')
			k = check_double(input, &i, 2);
		else
			i++;
	}
	return (k);
}

int	check_single(char *s, int *i, int which)
{
	*i += skip_spaces(&s[*i + 1]) + 1;
	if (s[*i] == '\0' || s[*i] == '|' || s[*i] == '>' || s[*i] == '<')
	{
		if (which == 1)
			return (lex_err_msg("near unexpected token `newline'"));
		else if (which == 2)
			return (lex_err_msg("near unexpected token `newline'"));
	}
	return (*i);
}
