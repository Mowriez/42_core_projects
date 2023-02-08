/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:33:04 by mtrautne          #+#    #+#             */
/*   Updated: 2023/01/15 20:47:18 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	ft_input_check(int count, char **args)
{
	int	i;

	i = 0;
	if (count != 3)
	{
		write(1, "\x1b[31mInvalid number of arguments - needs 2\n1. 800 <= Img "\
		"width <=1920 and\n2. Name of fractol = (Mandelbrot || Julia "\
		"|| BS)\nImage height is calculated automatically.\n\x1b[0m", 170);
		return (i);
	}
	if (ft_atoi(args[1]) < 800 || ft_atoi(args[1]) > 1920)
	{
		write(1, "\x1b[33mchoose parameter 1: 800 <= width <= 1920\n\x1b[0m", 51);
		return (i);
	}
	i = ft_input_check_fractal(args[2]);
	return (i);
}

int	ft_input_check_fractal(char *fractal)
{
	int	j;

	j = ft_strncmp("Mandelbrot", fractal, 11) * ft_strncmp("Julia", fractal, 5) \
		* ft_strncmp("BS", fractal, 2);
	if (j != 0)
	{
		write(1, "\x1b[31mNo valid fractal set requested. Choose:\nMandelbrot or\n"\
				"Julia or\nBS (Burning Ships)\n\x1b[0m", 92);
		return (0);
	}
	return (1);
}

int	ft_fractal_set(char *fractal_set)
{
	if (ft_strncmp("Mandelbrot", fractal_set, 10) == 0)
		return (MANDELBROT);
	else if (ft_strncmp("Julia", fractal_set, 5) == 0)
		return (JULIA);
	else if (ft_strncmp("BS", fractal_set, 2) == 0)
		return (BURNING_SHIPS);
	return (MANDELBROT);
}
