/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wave_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:56:03 by ldoctori          #+#    #+#             */
/*   Updated: 2022/01/07 11:56:05 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	delta(int dx[4], int dy[4])
{
	dx[0] = 1;
	dx[1] = 0;
	dx[2] = -1;
	dx[3] = 0;
	dy[0] = 0;
	dy[1] = 1;
	dy[2] = 0;
	dy[3] = -1;
}

int	smaller(t_wave *wave, int k)
{
	int	dx[4];
	int	dy[4];
	int	d;

	d = wave->arr[wave->ye][wave->xe];
	delta(dx, dy);
	while (k < 4)
	{
		if (wave->arr[wave->ye + dy[k]][wave->xe + dx[k]] > 0)
		{
			d = wave->arr[wave->ye + dy[k]][wave->xe + dx[k]];
			break ;
		}
		k++;
	}
	k = 0;
	while (k < 4)
	{
		if (d > wave->arr[wave->ye + dy[k]][wave->xe
			+ dx[k]] && wave->arr[wave->ye + dy[k]][wave->xe + dx[k]] >= 0)
			d = wave->arr[wave->ye + dy[k]][wave->xe + dx[k]];
		k++;
	}
	return (d);
}

void	path_finder(t_wave *wave, t_path *path)
{
	int	k;
	int	dx[4];
	int	dy[4];

	delta(dx, dy);
	k = 0;
	while (k < 4)
	{
		if (path->y + dy[k] >= 0 && path->y + dy[k] < wave->h
			&& path->x + dx[k] >= 0 && path->x + dx[k] < wave->w
			&& wave->arr[path->y + dy[k]][path->x + dx[k]] == -2)
		{
			wave->arr[path->y + dy[k]][path->x + dx[k]] = path->d + 1;
			path->stop = 1;
		}
		k++;
	}
}

int	wave_algorithm(t_wave *wave)
{
	t_path	path;

	path.d = 0;
	path.stop = 1;
	while (path.stop && wave->arr[wave->ye][wave->xe] == -3)
	{
		path.stop = 0;
		path.y = 0;
		while (path.y < wave->h)
		{
			path.x = 0;
			while (path.x < wave->w)
			{
				if (wave->arr[path.y][path.x] == path.d)
				{
					path_finder(wave, &path);
				}
				path.x++;
			}
			path.y++;
		}
		path.d++;
	}
	return (smaller(wave, 0));
}
