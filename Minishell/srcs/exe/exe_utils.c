/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 23:09:20 by eramusho          #+#    #+#             */
/*   Updated: 2023/07/05 14:54:09 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	failed_fork(int pid)
{
	if (pid == -1)
	{
		ft_exit_status("Couldn't fork\n", 1, "execution");
		return (1);
	}
	return (0);
}

void	ft_exit_status(char *str, int exit_code, char *cmd)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str, 2);
	g_exit = exit_code;
}

int	ft_strerror_status(int exit_status, char *cmd)
{
	ft_exit_status(strerror(exit_status), exit_status, cmd);
	write(2, "\n", 1);
	return (-1);
}

void	heredoc_exit(int signal)
{
	if (signal == SIGINT)
		exit(23);
}

/*makes the env ll into an char ** array*/
char	**copy_mod_env(t_env *env_ll)
{
	int		count;
	t_env	*temp;
	char	**mod_env;

	temp = env_ll;
	count = 0;
	while (temp)
	{
		temp = temp->next;
		count++;
	}
	mod_env = (char **)malloc((count + 1) * sizeof(char *));
	if (!mod_env)
		return (NULL);
	temp = env_ll;
	count = 0;
	while (temp)
	{
		mod_env[count] = ft_strdup(temp->string);
		temp = temp->next;
		count++;
	}
	mod_env[count] = NULL;
	return (mod_env);
}
