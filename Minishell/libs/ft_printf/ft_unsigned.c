/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:36:20 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/05 12:16:53 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Used to handle the format %u (unsigned) in the printf function. Reads the 
associated argument and prints it to standard output, converted to unsigned in.
Its basically the putnumber function but if the argument is negative, it will
be read as UINT_MAX + num + 1. (eg -1 is UINT_MAX = 4294967295). 
Returns number of chars printed.*/

#include "ft_printf.h"

int	ft_len_unsigned(unsigned int num)
{
	int	i;

	i = 1;
	while (num > 10)
	{
		i++;
		num = num / 10;
	}
	return (i);
}

void	ft_print_unsigned(unsigned int num)
{
	int	i;

	i = 0;
	if (num < 10)
	{
		i = num + '0';
		write(1, &i, 1);
	}
	else if (num > 9)
	{
		ft_print_unsigned(num / 10);
		i = (num % 10) + '0';
		write(1, &i, 1);
	}
}

int	ft_unsigned(int num)
{
	unsigned int	conv_num;

	conv_num = 0;
	if (num >= 0)
		return (ft_decint(num));
	if (num < 0)
	{
		conv_num = 4294967295 + num + 1;
		ft_print_unsigned(conv_num);
		return (ft_len_unsigned(conv_num));
	}
	return (0);
}
