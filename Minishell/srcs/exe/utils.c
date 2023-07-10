/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramusho <eramusho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:53:13 by eramusho          #+#    #+#             */
/*   Updated: 2023/07/05 22:21:54 by eramusho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin_mod(char *str_static, char *buffer)
{
	unsigned int	len;
	char			*str;

	if (!str_static)
	{
		str_static = (char *)malloc(1 * sizeof(char));
		str_static[0] = '\0';
	}
	if (!str_static || !buffer)
		return (0);
	len = ft_strlen(str_static) + ft_strlen(buffer);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	ft_strcpy(str, str_static);
	len = ft_strlen(str_static);
	ft_strcpy(&str[len], buffer);
	free(str_static);
	return (str);
}

int	fork_helper(int *pid)
{
	*pid = fork();
	if (failed_fork(*pid))
		return (1);
	return (0);
}

/*checks for logic in cmd tokens and skips their execution+ handles error 
messages*/
int	check_cmd_token_logic(t_cmd *cmnd)
{
	if (cmnd->cmd == NULL)
	{
		if (cmnd->cmd_arr[0])
			ft_exit_status("No such file or directory\n", 127, cmnd->cmd_arr[0]);
		return (1);
	}
	else if (cmnd->cmd_arr[0][0] == '/' || (cmnd->cmd_arr[0][0] == '.' && \
		cmnd->cmd_arr[0][1] == '/'))
	{
		if (access(cmnd->cmd_arr[0], R_OK))
		{
			ft_exit_status("Error: No such file or directory\n", 127, \
				cmnd->cmd_arr[0]);
			return (1);
		}
	}
	return (0);
}
