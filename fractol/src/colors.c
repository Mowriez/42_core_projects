/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:20:51 by mtrautne          #+#    #+#             */
/*   Updated: 2023/01/14 19:40:09 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	ft_change_prime_color(t_fract *vars, int keycode)
{
	vars->prime_color = keycode;
	ft_calc_fractal(vars);
}

void	ft_color_options(t_fract *vars, double shift)
{
	if (vars->prime_color == 18)
	{
		vars->div_color = 0x000F0F0F + ((shift / 2) * 0x00080808);
		vars->conv_color = 0x00000000;
	}
	else if (vars->prime_color == 19)
	{
		vars->div_color = 0x000F0000 + ((shift / 2) * 0x00080000);
		vars->conv_color = 0x00110000;
	}
	else if (vars->prime_color == 20)
	{
		vars->div_color = 0x00000F00 + ((shift / 2) * 0x00000800);
		vars->conv_color = 0x00001100;
	}
	else if (vars->prime_color == 21)
	{
		vars->div_color = 0x0000000F + ((shift / 2) * 0x00000008);
		vars->conv_color = 0x00000011;
	}
	else if (vars->prime_color == 22)
		ft_color_rainbow(vars, shift);
	else if (vars->prime_color == 23)
		ft_color_fire(vars, shift);
	vars->hud_color = (vars->conv_color / 2) + 0x00666666;
}

void	ft_color_fire(t_fract *vars, double shift)
{
	if (shift < 32)
		vars->div_color = shift * 0x00070300;
	if (shift >= 32)
		vars->div_color = 0x00FF7F00 + (shift * 0x00000200);
	vars->conv_color = 0x005F0000;
}

void	ft_color_rainbow(t_fract *vars, double shift)
{
	if (shift <= 10)
		vars->div_color = 0x00FF0000 + (shift * 0x00001900);
	else if (shift <= 20)
		vars->div_color = 0x00FFFF00 - ((shift - 10) * 0x00190000);
	else if (shift <= 30)
		vars->div_color = 0x0000FF00 + ((shift - 20) * 0x00000019);
	else if (shift <= 40)
		vars->div_color = 0x0000FFFF - ((shift - 30) * 0x00001900);
	else if (shift <= 50)
		vars->div_color = 0x000000FF + ((shift - 40) * 0x00190000);
	else if (shift > 50)
		vars->div_color = 0x00FF00FF - ((shift - 50) * 0x00000009);
	vars->conv_color = 0x00000000;
}
