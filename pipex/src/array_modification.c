/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_modification.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:52:14 by mtrautne          #+#    #+#             */
/*   Updated: 2023/03/18 17:36:14 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function description:
works like ft_split, but any str inside ' or " will be treated like 1 word.*/

#include <pipex.h>

char	**set_up_arr(t_pipex *vars, int i)
{
	char	**temp_arr;
	char	**ret_arr;
	int		j;
	int		status;

	temp_arr = ft_split(vars->argv_arr[i], ' ');
	if (!temp_arr)
		error_handling(2, vars, "exec_arr: array population failed\n");
	j = 0;
	status = 0;
	while (temp_arr[j] != NULL)
	{
		if (temp_arr[j][0] == '\'' || temp_arr[j][0] == '\"')
		{
			status = 1;
			break ;
		}
		j++;
	}
	if (status == 0)
		return (temp_arr);
	ret_arr = fix_quot_mark_arr(vars, temp_arr, j);
	free(temp_arr);
	return (ret_arr);
}

char	**fix_quot_mark_arr(t_pipex *vars, char **basic_arr, int start)
{
	int		i;
	int		j;
	char	c;
	char	**ret_arr;

	i = 1;
	j = start;
	c = basic_arr[start][0];
	while (basic_arr[j] != NULL)
	{
		while (basic_arr[j][i] != 0)
		{
			if (basic_arr[j][i] == c)
				break ;
			i++;
		}
		if (basic_arr[j][i] == c)
			break ;
		j++;
		i = 0;
	}
	if (basic_arr[j] == NULL || basic_arr[j][i] == 0)
		error_handling(2, vars, "exec_arr: array population really failed\n");
	ret_arr = build_correct_arr(basic_arr, start, j, vars);
	return (ret_arr);
}

char	**build_correct_arr(char **arr, int start, int stop, t_pipex *vars)
{
	int		i;
	int		j;
	char	**ret_arr;

	i = 0;
	j = 0;
	while (arr[i] != NULL)
		i++;
	ret_arr = (char **)malloc((i - (stop - start) + 1) * sizeof(char *));
	while (j < start)
	{
		ret_arr[j] = ft_strdup(arr[j]);
		j++;
	}
	ret_arr[start] = set_temp_str(j, stop, arr, vars);
	j = start + 1;
	i = stop + 1;
	while (arr[i] != NULL)
	{
		ret_arr[j] = arr[i];
		j++;
		i++;
	}
	ret_arr[j] = NULL;
	return (ret_arr);
}

char	*set_temp_str(int j, int stop, char**arr, t_pipex *vars)
{
	char	*temp_str;

	temp_str = NULL;
	while (j <= stop)
	{
		temp_str = ft_strjoin(temp_str, arr[j]);
		if (j < stop)
			temp_str = ft_strjoin(temp_str, " ");
		j++;
	}
	if (temp_str[0] == '\'')
		temp_str = ft_strtrim(temp_str, "\'");
	else if (temp_str[0] == '\"')
		temp_str = ft_strtrim(temp_str, "\"");
	if (temp_str[0] == '\'')
		vars->error = 2;
	return (temp_str);
}
