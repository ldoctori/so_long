/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_dynamic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:18:24 by ldoctori          #+#    #+#             */
/*   Updated: 2022/01/07 11:18:26 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	render_player(t_vars *vars)
{
	unsigned int	x;
	unsigned int	y;
	char			*player;

	vars->player->img = mlx_xpm_file_to_image(vars->mlx,
			"./winter_free/snowman.xpm", &vars->player->img_width,
			&vars->player->img_height);
	vars->player->addr = mlx_get_data_addr(vars->player->img,
			&vars->player->bits_per_pixel, &vars->player->line_length,
			&vars->player->endian);
	player = ft_strchr(vars->map->map, 'P');
	if (!player)
	{	
		free(vars->map->map);
		free(vars->mlx);
		exit(EXIT_SUCCESS);
	}
	y = (player - vars->map->map) / (vars->map->len + 1);
	x = (player - vars->map->map - y * (vars->map->len + 1))
		* vars->obstacles->img_width + vars->obstacles->img_width / 4;
	y = y * vars->obstacles->img_height + vars->obstacles->img_height / 4;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->player->img, x, y);
}

void	render_min_moves_string(t_vars *vars)
{	
	char	*min_move;

	if (vars->min_move != 0)
	{
		min_move = ft_itoa(vars->min_move);
		mlx_string_put(vars->mlx, vars->win, 10, 30, 0x000000FF, min_move);
		free(min_move);
	}
}

void	render_you_lose(t_vars *vars)
{
	t_data	lose;

	lose.img = mlx_xpm_file_to_image(vars->mlx, "./winter_free/lose.xpm",
			&lose.img_width, &lose.img_height);
	lose.addr = mlx_get_data_addr(lose.img, &lose.bits_per_pixel,
			&lose.line_length, &lose.endian);
	mlx_put_image_to_window(vars->mlx, vars->win, lose.img,
		vars->obstacles->img_width * (vars->map->len) / 4,
		vars->obstacles->img_height * (vars->map->width) / 4);
}
