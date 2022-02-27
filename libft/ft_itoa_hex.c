/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:39:54 by ldoctori          #+#    #+#             */
/*   Updated: 2022/01/07 16:17:35 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ispos_hex(char *base, unsigned long int n, int count)
{
	char	*str;

	str = malloc(count + 1);
	if (!str)
		return (0);
	str[count] = '\0';
	count--;
	if (n == 0)
		str[count] = '0';
	while (count >= 0 && n != 0)
	{
		str[count] = base[n % 16];
		n /= 16;
		count--;
	}
	return (str);
}

char	*ft_itoa_hex(unsigned long int n)
{
	char				*base;
	unsigned long int	nbuff;
	int					count;

	count = 0;
	nbuff = n;
	base = "0123456789abcdef";
	while (nbuff != 0)
	{
		nbuff /= 16;
		count++;
	}
	if (n == 0)
		count = 1;
	return (ft_ispos_hex(base, n, count));
}
