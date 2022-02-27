/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:19:05 by ldoctori          #+#    #+#             */
/*   Updated: 2021/10/19 18:55:26 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	char			*ptr;
	unsigned int	count;
	unsigned char	ch;

	ptr = (char *) s;
	ch = (unsigned char) c;
	count = 0;
	while (count < n)
	{
		if ((unsigned char) ptr[count] == ch)
			return ((char *) ptr + count);
		count++;
	}
	return (0);
}
