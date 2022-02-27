/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:14:13 by ldoctori          #+#    #+#             */
/*   Updated: 2022/01/07 16:14:15 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_g(char	*str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strjoin_g(char *str, char *buff)
{
	char	*new_str;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen_g(str) + ft_strlen_g(buff) + 1;
	new_str = malloc(len);
	if (!new_str)
		return (0);
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	while (buff[j])
	{
		new_str[i] = buff[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strchr_g(char *str, char ch)
{
	while (*str)
	{
		if (*str == ch)
			return (str);
		str++;
	}
	if (*str == ch)
		return (str);
	return (0);
}

char	*ft_strndup_g(char *str, int len)
{
	char	*new_str;
	int		i;

	new_str = malloc(len + 1);
	i = 0;
	if (!new_str)
		return (0);
	while (str[i] && i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
