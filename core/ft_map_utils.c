/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 01:52:05 by npalissi          #+#    #+#             */
/*   Updated: 2024/11/07 11:04:36 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	free_array(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	return (0);
}

int	ft_has_item_player(char **map, t_data *data, int y)
{
	int	x;
	int	n_player;
	int	n_exit;

	n_exit = 0;
	data->map.item = 0;
	n_player = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == BLOC_ITEM)
				data->map.item++;
			else if (map[y][x] == BLOC_BEGIN)
				n_player++;
			else if (map[y][x] == BLOC_EXIT)
				n_exit++;
			else if (map[y][x] != BLOC_EMPTY && map[y][x] != BLOC_WALL)
				return (0);
			x++;
		}
		y++;
	}
	return (n_player == 1 && data->map.item >= 1 && n_exit == 1);
}

void	ft_draw_img(t_data *data, void *img, int x, int y)
{
	int	w;

	w = data->img.size.x;
	mlx_put_image_to_window(data->mlx, data->win, img, x * w, y * w);
}

void	*ft_f_to_img(t_data *data, char *mat)
{
	int		w;
	void	*img;

	w = data->img.size.x;
	img = mlx_xpm_file_to_image(data->mlx, mat, &w, &w);
	return (img);
}

void	ft_destroy_img(t_data data)
{
	mlx_destroy_image(data.mlx, data.img.empty);
	mlx_destroy_image(data.mlx, data.img.player);
	mlx_destroy_image(data.mlx, data.img.item);
	mlx_destroy_image(data.mlx, data.img.wall);
	mlx_destroy_image(data.mlx, data.img.end);
	mlx_destroy_image(data.mlx, data.img.player_eat);
}
