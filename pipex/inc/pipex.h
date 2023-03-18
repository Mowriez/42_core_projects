/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:32:49 by mtrautne          #+#    #+#             */
/*   Updated: 2023/03/18 20:36:42 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include "../src/libft/libft.h"

// delete temp_helper functions before handing project in!!!!

// struct for storing input vars
typedef struct s_pipex {
	char	**path_dirs;
	char	**argv_arr;
	int		empty_fd;
	int		error;
}	t_pipex;

// exec_helpers.c
char	*path_to_exec(t_pipex *vars, char *cmd);
char	**set_exec_arr(t_pipex *vars, int i);
void	exec_cmd(t_pipex *vars, int i, char **envp);
void	exec_last_cmd(t_pipex *vars, int output_fd, int i, char **envp);

// array_modification.c
char	**set_up_arr(t_pipex *vars, int i);
char	**fix_quot_mark_arr(t_pipex *vars, char **basic_arr, int start);
char	**build_correct_arr(char **arr, int start, int stop, t_pipex *vars);
char	*set_temp_str(int j, int stop, char**arr, t_pipex *vars);

// input_error_free_helpers.c
int		input_check_fd(int argc, char **argv, int *input_fd, int *output_fd);
void	error_handling(int error_code, t_pipex *vars, char *str);
void	perror_check(int ret, char *function_name, t_pipex *vars);
void	free_struct(t_pipex *vars);
void	free_arr(char **arr);

// pipex.c
void	delete_empty_file(void);

//struct_helpers.c
char	**populate_path_arr(char **envp, t_pipex *vars);
char	**populate_argv_array(int argc, char **argv);
t_pipex	*populate_struct(int argc, char **argv, char **envp);

#endif
