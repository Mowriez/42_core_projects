/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:38:34 by mtrautne          #+#    #+#             */
/*   Updated: 2023/01/14 18:47:11 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	ft_mandelbrot(t_fract *vars)
{
	vars->x = 0;
	vars->y = 0;
	vars->it = 0;
	while (vars->x < vars->width)
	{
		while (vars->y < vars->height)
		{
			ft_mandel_calc_c(vars);
			while (vars->it < vars->max_it && (sqrt(pow(vars->r_z, 2) + \
					pow(vars->i_z, 2)) <= 2))
				ft_mandel_calc_z(vars);
			if (vars->it < vars->max_it)
				ft_my_pixel_put(vars);
			else
				ft_print_pixel(vars, vars->conv_color);
			vars->y++;
		}
		vars->y = 0;
		vars->x++;
	}
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img_ptr, 0, 0);
}

void	ft_mandel_calc_c(t_fract *vars)
{
	vars->r_c = ((vars->x / vars->width) * vars->r_range) - \
		(vars->r_range / 2) + vars->r_orgn;
	vars->i_c = ((-1) * (vars->y / vars->height) * vars->i_range) \
			+ (vars->i_range / 2) + vars->i_orgn;
	vars->r_z = 0;
	vars->i_z = 0;
	vars->temp = 0;
	vars->it = 0;
}

void	ft_mandel_calc_z(t_fract *vars)
{
	vars->temp = pow(vars->r_z, 2) - pow(vars->i_z, 2) + vars->r_c;
	vars->i_z = (2 * vars->r_z * vars->i_z) + vars->i_c;
	vars->r_z = vars->temp;
	vars->it++;
}
