/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:33:20 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/10 22:26:24 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*checks for and returns a valid path for the token*/
void	set_cmd_path(t_cmd *cmd)
{
	char	**paths;
	int		i;

	if (functioning_path(cmd))
		return ;
	if (cmd->cmd_arr[0] && cmd->cmd_arr[0][0] == '.'
		&& cmd->cmd_arr[0][1] == '/')
		return ;
	if (cmd->cmd_arr[0] && cmd->cmd_arr[0][0] == '.'
		&& cmd->cmd_arr[0][1] == '.' && cmd->cmd_arr[0][2] == '/')
		return ;
	if (cmd->cmd_arr[0] && cmd->cmd_arr[0][0] == '/')
		return ;
	paths = get_possible_paths(cmd);
	if (no_path(paths, cmd))
		return ;
	cmd->cmd = strjoin_paths(paths[0], cmd->cmd_arr[0]);
	i = 0;
	while (paths[i] && (access(cmd->cmd, X_OK) != 0))
	{
		free(cmd->cmd);
		cmd->cmd = ft_strjoin(paths[i], cmd->cmd_arr[0]);
		i++;
	}
	while (paths[i])
		free(paths[i++]);
	free(paths);
}

char	**get_possible_paths(t_cmd *cmd)
{
	t_paths	p;

	p.j = 0;
	p.k = 0;
	p.tk = cmd->ms_struct->env_ll;
	while (p.tk->next != NULL && (ft_strnstr(p.tk->string, "PATH=", 5) == NULL))
		p.tk = p.tk->next;
	if (p.tk->next == NULL && (ft_strnstr(p.tk->string, "PATH=", 5) == NULL))
		return (NULL);
	p.paths = ft_split(p.tk->value, ':');
	while (p.paths[p.j])
	{
		p.k = 0;
		while (p.paths[p.j][p.k])
			p.k++;
		if (p.paths[p.j][p.k - 1] != '/')
		{
			p.tmp = p.paths[p.j];
			p.paths[p.j] = strjoin_paths(p.paths[p.j], "/");
			free(p.tmp);
		}
		p.j++;
	}
	return (p.paths);
}

/*checks for builtins*/
int	check_for_builtin(char *cmd_string)
{
	if (!ft_strncmp(cmd_string, "echo", 5))
		return (1);
	else if (!ft_strncmp(cmd_string, "cd", 3))
		return (1);
	else if (!ft_strncmp(cmd_string, "pwd", 4))
		return (1);
	else if (!ft_strncmp(cmd_string, "export", 7))
		return (1);
	else if (!ft_strncmp(cmd_string, "unset", 6))
		return (1);
	else if (!ft_strncmp(cmd_string, "env", 4))
		return (1);
	else if (!ft_strncmp(cmd_string, "exit", 5))
		return (1);
	return (0);
}

/*stringjoin function that frees the join-target string*/
char	*strjoin_paths(char *target, char *addition)
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
		ft_exit_status("malloc failed in strjoin_paths\n", 1, "malloc");
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
