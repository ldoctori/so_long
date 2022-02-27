/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:24:27 by ldoctori          #+#    #+#             */
/*   Updated: 2022/01/11 09:37:34 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	check_amount(char *tmp)
{
	int	p_amount;
	int	c_amount;
	int	e_amount;

	p_amount = 0;
	c_amount = 0;
	e_amount = 0;
	while (*tmp)
	{
		if (*tmp == 'P')
			p_amount++;
		else if (*tmp == 'C')
			c_amount++;
		else if (*tmp == 'E')
			e_amount++;
		tmp++;
	}
	if (p_amount != 1 || c_amount < 1 || e_amount != 1)
		return (-1);
	return (0);
}

int	check_forbidden_symbols(char *tmp)
{
	if (*tmp != '1')
		return (-1);
	while (*tmp)
	{
		if (*tmp != '1' && *tmp != 'P' && *tmp != 'C'
			&& *tmp != '0' && *tmp != 'E' && *tmp != '\n')
			return (-1);
		if (*tmp == '\n')
		{
			if (*(tmp - 1) != '1' || (*(tmp + 1) != '1' && *(tmp + 1) != '\0'))
				return (-1);
		}
		tmp++;
	}
	tmp--;
	while (*tmp != '\n')
	{
		if (*tmp != '1')
			return (-1);
		tmp--;
	}
	return (0);
}

int	check_rectan(t_truct *map)
{
	char	*tmp;
	int		len;

	map->width = 0;
	tmp = ft_strchr(map->map, '\n');
	while (tmp)
	{
		tmp++;
		map->width++;
		tmp = ft_strchr(tmp, '\n');
	}
	map->width++;
	len = ft_strlen(map->map) + 1;
	if (len % map->width != 0)
		return (-1);
	map->len = (len - map->width) / map->width;
	return (0);
}

void	check_valid_map(t_truct *map)
{
	char	*tmp;

	if (check_rectan(map) == -1)
	{	
		free(map->map);
		map->map = NULL;
		return ;
	}
	tmp = map->map;
	while (*tmp != '\n')
	{
		if (*tmp != '1')
		{
			free(map->map);
			map->map = NULL;
			return ;
		}
		tmp++;
	}
	if (check_forbidden_symbols(map->map) == -1 || check_amount(map->map) == -1)
	{
		free(map->map);
		map->map = NULL;
	}
}

t_truct	ft_read_map(int fd)
{
	t_truct	s_map;
	char	*line;
	char	*tmp;
	char	*map;

	map = malloc(1);
	*map = '\0';
	while (get_next_line(&line, fd) > 0)
	{
		tmp = map;
		map = ft_strjoin(map, line);
		free(tmp);
		tmp = map;
		map = ft_strjoin(map, "\n");
		free(tmp);
		free(line);
	}
	tmp = map;
	map = ft_strjoin(map, line);
	free(line);
	free(tmp);
	s_map.map = map;
	if (map)
		check_valid_map(&s_map);
	return (s_map);
}
