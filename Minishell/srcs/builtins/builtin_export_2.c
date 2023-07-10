/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buitlin_export_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramusho <eramusho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 22:17:55 by eramusho          #+#    #+#             */
/*   Updated: 2023/07/05 22:18:19 by eramusho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_no_args(t_ms *data, char **args)
{
	if (!args[1])
	{
		print_export_no_args(data);
		return (1);
	}
	return (0);
}
