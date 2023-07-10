/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:13:27 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/05 11:14:28 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*checks if the path-arr is empty and returns 1 on true. Sets cmd to an empty
string if token is a builtin. If paths are available, returns 0.*/
int	no_path(char **paths, t_cmd *cmd)
{
	if (paths == NULL)
	{
		if (check_for_builtin(cmd->cmd_arr[0]))
			cmd->cmd = ft_strdup("");
		return (1);
	}
	return (0);
}

/*checks if input is already a functioning full path.*/
int	functioning_path(t_cmd *cmd)
{
	if (access(cmd->cmd_arr[0], X_OK) == 0)
	{
		cmd->cmd = ft_strdup(cmd->cmd_arr[0]);
		return (1);
	}
	return (0);
}
