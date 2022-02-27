/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:19:36 by ldoctori          #+#    #+#             */
/*   Updated: 2022/01/07 11:19:37 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	render_next_frame(t_vars *vars)
{	
	if (vars->lose == 1 && ft_strchr(vars->map->map, 'P') != 0)
	{	
		mlx_clear_window(vars->mlx, vars->win);
		render_you_lose(vars);
		mlx_hook(vars->win, 2, 0, ft_close, vars);
	}
	else
	{
		mlx_clear_window(vars->mlx, vars->win);
		render_snow(vars);
		render_obstacles(vars);
		render_collectables(vars);
		render_exit(vars);
		render_player(vars);
		render_min_moves_string(vars);
	}
	return (0);
}
