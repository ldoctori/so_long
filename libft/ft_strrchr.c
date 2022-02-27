/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:23:53 by ldoctori          #+#    #+#             */
/*   Updated: 2021/10/18 19:46:42 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*loc;
	const char	*ptr;

	if (c == '\0')
		return (ft_strchr(s, c));
	loc = 0;
	ptr = ft_strchr(s, c);
	while ((ptr != 0))
	{
		loc = ptr;
		s = ptr + 1;
		ptr = ft_strchr(s, c);
	}
	return ((char *) loc);
}
