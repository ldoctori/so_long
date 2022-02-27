/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:19:29 by ldoctori          #+#    #+#             */
/*   Updated: 2021/10/18 19:41:46 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	unsigned int	count;
	unsigned char	*pd;
	unsigned char	*ps;

	if (!src && !dest)
		return (0);
	pd = (unsigned char *) dest;
	ps = (unsigned char *) src;
	count = 0;
	while (count < n)
	{
		pd[count] = ps[count];
		count++;
	}
	return (pd);
}
