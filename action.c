/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 12:33:02 by ldoctori          #+#    #+#             */
/*   Updated: 2022/01/08 12:33:04 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	w_move(t_truct *map, char **player, int *col)
{
	**player = '0';
	*player -= map->len + 1;
	if (**player == 'C')
		(*col)--;
	**player = 'P';
}

void	a_move(t_truct *map, char **player, int *col)
{
	**player = '0';
	(*player)--;
	if (**player == 'C')
		(*col)--;
	**player = 'P';
}

void	s_move(t_truct *map, char **player, int *col)
{
	**player = '0';
	*player += map->len + 1;
	if (**player == 'C')
		(*col)--;
	**player = 'P';
}

void	d_move(t_truct *map, char **player, int *col)
{
	**player = '0';
	(*player)++;
	if (**player == 'C')
		(*col)--;
	**player = 'P';
}
