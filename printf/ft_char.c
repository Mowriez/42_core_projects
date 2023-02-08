/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:44:11 by mtrautne          #+#    #+#             */
/*   Updated: 2022/07/25 18:04:23 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Used to handle the format %c (character) in the printf function. Reads 
the associated argument and prints it to standard output, returns number of 
chars printed (always 1).*/

#include "ft_printf.h"

int	ft_char(int input)
{
	write(1, &input, 1);
	return (1);
}
