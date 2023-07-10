/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:27:01 by eramusho          #+#    #+#             */
/*   Updated: 2023/07/06 10:14:42 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*get_env_val(t_env *env_ll, char *key, int key_size)
{
	t_env	*current;

	current = env_ll;
	while (current != NULL)
	{
		if (ft_strncmp(current->key, key, key_size) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}
// get the value of an env variable -> primary used to get value of HOME

void	builtin_cd(t_ms *data, char **args)
{
	char	*path_home;
	char	*tmp_path;

	path_home = get_env_val(data->env_ll, "HOME", 4);
	if (!path_home && args[1] == NULL)
	{
		ft_exit_status("cd: no such file or directory\n", 1, "");
		return ;
	}
	if (args[1] == NULL)
		tmp_path = path_home;
	else
		tmp_path = args[1];
	if (data->old_path)
		free(data->old_path);
	data->old_path = ft_strdup(getcwd(data->ms_cwd, sizeof(data->ms_cwd)));
	if (chdir(tmp_path) != 0)
	{
		ft_exit_status("cd: no such file or directory\n", 1, tmp_path);
		return ;
	}
	reset_env_directory_entries(data);
	g_exit = 0;
}

void	reset_env_directory_entries(t_ms *data)
{
	if (data->new_path)
		free(data->new_path);
	data->new_path = ft_strdup(getcwd(data->ms_cwd, sizeof(data->ms_cwd)));
	check_update_env_2(data, data->old_path, "OLDPWD", 6);
	check_update_env_2(data, data->new_path, "PWD", 3);
}

int	check_update_env_2(t_ms *data, char *str_var, char *key, int k_size)
{
	t_env	*current;
	char	*value;
	char	*tmp;

	value = str_var;
	current = data->env_ll;
	while (current != NULL)
	{
		if (ft_strncmp(current->key, key, k_size) == 0 && \
			((int)ft_strlen(current->key) == k_size))
		{
			free(current->string);
			tmp = strjoin_cmd_arr(key, "=");
			current->string = ft_strjoin_mod(tmp, value);
			free(current->value);
			current->value = ft_strdup(value);
			return (1);
		}
		current = current->next;
	}
	if (!current)
		add_var_env_ll(data, str_var);
	return (0);
}
