/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_vars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:36:46 by mtrautne          #+#    #+#             */
/*   Updated: 2023/01/14 18:24:14 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	*ft_std_vars(t_fract *vars)
{
	vars->img_ptr = mlx_new_image(vars->mlx_ptr, vars->width, \
									vars->height);
	vars->img_data_addr = mlx_get_data_addr(vars->img_ptr, \
		&vars->bits_per_pixel, &vars->line_length, &vars->endian);
	ft_fractal_specific_vars(vars);
	return (vars);
}

void	ft_fractal_specific_vars(t_fract *vars)
{
	if (ft_strncmp("Mandelbrot", vars->fractal, 10) == 0)
		ft_set_std_vars_mandel(vars);
	else if (ft_strncmp("Julia", vars->fractal, 5) == 0)
		ft_set_std_vars_julia(vars);
	else if (ft_strncmp("BS", vars->fractal, 5) == 0)
		ft_set_std_vars_burning_ships(vars);
}

void	ft_set_std_vars_mandel(t_fract *std_vars)
{
	std_vars->x = 0;
	std_vars->y = 0;
	std_vars->max_it = 40;
	std_vars->r_orgn = -0.5;
	std_vars->i_orgn = 0;
	std_vars->r_range = 4;
	std_vars->i_range = 2.5;
	std_vars->div_color = 0;
	std_vars->conv_color = 0;
	std_vars->zoom_factor = 2;
	std_vars->zoom_step = 1;
	std_vars->prime_color = 18;
}

void	ft_set_std_vars_julia(t_fract *std_vars)
{
	std_vars->x = 0;
	std_vars->y = 0;
	std_vars->r_c = 0;
	std_vars->i_c = 0;
	std_vars->max_it = 40;
	std_vars->r_orgn = 0;
	std_vars->i_orgn = 0;
	std_vars->r_range = 4;
	std_vars->i_range = 2.5;
	std_vars->div_color = 0;
	std_vars->conv_color = 0;
	std_vars->zoom_factor = 2;
	std_vars->zoom_step = 1;
	std_vars->prime_color = 18;
}

void	ft_set_std_vars_burning_ships(t_fract *std_vars)
{
	std_vars->x = 0;
	std_vars->y = 0;
	std_vars->max_it = 40;
	std_vars->r_orgn = -0.5;
	std_vars->i_orgn = 0.5;
	std_vars->r_range = 4;
	std_vars->i_range = 2.5;
	std_vars->div_color = 0;
	std_vars->conv_color = 0;
	std_vars->zoom_factor = 2;
	std_vars->zoom_step = 1;
	std_vars->prime_color = 18;
}
