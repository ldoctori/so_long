/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:42:47 by ldoctori          #+#    #+#             */
/*   Updated: 2021/11/02 09:42:50 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ispos_unsigned(char *str, unsigned int n, int count)
{
	str[count] = '\0';
	count--;
	while (count >= 0)
	{
		str[count] = n % 10 + '0';
		count--;
		n /= 10;
	}
}

char	*ft_itoa_unsigned(unsigned int n)
{
	int				count;
	unsigned int	nbuff;
	char			*str;

	count = 0;
	nbuff = n;
	while (nbuff != 0)
	{
		nbuff /= 10;
		count++;
	}
	if (n == 0)
		count = 1;
	str = malloc(count + 1);
	if (!str)
		return (0);
	ft_ispos_unsigned(str, n, count);
	return (str);
}
