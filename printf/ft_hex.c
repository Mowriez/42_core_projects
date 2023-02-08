/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:23:43 by mtrautne          #+#    #+#             */
/*   Updated: 2022/07/25 18:19:15 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Used to handle the formats %x (int to lowercase hex) and %X (int to 
uppercase hex) in the printf function. Reads the associated arguments and 
prints them to standard output, converted to hex. Returns number of chars 
printed*/

#include "ft_printf.h"

int	ft_lenhex(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

void	ft_printhex(char str, unsigned int num)
{
	if (num >= 16)
	{
		ft_printhex(str, num / 16);
		ft_printhex(str, num % 16);
	}
	else if (num < 10)
	{
		num = num + '0';
		write(1, &num, 1);
	}
	else if (num >= 10)
	{
		if (str == 'x')
			ft_putchar_fd(num + 87, 1);
		if (str == 'X')
			ft_putchar_fd(num + 55, 1);
	}
}

int	ft_hex(char str, unsigned int num)
{
	ft_printhex(str, num);
	return (ft_lenhex(num));
}
