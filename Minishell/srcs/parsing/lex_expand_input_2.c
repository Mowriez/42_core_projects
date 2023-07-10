/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_expand_input_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:15:23 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/06 10:25:47 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*builds the new expanded string from the two string parts before and
after the variable and the value for the variable*/
char	*get_new_ret(char *exp_str, char *env_value, int *i)
{
	char	*str_start;
	char	*str_end;
	char	*str_ret;

	str_start = ret_str_start(exp_str, *i);
	str_end = ret_str_end(exp_str, *i);
	str_ret = ft_strjoin(str_start, env_value);
	str_ret = ft_strjoin(str_ret, str_end);
	free(str_end);
	free(exp_str);
	*i = *i + ft_strlen(env_value) - 1;
	return (str_ret);
}

/*returns the part of the string infront of the variable $*/
char	*ret_str_start(char *exp_str, int i)
{
	int		j;
	char	*str_start;

	j = 0;
	str_start = malloc((i + 1) * sizeof(char));
	while (j < i)
	{
		str_start[j] = exp_str[j];
		j++;
	}
	str_start[j] = '\0';
	return (str_start);
}

/*returns the end of the string after the variable*/
char	*ret_str_end(char *exp_str, int i)
{
	int		j;
	int		k;
	int		len;
	char	*str_end;

	j = i + 1;
	len = 0;
	while (exp_str[j] != ' ' && exp_str[j] != '\0' && exp_str[j] != '\'' \
		&& exp_str[j] != '"' && exp_str[j] != '$' && exp_str[j] != '>' \
		&& exp_str[j] != '<' && exp_str[j] != '|')
		j++;
	while (exp_str[j + len] != '\0')
		len++;
	str_end = malloc((len + 1) * sizeof(char));
	k = 0;
	while (exp_str[j] != '\0')
	{
		str_end[k] = exp_str[j];
		k++;
		j++;
	}
	str_end[k] = '\0';
	return (str_end);
}

/*returns the variable itself without the $-sign*/
char	*ret_env_key(char *str, int i)
{
	int		j;
	int		k;
	int		end;
	char	*ret;

	j = 0;
	k = 0;
	while (str[i + j] != ' ' && str[i + j] != '\0' && str[i + j] != '\'' \
		&& str[i + j] != '"' && str[i + j] != '$' && str[i + j] != '>' \
		&& str[i + j] != '<' && str[i + j] != '|')
		j++;
	end = i + j;
	ret = malloc((j + 1) * sizeof(char));
	while (i < end)
	{
		ret[k] = str[i];
		i++;
		k++;
	}
	ret[k] = '\0';
	return (ret);
}

/*returns the variables key and value-string if found in the environment list*/
char	*find_env_value(t_ms *ms_struct, char *key)
{
	t_env	*env_temp;
	int		len;

	env_temp = ms_struct->env_ll;
	len = ft_strlen(key);
	while (env_temp != NULL)
	{
		if (ft_strncmp(key, env_temp->string, len) == 0 && \
			ft_strlen(key) == ft_strlen(env_temp->key))
			return (env_temp->string);
		else
			env_temp = env_temp->next;
	}
	return (NULL);
}
