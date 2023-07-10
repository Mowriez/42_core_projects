/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_check_input_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 21:47:13 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/03 23:21:31 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_double(char *s, int *i, int which)
{
	*i += skip_spaces(&s[*i + 2]) + 2;
	if (s[*i] == '\0' || s[*i] == '|' || s[*i] == '>' || s[*i] == '<')
	{
		if (which == 1)
			return (lex_err_msg(" near unexpected token: `newline'"));
		else if (which == 2)
			return (lex_err_msg(" near unexpected token: `newline'"));
	}
	return (*i);
}

int	skip_spaces(char *input)
{
	int	i;

	i = 0;
	while (input[i] == ' ')
		i++;
	return (i);
}
