/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:31:44 by mtrautne          #+#    #+#             */
/*   Updated: 2023/06/17 14:40:11 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*splits the env argument provided to the function at the = and returns an array
with the individual parts*/
char	**ft_split_env(char *str)
{
	size_t	i;
	size_t	len;
	char	**ret;

	i = 0;
	if (!str)
		return (NULL);
	ret = (char **)malloc(2 * sizeof(char *));
	if (!ret)
		return (NULL);
	len = len_substr_env(str, i, '=');
	ret[0] = ft_substr(str, i, len);
	i = i + len + 1;
	len = len_substr_env(str, i, '\0');
	ret[1] = ft_substr(str, i, len);
	return (ret);
}
/*returns the length of a substring from start to end_char*/

int	len_substr_env(char *str, int start, char end_char)
{
	int	i;

	i = 0;
	while (str[start + i] != end_char)
		i++;
	return (i);
}
