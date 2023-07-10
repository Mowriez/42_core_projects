/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_check_input_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramusho <eramusho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:01:05 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/06 01:25:59 by eramusho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*checks for args after ./minishell*/
void	check_args(int argc, char **argv)
{
	if (argc > 1 || argv[0] == 0)
	{
		ft_putstr_fd("Error: No arguments permitted.\n", 2);
		exit (1);
	}
	if (argv[0] == NULL)
	{
		ft_putstr_fd("Error: Need to use argv, otherwise gcc acts up.\n", 2);
		exit (1);
	}
}

/*checks input for open quotes, empty input, exit, ...*/
int	check_rl_input(t_ms *ms_struct)
{
	if (check_quotes(ms_struct->rl_input) == -1)
		return (free_in_check_rl_input(ms_struct->rl_input));
	else if (check_empty_prompt(ms_struct->rl_input) == -1)
		return (free_in_check_rl_input(ms_struct->rl_input));
	else if (check_special_chars(ms_struct->rl_input) == -1)
		return (free_in_check_rl_input(ms_struct->rl_input));
	else if (check_empty_pipes(ms_struct->rl_input) == -1)
		return (free_in_check_rl_input(ms_struct->rl_input));
	else if (check_redirs(ms_struct->rl_input) == -1)
		return (free_in_check_rl_input(ms_struct->rl_input));
	return (0);
}

/*subfunction for quotes-check*/
int	check_quotes(char *input)
{
	int		i;
	char	quote_type;
	int		open_quote;

	i = 0;
	open_quote = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '"' || input[i] == '\'')
		{
			if (!open_quote)
			{
				quote_type = input[i];
				open_quote = 1;
			}
			else if (quote_type == input[i])
				open_quote = 0;
		}
		i++;
	}
	if (open_quote)
		return (lex_err_msg("Quotes not closed."));
	return (0);
}

/*subfunction for empty-prompt-check*/
int	check_empty_prompt(char *input)
{
	int	i;

	i = 0;
	while (input[i] == ' ' && input[i] != '\0')
		i++;
	if (input[i] == '\0')
		return (-1);
	return (0);
}

/*checks for special characters that are used wrongly.*/
int	check_special_chars(char *input)
{
	int	i;

	i = 0;
	while (input[i] != 0)
	{
		if (input[i] == '&' && input[i + 1] == '&')
			return (lex_err_msg("near unexpected token `&&'"));
		if (input[i] == '&' && input[i + 1] == '&' && input[i + 2] == '&')
			return (lex_err_msg("near unexpected token `&&'"));
		else if (input[i] == '|' && input[i + 1] == '|')
			return (lex_err_msg("near unexpected token `||'"));
		else if (input[i] == '|' && input[i + 1] == '|' && input[i + 2] == '|')
			return (lex_err_msg("near unexpected token `||'"));
		else if (input[i] == '<' && input[i + 1] == '<' && input[i + 2] == '<')
			return (lex_err_msg("near unexpected token `newline'"));
		else if (input[i] == '>' && input[i + 1] == '>' && input[i + 2] == '>')
			return (lex_err_msg("near unexpected token `>'"));
		else
			i++;
	}
	return (0);
}
