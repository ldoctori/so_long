/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:11:40 by ldoctori          #+#    #+#             */
/*   Updated: 2022/01/07 16:11:42 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*ft_read(int fd)
{
	char	*buff;
	int		rb;
	char	*str;
	char	*tmp;

	buff = malloc(2);
	str = malloc(1);
	str[0] = '\0';
	rb = read(fd, buff, 1);
	buff[rb] = '\0';
	if (rb < 0)
		free(str);
	while (rb > 0)
	{	
		tmp = str;
		str = ft_strjoin_g(str, buff);
		if (!str)
			return (0);
		free(tmp);
		rb = read(fd, buff, 1);
	}
	free(buff);
	if (rb == -1)
		return (0);
	return (str);
}

void	gnl_helper(char **line, char **str, char *n)
{
	char	*tmp;

	tmp = *str;
	*line = ft_strndup_g(*str, n - *str);
	n++;
	*str = ft_strndup_g(n, ft_strlen_g(n));
	free(tmp);
}

int	get_next_line(char **line, int fd)
{
	static char	*str;
	char		*n;

	if (!str)
	{
		str = ft_read(fd);
		if (!str)
			return (-1);
	}
	n = ft_strchr_g(str, '\n');
	if (n)
	{
		gnl_helper(line, &str, n);
		if (!(*line))
			return (-1);
		return (1);
	}
	else
	{
		*line = ft_strndup_g(str, ft_strchr_g(str, '\0') - str);
		free(str);
		if (!(*line))
			return (-1);
		return (0);
	}
}
