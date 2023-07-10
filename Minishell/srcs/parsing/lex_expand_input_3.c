/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_expand_input_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 02:57:45 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/06 11:04:46 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*returns the variables value from the full env string*/
char	*extract_value(char *env_str)
{
	int		i;
	int		j;
	int		len_val;
	char	*value;

	i = 0;
	j = 0;
	len_val = 0;
	if (env_str == NULL)
		return (NULL);
	while (env_str[i] != '=' && env_str[i] != '\0')
		i++;
	i++;
	len_val = ft_strlen(env_str) - i;
	value = malloc((len_val + 1) * sizeof(char));
	while (env_str[i] != '\0')
	{
		value[j] = env_str[i];
		j++;
		i++;
	}
	value[j] = '\0';
	return (value);
}

/*builds the new expanded string if $VAR is not found */
char	*cut_var(char *str, int i)
{
	int		j;
	int		k;
	int		l;
	char	*str_ret;

	j = 1;
	k = 0;
	while (str[i + j] != ' ' && str[i + j] != '\0' && str[i + j] != '\'' \
		&& str[i + j] != '"' && str[i + j] != '$' && str[i + j] != '>' \
		&& str[i + j] != '<' && str[i + j] != '|')
		j++;
	str_ret = malloc((ft_strlen(str) - j + 1));
	while (k < i)
	{
		str_ret[k] = str[k];
		k++;
	}
	l = k;
	k += j;
	while (str[k])
		str_ret[l++] = str[k++];
	str_ret[l] = '\0';
	free(str);
	return (str_ret);
}
