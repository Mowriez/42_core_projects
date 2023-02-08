/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ships.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:37:57 by mtrautne          #+#    #+#             */
/*   Updated: 2023/01/14 18:47:17 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	ft_burning_ships(t_fract *vars)
{
	vars->x = 0;
	vars->y = 0;
	vars->it = 0;
	while (vars->x < vars->width)
	{
		while (vars->y < vars->height)
		{
			ft_burning_ships_calc_c(vars);
			while (vars->it < vars->max_it && (pow(vars->r_z, 2) + \
					pow(vars->i_z, 2) < 4))
				ft_burning_ships_calc_z(vars);
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

void	ft_burning_ships_calc_c(t_fract *vars)
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

void	ft_burning_ships_calc_z(t_fract *vars)
{
	vars->temp = pow(vars->r_z, 2) - pow(vars->i_z, 2) + vars->r_c;
	if ((2 * vars->r_z * vars->i_z) < 0)
		vars->i_z = (2 * vars->r_z * vars->i_z) + vars->i_c;
	else
		vars->i_z = (-2 * vars->r_z * vars->i_z) + vars->i_c;
	vars->r_z = vars->temp;
	vars->it++;
}
