/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 03:11:09 by npalissi          #+#    #+#             */
/*   Updated: 2024/11/07 17:06:21 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_img(t_data *data, int x_start, int y_start, t_vector_2d pos_player)
{
	int		x;
	int		y;
	char	pos;

	y = 0;
	while (y <= H_MAX && data->map.map_2d[y + y_start])
	{
		x = 0;
		while (data->map.map_2d[y + y_start][x + x_start])
		{
			pos = data->map.map_2d[y + y_start][x + x_start];
			if (pos == BLOC_WALL)
				ft_draw_img(data, data->img.wall, x, y);
			else if (pos == BLOC_ITEM)
				ft_draw_img(data, data->img.item, x, y);
			else if (pos == BLOC_EXIT)
				ft_draw_img(data, data->img.end, x, y);
			else if (pos == BLOC_EMPTY)
				ft_draw_img(data, data->img.empty, x, y);
			else
				ft_draw_img(data, ft_get_img_player(*data), pos_player.x - x_start, pos_player.y - y_start);
			x++;
		}
		y++;
	}
	
}

void	v2_draw(t_data *data)
{
	t_vector_2d	pos_player;
	t_vector_2d	size_map;
	char		**map;
	int			x_start;
	int			y_start;

	map = data->map.map_2d;
	pos_player = (t_vector_2d){data->player.pos.x, data->player.pos.y};
	size_map = (t_vector_2d){data->map.size.x, data->map.size.y};
	x_start = pos_player.x - W_MAX / 2;
	if (x_start < 0)
		x_start = 0;
	else if (x_start + W_MAX >= size_map.x)
		x_start = size_map.x - W_MAX;
	y_start = pos_player.y - H_MAX / 2;
	if (y_start < 0)
		y_start = 0;
	else if (y_start + H_MAX >= size_map.y)
		y_start = size_map.y - H_MAX;
	data->start_win = (t_vector_2d){x_start, y_start};
	draw_img(data, x_start, y_start, pos_player);
}

void	ft_update_player(t_data *data)
{
	char	bloc_player;

	bloc_player = data->map.map_2d[data->player.pos.y][data->player.pos.x];
	if (bloc_player == BLOC_ITEM)
	{
		
		data->player.item += 1;
	}
	if (bloc_player == BLOC_EXIT && data->map.item == data->player.item)
	{
		write(1, "\nfinish", 7);
		ft_exit(data);
	}
	data->map.map_2d[data->player.pos.y][data->player.pos.x] = BLOC_BEGIN;
}

void	ft_move_player(int x, int y, t_data *data)
{
	int	n_pos_x;
	int	n_pos_y;

	n_pos_x = data->player.pos.x + x;
	n_pos_y = data->player.pos.y + y;
	if (n_pos_x >= data->map.size.x || n_pos_x < 0)
		return ;
	if (n_pos_y >= data->map.size.y || n_pos_y < 0)
		return ;
	if (data->map.map_2d[n_pos_y][n_pos_x] == BLOC_WALL)
		return ;
	data->map.map_2d[n_pos_y - y][n_pos_x -x] = BLOC_EMPTY;
	ft_putstr_fd("movement : ", 1);
	ft_putnbr_fd(++data->count, 1);
	write(1, "\n", 1);
	data->player.pos.x = n_pos_x;
	data->player.pos.y = n_pos_y;
	ft_update_player(data);
	v2_draw(data);
}

int	key_hook(int key, t_data *data)
{
	if (key == KEY_UP)
		ft_move_player(0, -1, data);
	else if (key == KEY_DOWN)
		ft_move_player(0, 1, data);
	else if (key == KEY_LEFT)
		ft_move_player(-1, 0, data);
	else if (key == KEY_RIGHT)
		ft_move_player(1, 0, data);
	else if (key == 65307)
		ft_exit(data);
	else
		return (0);
	return (1);
}
