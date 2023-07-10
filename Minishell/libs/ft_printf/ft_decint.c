/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:24:11 by mtrautne          #+#    #+#             */
/*   Updated: 2022/07/25 18:05:04 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Used to handle the formats %i (integer) and %d (decimal) in the printf 
function. Reads the associated arguments and prints it to standard output,
returns number of chars printed*/

#include "ft_printf.h"

int	ft_leninput(int input)
{
	int	i;
	int	j;

	i = 1;
	if (input == -2147483648)
		return (11);
	else if (input < 0)
		j = -input;
	else
		j = input;
	while (j > 9)
	{
		j /= 10;
		i++;
	}
	if (input < 10 && input >= 0)
		return (1);
	if (input < 0)
		return (i + 1);
	return (i);
}

int	ft_decint(int input)
{
	ft_putnbr_fd(input, 1);
	return (ft_leninput(input));
}
