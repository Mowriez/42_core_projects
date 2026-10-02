/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymacros.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:44:14 by mtrautne          #+#    #+#             */
/*   Updated: 2023/01/14 17:24:20 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYMACROS_H
# define KEYMACROS_H

// TODO: Still no capture for key for whatever reason.
# ifdef __linux__
#  define OS_Linux 1
#  define MOUSE_WHEEL_UP 4
#  define MOUSE_WHEEL_DOWN 5
#  define MOUSE_LEFT 1
#  define MOUSE_RIGHT 3
#  define MOUSE_SCROLL_RIGHT 6
#  define MOUSE_SCROLL_LEFT 7
#  define KEY_ESCAPE 65307
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_1 49
#  define KEY_2 50
#  define KEY_3 51
#  define KEY_4 52
#  define KEY_5 53
#  define KEY_6 54
#  define KEY_R 114
#  define KEY_PLUS 43
#  define KEY_MINUS 45

# elif defined(__APPLE__)
#  define OS_Linux 0
#  define MOUSE_WHEEL_UP 4
#  define MOUSE_WHEEL_DOWN 5
#  define MOUSE_LEFT 1
#  define MOUSE_RIGHT 2
#  define MOUSE_SCROLL_RIGHT 6
#  define MOUSE_SCROLL_LEFT 7
#  define KEY_ESCAPE 53
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_1 18
#  define KEY_2 19
#  define KEY_3 20
#  define KEY_4 21
#  define KEY_5 22
#  define KEY_6 23
#  define KEY_R 15
#  define KEY_PLUS 30
#  define KEY_MINUS 44

# else
#  error "Unsupported operating system"
# endif

// ascii escape characters for text colors
# define RED "\033[1;31m"
# define GRE "\033[1;32m"
# define YEL "\033[1;33m"
# define BLU "\033[1;34m"
# define PUR "\033[1;35m"
# define CYA "\033[1;36m"
# define WHI "\033[1;37m"
# define RES "\033[0m"

# define MANDELBROT 990
# define JULIA 991
# define BURNING_SHIPS 992
#endif