/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:22:54 by ldoctori          #+#    #+#             */
/*   Updated: 2021/10/19 09:01:52 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	if (!s || !f)
		return (0);
	i = 0;
	str = ft_strdup((char *)s);
	if (!str)
		return (0);
	while (str[i])
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	return (str);
}
