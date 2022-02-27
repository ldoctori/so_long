/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:57:28 by ldoctori          #+#    #+#             */
/*   Updated: 2022/01/11 09:38:58 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	is_dot_ber(int argc, char **argv)
{
	char	*tmp;

	if (argc != 2)
		ft_close_error();
	tmp = ft_strchr(argv[1], '.');
	if (!tmp)
		ft_close_error();
	if (ft_strncmp(tmp, ".ber", 4) != 0)
		ft_close_error();
}

int	key_hook(int keycode, t_vars *vars)
{
	char		*player;
	static char	*exit;
	static int	min_move;

	if (keycode == 53)
		ft_close(keycode, vars);
	player = ft_strchr(vars->map->map, 'P');
	if (exit == 0)
		exit = ft_strchr(vars->map->map, 'E');
	vars->min_move = player_move(vars->map, player, exit, keycode);
	if (min_move == 0 && *exit == 'O' && vars->min_move != -1)
	{
		min_move = vars->min_move + 1;
	}
	if (min_move != 0 && vars->min_move != -1)
	{
		min_move--;
		vars->min_move = min_move;
		if (min_move == 0)
			vars->lose = 1;
	}
	if (vars->min_move == -1)
		vars->min_move = min_move;
	return (0);
}

void	main_helper(t_data *obstacles, t_data *player, t_vars *vars)
{
	obstacles->img = mlx_xpm_file_to_image(vars->mlx, "./winter_free/tree.xpm",
			&obstacles->img_width, &obstacles->img_height);
	obstacles->addr = mlx_get_data_addr(obstacles->img,
			&obstacles->bits_per_pixel, &obstacles->line_length,
			&obstacles->endian);
	player->img = mlx_xpm_file_to_image(vars->mlx, "./winter_free/snowman.xpm",
			&player->img_width, &player->img_height);
	player->addr = mlx_get_data_addr(player->img, &player->bits_per_pixel,
			&player->line_length, &player->endian);
	vars->obstacles = obstacles;
	vars->player = player;
}

int	main(int argc, char **argv)
{
	int		fd;
	t_truct	s_map;
	t_vars	vars;
	t_data	obstacles;
	t_data	player;

	vars.lose = 0;
	is_dot_ber(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_close_error();
	s_map = ft_read_map(fd);
	close(fd);
	vars.map = &s_map;
	if (s_map.map == 0 || *(s_map.map) == '\0')
		ft_close_error();
	vars.mlx = mlx_init();
	main_helper(&obstacles, &player, &vars);
	vars.win = mlx_new_window(vars.mlx, obstacles.img_width * (s_map.len),
			obstacles.img_height * (s_map.width), "GAME!");
	mlx_hook(vars.win, 17, 0, ft_red_cross, &vars);
	mlx_hook(vars.win, 2, 0, key_hook, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
