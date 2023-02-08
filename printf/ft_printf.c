/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:30:28 by mtrautne          #+#    #+#             */
/*   Updated: 2022/07/25 18:25:31 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* va_end(args) tells compiler that acces to args is no longer needed. This 
command is not neccessary for gcc, but for portability to other compilers.
va_arg accesses the next argument in va list. careful with calling va_arg, as 
repeated calls will move it to the next arg. so its best practice to call them 
in the "highest possible" function, not in the subfunctions.
... is called elipses.*/

#include "ft_printf.h"

int	ft_charselect(char str, va_list args)
{
	if (str == '%')
		return (ft_perc());
	if (str == 'c')
		return (ft_char(va_arg(args, int)));
	if (str == 'd' || str == 'i')
		return (ft_decint(va_arg(args, int)));
	if (str == 'x' || str == 'X')
		return (ft_hex(str, va_arg(args, unsigned int)));
	if (str == 's')
		return (ft_str(va_arg(args, char *)));
	if (str == 'u')
		return (ft_unsigned(va_arg(args, int)));
	if (str == 'p')
		return (ft_pointer(va_arg(args, unsigned long long)));
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		chars_printed;

	i = 0;
	chars_printed = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			chars_printed += ft_charselect(format[i + 1], args);
			i += 2;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			i++;
			chars_printed++;
		}
	}
	return (chars_printed);
}
