/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:34:52 by ldoctori          #+#    #+#             */
/*   Updated: 2022/01/11 09:35:02 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	ft_red_cross(int keycode, t_vars *vars)
{
	exit(EXIT_SUCCESS);
}

int	ft_close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->map->map);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_close_error(void)
{
	ft_putstr_fd("Error\n", 2);
	printf("Incorrect map!\n");
	exit(EXIT_SUCCESS);
}
