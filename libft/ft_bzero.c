/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:14:20 by ldoctori          #+#    #+#             */
/*   Updated: 2021/10/18 19:36:53 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, unsigned int n)
{
	unsigned int	count;
	unsigned char	*p;

	p = (unsigned char *) s;
	count = 0;
	while (count < n)
	{
		p[count] = '\0';
		count++;
	}
}
