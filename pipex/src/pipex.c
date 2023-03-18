/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:33:40 by mtrautne          #+#    #+#             */
/*   Updated: 2023/03/18 21:10:25 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*vars;
	int		input_fd;
	int		output_fd;
	int		i;
	int		error;

	i = 1;
	if (input_check_fd(argc, argv, &input_fd, &output_fd) != 0)
		i++;
	vars = populate_struct(argc, argv, envp);
	if (!vars)
		error_handling(2, vars, "struct malloc failed\n");
	perror_check(dup2(input_fd, STDIN_FILENO), "dup2 input", vars);
	while (i < argc - 3)
	{
		exec_cmd(vars, i, envp);
		i++;
	}
	exec_last_cmd(vars, output_fd, i, envp);
	close(input_fd);
	close(output_fd);
	error = vars->error;
	free_struct(vars);
	delete_empty_file();
	return (error);
}

void	delete_empty_file(void)
{
	if (access("./empty", F_OK) == 0)
		unlink("./empty");
}
