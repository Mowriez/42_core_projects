/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:33:21 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/05 21:06:44 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// deallocates the nodes of the env_ll
void	free_env_ll(t_env *head)
{
	t_env	*temp;

	temp = head;
	while (head->next != NULL)
	{
		temp = head->next;
		free(head->string);
		free(head->key);
		free(head->value);
		free(head);
		head = temp;
	}
	free(head->string);
	free(head->key);
	free(head->value);
	free(head);
}

// deallocates the nodes of the cmd_ll
void	free_cmd_ll(t_cmd *head)
{
	t_cmd	*temp;

	temp = NULL;
	while (head != NULL)
	{
		temp = head;
		if (head->cmd)
			free(head->cmd);
		free_double_arr(head->cmd_arr);
		if (head->input_fd != STDIN_FILENO)
			close(head->input_fd);
		if (head->output_fd != STDOUT_FILENO)
			close(head->output_fd);
		head = head->next;
		free(temp);
	}
}
// && head->next != NULL
	// if (head != NULL)
	// {
	// 	if (head->cmd)
	// 		free(head->cmd);
	// 	free_double_arr(head->cmd_arr);
	// 	if (head->input_fd != STDIN_FILENO)
	// 		close(head->input_fd);
	// 	if (head->output_fd != STDOUT_FILENO)
	// 		close(head->output_fd);
	// 	free(head);
	// }

/*frees most (char **)*/
void	free_double_arr(char **arr)
{
	int	index;

	index = 0;
	while (arr && arr[index] != NULL)
	{
		free(arr[index]);
		index++;
	}
	if (arr)
		free(arr);
}

/* empties the ms_struct after a successful run through one user input line 
and prepares the programm for the next call*/

void	clean_up_run(t_ms *ms_struct)
{
	free_cmd_ll(ms_struct->cmd_ll);
	reset_ms_struct(ms_struct);
}

/*resets the main struct to initial settings*/
void	reset_ms_struct(t_ms *ms_struct)
{
	if (ms_struct->rl_input)
		free(ms_struct->rl_input);
	if (ms_struct->new_path)
	{
		free(ms_struct->new_path);
		ms_struct->new_path = NULL;
	}
	if (ms_struct->old_path)
	{
		free(ms_struct->old_path);
		ms_struct->old_path = NULL;
	}
}
