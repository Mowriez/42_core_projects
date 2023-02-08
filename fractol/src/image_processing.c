/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:33:26 by mtrautne          #+#    #+#             */
/*   Updated: 2023/01/14 19:37:48 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	ft_my_pixel_put(t_fract *vars)
{
	double	shift;

	shift = (double)round((vars->it / vars->max_it) * 64);
	ft_color_options(vars, shift);
	ft_print_pixel(vars, vars->div_color);
}

void	ft_print_pixel(t_fract *vars, unsigned int color)
{
	char	*pixel;

	pixel = vars->img_data_addr + ((int)vars->x * vars->bits_per_pixel / 8) \
			+ ((int)vars->y * vars->line_length);
	*(unsigned int *)pixel = color;
}

void	ft_overlay(t_fract *vars)
{
	char	*max_it_str;
	char	*zoom_perc_str;

	max_it_str = ft_itoa(vars->max_it);
	zoom_perc_str = ft_itoa(vars->zoom_step * vars->zoom_factor);
	ft_overlay_text(vars, max_it_str, zoom_perc_str);
	free (max_it_str);
	free (zoom_perc_str);
}

void	ft_overlay_text(t_fract *vars, char *max_it_str, char *zoom_perc_str)
{
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, vars->width - 120, 15, \
			vars->hud_color, "Iterations:");
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, vars->width - 120, 27, \
				vars->hud_color, "Zoom Factor:");
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, vars->width - 38, 15, \
				vars->hud_color, max_it_str);
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, vars->width - 34, 27, \
				vars->hud_color, zoom_perc_str);
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 5, 11, \
				vars->hud_color, "How to:");
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 5, 27, \
				vars->hud_color, "Arrow keys: pan");
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 5, 39, \
				vars->hud_color, "Mouse wheel: zoom");
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 5, 51, \
				vars->hud_color, "+/-: change resolution");
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 5, 63, \
				vars->hud_color, "1/2/3/4/5/6: change color");
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 5, 75, \
				vars->hud_color, "r: reset");
}
