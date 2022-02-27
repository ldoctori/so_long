/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:24:05 by ldoctori          #+#    #+#             */
/*   Updated: 2021/10/19 08:41:07 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_while_set(char const *set, char ch)
{
	unsigned int	count;

	count = 0;
	while (set[count])
	{
		if (set[count] == ch)
			return (1);
		count++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*str_count;
	char	*start;
	char	*end;

	if (!s1 || !set)
		return (0);
	start = (char *) s1;
	while (start && ft_while_set(set, *start))
		start++;
	end = (char *)(s1 + ft_strlen(s1) - 1);
	if (start == end)
		return (0);
	while (end > start && ft_while_set(set, *end))
		--end;
	str = malloc((end - start + 2) * sizeof(*s1));
	if (!str)
		return (0);
	str_count = str;
	while (start <= end)
		*str_count++ = *start++;
	*str_count = 0;
	return (str);
}
