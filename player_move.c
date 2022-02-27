/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 09:17:39 by ldoctori          #+#    #+#             */
/*   Updated: 2022/01/07 09:58:26 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	player_move_helper(t_truct *map, char *exit, int *col)
{
	static int	movements;
	static int	min_move;

	movements++;
	printf("moves number = %i\n", movements);
	if (*col == 0)
	{
		*exit = 'O';
		if (min_move == 0)
			min_move = minimal_movements(map) + 1;
	}
	return (min_move);
}

int	player_move(t_truct *map, char *player, char *exit, int keycode)
{
	static int	col;
	char		*tmp;

	tmp = player;
	if (col == 0)
		col = col_number(map->map);
	if (keycode == 13 && *(player - (map->len + 1)) != '1'
		&& *(player - (map->len + 1)) != 'E')
		w_move(map, &player, &col);
	if (keycode == 0 && *(player - 1) != '1' && *(player - 1) != 'E')
		a_move(map, &player, &col);
	if (keycode == 1 && *(player + map->len + 1) != '1'
		&& *(player + map->len + 1) != 'E')
		s_move(map, &player, &col);
	if (keycode == 2 && *(player + 1) != '1' && *(player + 1) != 'E')
		d_move(map, &player, &col);
	if (tmp == player)
		return (-1);
	return (player_move_helper(map, exit, &col));
}
