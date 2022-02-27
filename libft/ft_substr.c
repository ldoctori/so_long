/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:24:18 by ldoctori          #+#    #+#             */
/*   Updated: 2021/10/20 09:25:25 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	j;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (!s)
		return (0);
	if (s_len - start < len)
		sub = malloc(s_len - start + 1);
	else
		sub = malloc(len + 1);
	if (!sub)
		return (0);
	j = 0;
	while (start <= s_len && j < len)
		sub[j++] = s[start++];
	sub[j] = '\0';
	return (sub);
}
