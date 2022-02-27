/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:22:31 by ldoctori          #+#    #+#             */
/*   Updated: 2021/10/18 19:45:14 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int dstsize)
{
	unsigned int	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while ((src[i] != '\0') && (i < dstsize - 1))
	{
		dest[i] = src[i];
		i++;
	}	
	dest[i] = '\0';
	return (ft_strlen(src));
}
