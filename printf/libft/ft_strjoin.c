/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 08:09:20 by mtrautne          #+#    #+#             */
/*   Updated: 2022/07/19 10:18:12 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function description:
Allocates (with malloc(3)) and returns a new string, which is the result of the 
concatenation of ’s1’ and ’s2’.

Return value:
The new string. NULL if the allocation fails.

Parameters:
s1: The prefix string. s2: The suffix string.

External functions:
malloc

Particularities:
Would be nice to have another variable for ft_strlen(s1) + ft_strlen(s2), but 
then fct is more than 25 lines.*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		l;
	char		*j;

	i = 0;
	l = 0;
	if (!s1 && !s2)
		return (ft_strdup(""));
	j = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!j)
		return (0);
	while (i < ft_strlen(s1) + ft_strlen(s2) && s1[i])
	{
		j[i] = s1[i];
		i++;
	}
	while (i < ft_strlen(s1) + ft_strlen(s2) && s2[l])
	{
		j[i] = s2[l];
		i++;
		l++;
	}
	j[i] = '\0';
	return (j);
}
