/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:12:24 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/05 14:59:07 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	input_redir(int *input_fd, char *infile)
{
	if (*input_fd != 0)
		close(*input_fd);
	*input_fd = open(infile, O_RDONLY);
	if (*input_fd == -1)
	{
		ft_strerror_status(g_exit, "open");
		return (-1);
	}
	return (0);
}

int	output_redir(int *output_fd, char *outfile)
{
	if (*output_fd != 1)
		close(*output_fd);
	*output_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (*output_fd == -1)
	{
		ft_strerror_status(g_exit, "open");
		return (-1);
	}
	return (0);
}

int	append_redir(int *output_fd, char *outfile)
{
	if (*output_fd != 1)
		close(*output_fd);
	*output_fd = open(outfile, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (*output_fd == -1)
	{
		ft_strerror_status(g_exit, "open");
		return (-1);
	}
	return (0);
}
