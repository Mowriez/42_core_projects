/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:50:43 by mtrautne          #+#    #+#             */
/*   Updated: 2022/07/25 18:20:22 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Used to handle the %% in the printf function. Prints out a % to standard 
output, returns number of chars printed (always 1).*/

#include "ft_printf.h"

int	ft_perc(void)
{
	write(1, "%", 1);
	return (1);
}
