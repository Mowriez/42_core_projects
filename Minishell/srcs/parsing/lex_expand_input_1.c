/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_expand_input_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:13:29 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/06 10:43:01 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*checks for variables in the input string and returns the input string expanded
with the actual value of that variable. nice to have: $$->gives pid*/
char	*expand_input(t_ms *ms_struct)
{
	int		i;
	int		sngl_qt;
	char	*exp_str;

	i = 0;
	sngl_qt = -1;
	exp_str = crop_whitespaces(ms_struct->rl_input);
	while (exp_str && exp_str[i] != '\0')
	{
		if (exp_str[i] == '\'')
			sngl_qt = sngl_qt * -1;
		if (sngl_qt == 1)
		{
			i++;
			continue ;
		}
		else if (exp_str[i] == '$' && sngl_qt != 1)
		{
			exp_str = resize_expanded_str(ms_struct, &i, exp_str);
		}
		i++;
	}
	return (exp_str);
}

/*inserts the value for variable or cuts the variable if it is not valid*/
char	*resize_expanded_str(t_ms *ms_struct, int *i, char *exp_str)
{
	char	*env_value;
	char	*ret;

	if (((*i) != 0 && exp_str[*i - 1] != '$') && exp_str[*i + 1] != '$' && \
			(exp_str[*i + 1] == ' ' || exp_str[*i + 1] == '\0'))
	{
		(*i)++;
		return (exp_str);
	}
	env_value = ret_env_value(ms_struct, exp_str, *i);
	if (env_value == NULL)
	{
		ret = cut_var(exp_str, *i);
		*i = *i - 1;
	}
	else
	{
		ret = get_new_ret(exp_str, env_value, i);
		free(env_value);
	}
	return (ret);
}

/*crops whitespaces from beginning and end of input string*/
char	*crop_whitespaces(char *rl_input)
{
	int		i;
	int		j;
	int		k;
	char	*cropped_str;

	i = 0;
	j = 0;
	k = 0;
	while (rl_input[i] == ' ')
		i++;
	while (rl_input[j + 1] != '\0')
		j++;
	while (rl_input[j] == ' ')
		j--;
	cropped_str = malloc((j - i + 2) * sizeof(char));
	while (i <= j)
	{
		cropped_str[k] = rl_input[i];
		k++;
		i++;
	}
	cropped_str[k] = '\0';
	return (cropped_str);
}

/*returns value for variable ($USER -> eramusho/mtrautne))*/
char	*ret_env_value(t_ms *ms_struct, char *str, int i)
{
	char	*key;
	char	*env_str;
	char	*value;

	key = NULL;
	if (str[i + 1] == '?')
		value = ret_exit_status();
	else
	{
		key = ret_env_key(str, i + 1);
		env_str = find_env_value(ms_struct, key);
		value = extract_value(env_str);
	}
	if (key)
		free(key);
	return (value);
}

/*returns current exit status, if $? is called*/
char	*ret_exit_status(void)
{
	char	*ret;

	ret = ft_itoa(g_exit);
	if (!ret)
		return ("");
	return (ret);
}
