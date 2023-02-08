/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_processing_mouse.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:32:21 by mtrautne          #+#    #+#             */
/*   Updated: 2023/01/14 18:26:39 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	ft_mouse_input(int button, int x, int y, t_fract *vars)
{
	if (y <= 0)
		return (0);
	if (button == MOUSE_WHEEL_UP || button == MOUSE_WHEEL_DOWN)
	{
		ft_zoom(button, x, y, vars);
		ft_calc_fractal(vars);
		return (0);
	}
	if (button == MOUSE_LEFT)
	{
		ft_julia_change_c(x, y, vars);
		ft_calc_fractal(vars);
		return (0);
	}
	return (0);
}

void	ft_zoom(int button, int x, int y, t_fract *vars)
{
	if (button == MOUSE_WHEEL_UP)
	{
		vars->r_range = (1 / vars->zoom_factor) * vars->r_range;
		vars->i_range = (1 / vars->zoom_factor) * vars->i_range;
		vars->r_orgn = (((double)x / vars->width) * vars->r_range) \
					- (vars->r_range / 2) + (vars->r_orgn);
		vars->i_orgn = ((((-1) * ((double)y)) / vars->height) * vars->i_range) \
					+ (vars->i_range / 2) + (vars->i_orgn);
		vars->zoom_step++;
	}
	if (button == MOUSE_WHEEL_DOWN)
	{
		vars->r_orgn = (((double)x / vars->width) * vars->r_range) - \
					(vars->r_range / 2) + (vars->r_orgn);
		vars->i_orgn = ((((-1) * ((double)y)) / vars->height) * vars->i_range) \
				+ (vars->i_range / 2) + (vars->i_orgn);
		vars->r_range = vars->zoom_factor * vars->r_range;
		vars->i_range = vars->zoom_factor * vars->i_range;
		vars->zoom_step--;
	}
}

void	ft_julia_change_c(int x, int y, t_fract *vars)
{
	vars->x_mouse_pos = (double)x;
	vars->y_mouse_pos = (double)y;
	vars->r_c = ((vars->x_mouse_pos / vars->width) * vars->r_range) - \
		(vars->r_range / 2) + vars->r_orgn;
	vars->i_c = ((-1) * (vars->y_mouse_pos / vars->height) * vars->i_range) \
			+ (vars->i_range / 2) + vars->i_orgn;
}
