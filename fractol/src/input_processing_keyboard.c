/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_processing_keyboard.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:05:20 by mtrautne          #+#    #+#             */
/*   Updated: 2023/01/14 18:39:08 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	ft_keyboard_input(int keycode, t_fract *vars)
{	
	if (keycode >= 123 && keycode <= 126)
		ft_pan_view(vars, keycode);
	if (keycode >= 18 && keycode <= 23)
		ft_change_prime_color(vars, keycode);
	if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		ft_change_max_it(vars, keycode);
	if (keycode == KEY_R)
		ft_reset_view(vars);
	if (keycode == KEY_ESCAPE)
		ft_end(vars);
	return (0);
}

void	ft_pan_view(t_fract *vars, int keycode)
{
	if (keycode == KEY_LEFT)
		vars->r_orgn = vars->r_orgn - (0.2 * vars->r_range);
	if (keycode == KEY_RIGHT)
		vars->r_orgn = vars->r_orgn + (0.2 * vars->r_range);
	if (keycode == KEY_DOWN)
		vars->i_orgn = vars->i_orgn - (0.2 * vars->i_range);
	if (keycode == KEY_UP)
		vars->i_orgn = vars->i_orgn + (0.2 * vars->i_range);
	ft_calc_fractal(vars);
}

void	ft_reset_view(t_fract *vars)
{
	double	prime_color;

	prime_color = vars->prime_color;
	ft_fractal_specific_vars(vars);
	vars->prime_color = prime_color;
	ft_calc_fractal(vars);
}

void	ft_change_max_it(t_fract *vars, int keycode)
{
	if (keycode == KEY_PLUS)
	{
		if (vars->max_it < 10)
			vars->max_it += 1;
		else
			vars->max_it += 10;
	}
	if (keycode == KEY_MINUS)
	{
		if (vars->max_it <= 10 && vars->max_it > 0)
			vars->max_it -= 1;
		else if (vars->max_it == 0)
			write(1, "Max_it < 0 produces undef. behaviour and will therefore"\
				"not be shown.\n", 70);
		else
			vars->max_it -= 10;
	}
	ft_calc_fractal(vars);
}
