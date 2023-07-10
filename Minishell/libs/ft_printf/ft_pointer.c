/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:22:53 by mtrautne          #+#    #+#             */
/*   Updated: 2022/07/25 18:23:53 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Used to handle the format %p (pointer) in the printf function. Reads the 
associated argument and prints its address to standard output, in hex and with 
a leading 0x. In Linux Systems, 0-pointer would be printed as (nil), though as 
macOS is the agreed upon testing setup, 0x0 is the correct output (see line 62).
Returns number of chars printed*/

#include "ft_printf.h"

int	ft_lenptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (1);
	while (ptr != 0)
	{
		len++;
		ptr /= 16;
	}
	return (len);
}

void	ft_printptr(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_printptr(ptr / 16);
		ft_printptr(ptr % 16);
	}
	else if (ptr < 10)
	{
		ptr = ptr + '0';
		write(1, &ptr, 1);
	}
	else if (ptr >= 10)
		ft_putchar_fd(ptr + 87, 1);
}

int	ft_pointer(unsigned long long ptr)
{
	if (ptr != 0)
	{
		write(1, "0x", 2);
		ft_printptr(ptr);
		return (ft_lenptr(ptr) + 2);
	}
	else
	{
		write(1, "0x0", 3);
		return (3);
	}
}
