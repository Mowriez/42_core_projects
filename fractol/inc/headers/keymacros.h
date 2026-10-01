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
#  define MOUSE_WHEEL_UP 4
#  define MOUSE_WHEEL_DOWN 5
#  define MOUSE_LEFT 1
#  define MOUSE_RIGHT 3
#  define MOUSE_SCROLL_RIGHT 6
#  define MOUSE_SCROLL_LEFT 7
#  define KEY_ESCAPE 9
#  define KEY_UP 111
#  define KEY_DOWN 116
#  define KEY_LEFT 113
#  define KEY_RIGHT 114
#  define KEY_1 10
#  define KEY_2 11
#  define KEY_3 12
#  define KEY_4 13
#  define KEY_5 14
#  define KEY_R 27
#  define KEY_PLUS 35
#  define KEY_MINUS 61

# elif defined(__APPLE__)
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