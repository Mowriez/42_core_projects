/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:10:00 by mtrautne          #+#    #+#             */
/*   Updated: 2023/03/18 21:07:44 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

char	**populate_path_arr(char **envp, t_pipex *vars)
{
	int		i;
	char	*path;
	char	**path_arr;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == NULL && envp[i] != NULL)
		i++;
	if (envp[i] == NULL)
		error_handling(4, vars, "No env-variables available\n");
	path = ft_strtrim(envp[i], "PATH=");
	path_arr = ft_split(path, ':');
	free(path);
	return (path_arr);
}

char	**populate_argv_array(int argc, char **argv)
{
	int		i;
	char	**arr;

	i = 0;
	arr = (char **)malloc(argc * sizeof(char *));
	while (i < (argc - 1))
	{
		arr[i] = ft_strdup(argv[i + 1]);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

t_pipex	*populate_struct(int argc, char **argv, char **envp)
{
	t_pipex	*vars;

	vars = (t_pipex *)malloc(sizeof(t_pipex));
	if (!vars)
		return (NULL);
	vars->path_dirs = populate_path_arr(envp, vars);
	vars->argv_arr = populate_argv_array(argc, argv);
	vars->empty_fd = open("./empty", O_RDONLY | O_CREAT, 0777);
	vars->error = 0;
	return (vars);
}
