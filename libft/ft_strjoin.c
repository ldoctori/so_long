/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:21:59 by ldoctori          #+#    #+#             */
/*   Updated: 2021/10/19 09:01:27 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ns;
	unsigned int	size;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	ns = malloc(size * sizeof(*s1));
	if (!ns)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
		ns[j++] = s1[i++];
	i = 0;
	while (s2[i])
		ns[j++] = s2[i++];
	ns[j] = '\0';
	return (ns);
}
