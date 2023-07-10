/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:24:11 by eramusho          #+#    #+#             */
/*   Updated: 2023/07/05 15:33:14 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// to print the arguments starting after echo / echo -n.
static void	print_args(char	**args, int start)
{
	int	index;

	index = start;
	while (args[index])
	{
		ft_putstr_fd(args[index], 1);
		if (args[index + 1])
			ft_putstr_fd(" ", 1);
		index++;
	}
}

/*checks if the flag -n is set*/
static int	check_no_newline(char *arg)
{
	int	index;

	index = 1;
	if (arg[0] != '-')
		return (0);
	while (arg[index])
	{
		if (arg[index] != 'n')
			return (0);
		index++;
	}
	return (1);
}

/*runs the functions to represent the echo builtin*/
int	builtin_echo(char **args)
{
	int	index;
	int	newline;

	index = 1;
	newline = 1;
	if (!args[index])
	{
		ft_putstr_fd("\n", 1);
		return (0);
	}
	while (args[index] && check_no_newline(args[index]))
	{
		newline = 0;
		index++;
	}
	print_args(args, index);
	if (newline != 0)
		ft_putstr_fd("\n", 1);
	g_exit = 0;
	return (0);
}
