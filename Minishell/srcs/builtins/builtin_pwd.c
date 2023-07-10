/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:30:14 by eramusho          #+#    #+#             */
/*   Updated: 2023/07/05 15:45:04 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	builtin_pwd(t_ms *data)
{
	if (!getcwd(data->ms_cwd, sizeof(data->ms_cwd)))
	{
		ft_putstr_fd("Error in getcwd:", 2);
		return (0);
	}
	ft_putstr_fd(data->ms_cwd, 1);
	ft_putstr_fd("\n", 1);
	g_exit = 0;
	return (1);
}
// gwd() returns the current working directory if buffer is big
// enough to store, else return error message
// if cwd[0] = Invalid argument, if cwd[] <  cwd = Result too large