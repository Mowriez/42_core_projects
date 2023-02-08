/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:51:15 by mtrautne          #+#    #+#             */
/*   Updated: 2022/07/25 18:26:50 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Used to handle the format %s (string) in the printf function. Reads the 
associated argument and prints it to standard output. Returns number of chars 
printed.*/

#include "ft_printf.h"

int	ft_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_str_print(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
}

int	ft_str(char *str)
{
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_str_print(str);
	return (ft_str_len(str));
}
