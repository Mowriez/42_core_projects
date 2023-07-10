/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramusho <eramusho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:39:53 by eramusho          #+#    #+#             */
/*   Updated: 2023/07/05 21:38:37 by eramusho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// prints then env out -> dont forget it prints string, be sure that string,
// key, value are always the same otherwise you will run into problems
void	output_env_ll(t_ms *data)
{
	t_env	*current;

	current = data->env_ll;
	while (current)
	{
		ft_putstr_fd(current->string, 1);
		write(1, "\n", 1);
		current = current->next;
	}
	g_exit = 0;
}

/*checks for shell level in original env and increments it, when minishell is
started*/
void	increment_shlvl(t_ms *data)
{
	t_env	*current;
	int		lvl;
	char	*tmp;
	char	*shlvl;

	current = data->env_ll;
	lvl = 1;
	while (current != NULL)
	{
		if (ft_strncmp(current->key, "SHLVL", 5) == 0)
		{
			lvl = ft_atoi(current->value) + 1;
			break ;
		}
		current = current->next;
	}
	tmp = ft_itoa(lvl);
	shlvl = strjoin_cmd_arr("SHLVL=", tmp);
	free(current->value);
	free(current->string);
	current->value = tmp;
	current->string = shlvl;
}

//updates the env SHLVL -> dont use it for printing the env_ll
void	update_shlvl(t_ms *data)
{
	t_env	*current;

	current = data->env_ll;
	while (current != NULL)
	{
		if (ft_strncmp("SHLVL", current->key, 5) == 0)
			increment_shlvl(data);
		current = current->next;
	}
}
