/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramusho <eramusho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:50:06 by eramusho          #+#    #+#             */
/*   Updated: 2023/07/05 23:19:39 by eramusho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	signal_interactive(void)
{
	signal(SIGINT, &interactive_sigint);
	signal(SIGQUIT, SIG_IGN);
}

void	signal_not_interactive(void)
{
	signal(SIGINT, &non_interactive_handler);
	signal(SIGQUIT, &non_interactive_handler);
}

//write(1, "\n13", 3); entfern after g_exit = 128...
void	non_interactive_handler(int sign)
{
	if (sign == SIGINT)
	{
		g_exit = 128 + sign;
		ft_putstr_fd("\n", 1);
		rl_replace_line("", 0);
	}
	else if (sign == SIGQUIT)
	{
		g_exit = 128 + sign;
		ft_putstr_fd("Quit: ", 1);
		ft_putstr_fd(ft_itoa(sign), 1);
		ft_putstr_fd("\n", 1);
	}
}

//128 + sign; entfernt after g_exit = 1
void	interactive_sigint(int sign)
{
	if (sign == SIGINT)
	{
		g_exit = 1;
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	signal_child_active(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
