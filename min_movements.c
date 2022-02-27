/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_movements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:10:31 by ldoctori          #+#    #+#             */
/*   Updated: 2022/01/07 10:33:38 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	col_number(char	*map)
{
	int	col;

	col = 0;
	while (*map)
	{
		if (*map == 'C')
			col++;
		map++;
	}
	return (col);
}

void	free_map_arr(int **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	int_for_map(char ch)
{
	if (ch == '1')
		return (-1);
	if (ch == '0')
		return (-2);
	if (ch == 'P')
		return (0);
	if (ch == 'O')
		return (-3);
	return (2);
}

void	exit_position(t_wave *wave, char **tmp, int *i, int *j)
{	
	while (*j < wave->w)
	{
		wave->arr[*i][*j] = int_for_map(**tmp);
		if (**tmp == 'O')
		{
			wave->xe = *j;
			wave->ye = *i;
		}
		(*j)++;
		(*tmp)++;
	}
	wave->arr[*i][*j] = '\0';
}

int	minimal_movements(t_truct *map)
{
	t_wave	wave;
	int		i;
	int		j;
	int		min_move;
	char	*tmp;

	wave.h = map->width;
	wave.w = map->len;
	tmp = map->map;
	wave.arr = malloc(sizeof(int *) * (map->width + 1));
	i = 0;
	while (i < wave.h)
	{
		j = 0;
		wave.arr[i] = malloc(sizeof(int) * (map->len + 1));
		exit_position(&wave, &tmp, &i, &j);
		i++;
		tmp++;
	}
	wave.arr[i] = 0;
	min_move = wave_algorithm(&wave);
	free_map_arr(wave.arr);
	return (min_move);
}
