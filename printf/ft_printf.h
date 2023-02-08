/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:20:44 by mtrautne          #+#    #+#             */
/*   Updated: 2022/07/25 18:57:51 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);

int	ft_char(int input);
int	ft_decint(int num);
int	ft_hex(char str, unsigned int num);
int	ft_perc(void);
int	ft_pointer(unsigned long long ptr);
int	ft_str(char *str);
int	ft_unsigned(int num);

#endif