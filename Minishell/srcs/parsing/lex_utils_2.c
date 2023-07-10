/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:33:01 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/05 03:06:30 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*calculates the lenght of string until the next char of type delimiter*/
int	len_redir_token(char *exp_str)
{
	int		i;
	int		j;
	char	*delimiter;

	i = 0;
	delimiter = " ><|";
	while (exp_str[i] != '\0')
	{
		j = 0;
		while (delimiter[j] != '\0')
		{
			if (exp_str[i] == delimiter[j])
				return (i);
			else
				j++;
		}
		i++;
	}
	return (i);
}

/*returns the lenght of a number of uninterrupted spaces us exp_str*/
int	len_spaces(char *exp_str)
{
	int	i;

	i = 0;
	while (exp_str[i] == ' ')
		i++;
	return (i);
}
