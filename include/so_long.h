/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:28:03 by ldoctori          #+#    #+#             */
/*   Updated: 2022/01/07 12:28:05 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
}	t_data;

typedef struct s_truct
{
	char	*map;
	int		len;
	int		width;
}	t_truct;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_truct	*map;
	t_data	*obstacles;
	t_data	*player;
	t_data	*exit;
	int		min_move;
	int		lose;
}	t_vars;

typedef struct s_wave
{
	int		**arr;
	int		xe;
	int		ye;
	int		w;
	int		h;
}	t_wave;

typedef struct s_path
{
	int		x;
	int		y;
	int		d;
	int		stop;
}	t_path;

void	render_obstacles(t_vars *vars);
void	render_exit(t_vars *vars);
void	render_collectables(t_vars *vars);
void	render_snow(t_vars *vars);
void	render_player(t_vars *vars);
void	render_min_moves_string(t_vars *vars);
void	render_you_lose(t_vars *vars);
void	w_move(t_truct *map, char **player, int *col);
void	a_move(t_truct *map, char **player, int *col);
void	s_move(t_truct *map, char **player, int *col);
void	d_move(t_truct *map, char **player, int *col);
int		render_next_frame(t_vars *vars);
int		wave_algorithm(t_wave *wave);
int		minimal_movements(t_truct *map);
int		col_number(char *map);
int		player_move(t_truct *map, char *player, char *exit, int keycode);
int		ft_close(int keycode, t_vars *vars);
int		ft_red_cross(int keycode, t_vars *vars);
int		ft_close_error(void);
t_truct	ft_read_map(int fd);
#endif
