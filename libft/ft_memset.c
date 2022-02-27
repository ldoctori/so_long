/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:19:48 by ldoctori          #+#    #+#             */
/*   Updated: 2021/10/19 07:49:29 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, unsigned int n)
{
	unsigned int	count;
	unsigned char	*p;

	p = (unsigned char *) s;
	count = 0;
	while (count < n)
	{
		p[count] = c;
		count++;
	}
	return (p);
}
