/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:26:10 by ldoctori          #+#    #+#             */
/*   Updated: 2022/01/07 10:30:14 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	render_obstacles_helper(t_vars *vars, int x, int y)
{
	char	*prev;
	char	*map;

	map = vars->map->map;
	prev = map - 1;
	while (*(map))
	{
		if (*(map) == '1')
		{
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->obstacles->img, x, y);
			x += vars->obstacles->img_width;
		}
		else if (*(map) == '\n')
		{
			x = 0;
			y += vars->obstacles->img_height;
			prev = map;
		}
		else
			x += vars->obstacles->img_width;
		map++;
	}
}

void	render_obstacles(t_vars *vars)
{
	render_obstacles_helper(vars, 0, 0);
}

void	render_exit(t_vars *vars)
{
	static unsigned int	x;
	static unsigned int	y;
	static char			*p_exit;
	static t_data		exit;

	if (!p_exit)
		p_exit = ft_strchr(vars->map->map, 'E');
	if (!exit.img)
	{
		exit.img = mlx_xpm_file_to_image(vars->mlx,
				"./winter_free/global.xpm", &exit.img_width, &exit.img_height);
		exit.addr = mlx_get_data_addr(exit.img,
				&exit.bits_per_pixel, &exit.line_length, &exit.endian);
	}
	if (x == 0 && y == 0)
	{
		y = (p_exit - vars->map->map) / (vars->map->len + 1);
		x = (p_exit - vars->map->map
				- y * (vars->map->len + 1)) * vars->obstacles->img_width;
		y = y * vars->obstacles->img_height;
	}
	vars->exit = &exit;
	mlx_put_image_to_window(vars->mlx, vars->win, exit.img, x, y);
}

void	render_collectables(t_vars *vars)
{
	unsigned int	x;
	unsigned int	y;
	static t_data	coll;
	char			*p_coll;

	if (!coll.img)
	{
		coll.img = mlx_xpm_file_to_image(vars->mlx,
				"./winter_free/stars.xpm", &coll.img_width, &coll.img_height);
		coll.addr = mlx_get_data_addr(coll.img, &coll.bits_per_pixel,
				&coll.line_length, &coll.endian);
	}
	p_coll = ft_strchr(vars->map->map, 'C');
	while (p_coll)
	{
		y = (p_coll - vars->map->map) / (vars->map->len + 1);
		x = (p_coll - vars->map->map - y * (vars->map->len + 1))
			* vars->obstacles->img_width + vars->obstacles->img_width / 4;
		y = y * vars->obstacles->img_height + vars->obstacles->img_height / 4;
		mlx_put_image_to_window(vars->mlx, vars->win, coll.img, x, y);
		p_coll = ft_strchr(p_coll + 1, 'C');
	}
}

void	render_snow(t_vars *vars)
{
	unsigned int	x;
	unsigned int	y;
	static t_data	snow;

	x = 0;
	if (!snow.img)
	{
		snow.img = mlx_xpm_file_to_image(vars->mlx,
				"./winter_free/SNOW.xpm", &snow.img_width, &snow.img_height);
		snow.addr = mlx_get_data_addr(snow.img, &snow.bits_per_pixel,
				&snow.line_length, &snow.endian);
	}
	while (x < vars->map->len)
	{	
		y = 0;
		while (y < vars->map->width)
		{
			mlx_put_image_to_window(vars->mlx, vars->win,
				snow.img, x * snow.img_width, y * snow.img_height);
			y++;
		}
		x++;
	}
}
