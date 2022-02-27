/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:16:51 by ldoctori          #+#    #+#             */
/*   Updated: 2021/10/18 19:38:54 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_isneg(char *str, int n, int count)
{
	str[count] = '\0';
	count--;
	while (count > 0)
	{
		str[count] = n % 10 * (-1) + '0';
		count--;
		n /= 10;
	}
	str[count] = '-';
}

void	ft_ispos(char *str, int n, int count)
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

char	*ft_itoa(int n)
{
	int		count;
	int		nbuff;
	char	*str;

	count = 0;
	nbuff = n;
	while (nbuff != 0)
	{
		nbuff /= 10;
		count++;
	}
	if (n < 0)
		count++;
	if (n == 0)
		count = 1;
	str = malloc(count + 1);
	if (!str)
		return (0);
	if (n < 0)
		ft_isneg(str, n, count);
	else
		ft_ispos(str, n, count);
	return (str);
}
