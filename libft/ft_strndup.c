/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:21:19 by ldoctori          #+#    #+#             */
/*   Updated: 2021/10/18 19:44:15 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *src, int n)
{
	int		i;
	int		str_len;
	char	*copy;

	str_len = ft_strlen(src);
	copy = malloc(str_len + 1);
	if (copy == NULL)
		return (0);
	i = 0;
	while (i < str_len + 1 && i < n)
	{
		copy[i] = src[i];
		i++;
	}
	return (copy);
}
