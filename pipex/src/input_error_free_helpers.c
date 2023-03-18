/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error_free_helpers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 01:41:14 by mtrautne          #+#    #+#             */
/*   Updated: 2023/03/18 21:08:23 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	input_check_fd(int argc, char **argv, int *input_fd, int *output_fd)
{
	if (argc < 5)
	{
		ft_putstr_fd("Error: Incorrect number of arguments. (Needs 5+)\n", 2);
		exit(1);
	}
	*input_fd = open(argv[1], O_RDONLY);
	*output_fd = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (*input_fd == -1)
	{
		perror("pipex: input");
		*input_fd = open("./empty", O_RDONLY | O_CREAT, 0777);
		return (1);
	}
	return (0);
}

void	error_handling(int error_code, t_pipex *vars, char *str)
{
	ft_putstr_fd("pipex: ", 2);
	if (error_code == 1)
	{
		ft_putstr_fd(str, 2);
		exit(1);
	}
	else if (error_code == 2)
	{
		ft_putstr_fd(str, 2);
		free_struct(vars);
		exit(2);
	}
	else if (error_code == 3)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": command not found", 2);
		ft_putstr_fd("\n", 2);
	}
	else if (error_code == 4)
	{
		ft_putstr_fd(str, 2);
		free_struct(vars);
		exit(2);
	}
}

void	perror_check(int ret, char *function_name, t_pipex *vars)
{
	if (ret == -1)
	{
		perror(function_name);
		free_struct(vars);
		exit(1);
	}
}

void	free_struct(t_pipex *vars)
{
	free_arr(vars->path_dirs);
	free_arr(vars->argv_arr);
	free(vars);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr[i]);
	free(arr);
}
