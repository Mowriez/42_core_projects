/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:45:40 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/05 19:48:34 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*frees the main struct*/
void	free_ms_struct(t_ms *data)
{
	free_env_ll(data->env_ll);
	free(data->rl_input);
	free(data->new_path);
	free(data->old_path);
}

int	free_in_check_rl_input(char *rl_input)
{
	free(rl_input);
	return (-1);
}

void	free_token_ll(t_token *head)
{
	t_token	*temp;

	while (head->next != NULL)
	{
		temp = head;
		if (head->value)
			free(head->value);
		head = head->next;
		free(temp);
	}
	if (head->value)
		free(head->value);
	free(head);
}
