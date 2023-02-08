/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:58:11 by mtrautne          #+#    #+#             */
/*   Updated: 2023/01/26 14:13:25 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	main(int argc, char *argv[])
{
	t_fract	*vars;

	if (ft_input_check(argc, argv) == 0)
		return (0);
	vars = ft_setup_mlx(argv[1], argv[2]);
	if (vars == NULL)
		return (0);
	ft_calc_fractal(vars);
	mlx_key_hook(vars->win_ptr, ft_keyboard_input, &*vars);
	mlx_hook(vars->win_ptr, 17, 0L, ft_end, vars);
	mlx_hook(vars->win_ptr, 4, 0L, ft_mouse_input, vars);
	mlx_loop(vars->mlx_ptr);
}

t_fract	*ft_setup_mlx(char *width, char *fractal_set)
{
	t_fract	*vars;

	vars = (t_fract *)malloc(sizeof(t_fract));
	if !(vars)
		return(NULL);
	vars->mlx_ptr = mlx_init();
	vars->width = (double)ft_atoi(width);
	vars->height = (double)round(vars->width / 1.77);
	vars->fractal_int = ft_fractal_set(fractal_set);
	vars->fractal = fractal_set;
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, vars->width, vars->height, \
									vars->fractal);
	ft_std_vars(vars);
	return (vars);
}

void	ft_calc_fractal(t_fract	*vars)
{
	if (vars->fractal_int == MANDELBROT)
		ft_mandelbrot(vars);
	if (vars->fractal_int == JULIA)
		ft_julia(vars);
	if (vars->fractal_int == BURNING_SHIPS)
		ft_burning_ships(vars);
	ft_overlay(vars);
}

int	ft_end(t_fract *vars)
{
	mlx_destroy_image(vars->mlx_ptr, vars->img_ptr);
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	free(vars);
	exit(1);
}
