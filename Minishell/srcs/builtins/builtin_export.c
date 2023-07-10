/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramusho <eramusho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:56:04 by eramusho          #+#    #+#             */
/*   Updated: 2023/07/05 22:17:59 by eramusho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	print_export_no_args(t_ms *data)
{
	t_env	*current;

	current = data->env_ll;
	while (current)
	{
		write(1, "declare -x ", 11);
		ft_putstr_fd(current->key, 1);
		write(1, "=\"", 2);
		ft_putstr_fd(current->value, 1);
		write(1, "\"", 1);
		write(1, "\n", 1);
		current = current->next;
	}
}

void	add_var_env_ll(t_ms *data, char *str_var)
{
	t_env	*new_var;
	t_env	*current;

	new_var = make_new_node(str_var);
	if (!new_var)
		ft_exit_status("Allocation for new env failed\n", 1, "malloc");
	if (data->env_ll == NULL)
		data->env_ll = new_var;
	else
	{
		current = data->env_ll;
		while (current->next != NULL)
			current = current->next;
		current->next = new_var;
	}
}

int	check_update_env(t_ms *data, char *str_var, char *key, int k_size)
{
	t_env	*current;
	char	*value;
	char	*tmp;

	value = ft_strchr(str_var, '=') + 1;
	current = data->env_ll;
	while (current != NULL)
	{
		if (ft_strncmp(current->key, key, k_size) == 0
			&& (int)ft_strlen(current->key) == k_size)
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
	return (0);
}

// if you want to update the env it checks if the variable(key) exit so it only
// needs to change the value of it, if the variable don't exit it adds it end
void	builtin_export(t_ms *data, char **args)
{
	char	*key;
	int		i;
	int		key_sz;

	i = 1;
	if (check_no_args(data, args))
		return ;
	while (args[i])
	{
		if (ft_strchr(args[i], '=') == NULL)
			i++;
		else if (ft_strchr(args[i], '=') != NULL)
		{
			key_sz = (ft_strlen(args[i]) - ft_strlen(ft_strchr(args[i], '=')));
			key = ft_substr(args[i], 0, key_sz);
			check_valid_var(key, key_sz, data, args[i]);
			free(key);
			i++;
		}
	}
}

void	check_valid_var(char *key, int key_sz, t_ms *data, char *arg)
{
	if (is_valid_var_name(key) == 1)
	{
		if (check_update_env(data, arg, key, key_sz) == 0)
		{
			add_var_env_ll(data, arg);
			g_exit = 0;
		}
	}
	else
		ft_exit_status("invalid input to export\n", 1, "export");
	return ;
}
