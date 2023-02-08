/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:30:56 by mtrautne          #+#    #+#             */
/*   Updated: 2023/01/15 20:43:43 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "./keymacros.h"
# include <math.h>

typedef struct s_fract {
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_data_addr;
	char			*fractal;
	int				fractal_int;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	double			width;
	double			height;
	int				offset;
	double			zoom_factor;
	int				zoom_step;

	double			x;
	double			y;
	double			r_orgn;
	double			i_orgn;
	double			r_range;
	double			i_range;
	double			r_c;
	double			i_c;
	double			r_z;
	double			i_z;
	double			x_mouse_pos;
	double			y_mouse_pos;
	double			it;
	double			max_it;
	unsigned int	div_color;
	int				prime_color;
	int				hud_color;
	unsigned int	conv_color;
	double			temp;
}	t_fract;

// fractol.c
t_fract		*ft_setup_mlx(char *width, char *fractal_set);
void		ft_calc_fractal(t_fract	*vars);
int			ft_end(t_fract *vars);

// usr_input_fcts.c
int			ft_input_check(int count, char **args);
int			ft_input_check_fractal(char *fractal);
int			ft_fractal_set(char *fractal_set);

// img_processing.c
void		ft_my_pixel_put(t_fract *vars);
void		ft_print_pixel(t_fract *vars, unsigned int color);
void		ft_overlay(t_fract *vars);
void		ft_overlay_text(t_fract *vars, char *max_it_str, \
					char *zoom_perc_str);

// colors.c
void		ft_change_prime_color(t_fract *vars, int keycode);
void		ft_color_options(t_fract *vars, double shift);
void		ft_color_fire(t_fract *vars, double shift);
void		ft_color_rainbow(t_fract *vars, double shift);

// std_vars.c
void		*ft_std_vars(t_fract *vars);
void		ft_fractal_specific_vars(t_fract *vars);
void		ft_set_std_vars_mandel(t_fract *std_vars);
void		ft_set_std_vars_julia(t_fract *std_vars);
void		ft_set_std_vars_burning_ships(t_fract *std_vars);

// input_processing_keyboard.c
int			ft_keyboard_input(int keycode, t_fract *vars);
void		ft_pan_view(t_fract *vars, int keycode);
void		ft_reset_view(t_fract *vars);
void		ft_change_max_it(t_fract *vars, int keycode);

// input_processing_mouse.c
int			ft_mouse_input(int button, int x, int y, t_fract *vars);
void		ft_zoom(int button, int x, int y, t_fract *vars);
void		ft_julia_change_c(int x, int y, t_fract *vars);

// mandelbrot.c
void		ft_mandelbrot(t_fract *vars);
void		ft_mandel_calc_c(t_fract *vars);
void		ft_mandel_calc_z(t_fract *vars);

// julia.c
void		ft_julia(t_fract *vars);
void		ft_julia_calc_start_values(t_fract *vars);
void		ft_julia_calc_z(t_fract *vars);

// burning_ships.c
void		ft_burning_ships(t_fract *vars);
void		ft_burning_ships_calc_c(t_fract *vars);
void		ft_burning_ships_calc_z(t_fract *vars);

#endif
