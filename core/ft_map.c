/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:58:51 by npalissi          #+#    #+#             */
/*   Updated: 2024/11/07 14:51:58 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_img(t_data *data)
{
	data->img.size.x = W_IMG;
	data->img.empty = ft_f_to_img(data, "texture/background.xpm");
	data->img.wall = ft_f_to_img(data, "texture/wall.xpm");
	data->img.player = ft_f_to_img(data, "texture/player.xpm");
	data->img.item = ft_f_to_img(data, "texture/item.xpm");
	data->img.end = ft_f_to_img(data, "texture/end.xpm");
	data->img.player_eat = ft_f_to_img(data,"texture/player_eat.xpm");
}



void *ft_get_img_player(t_data data)
{
	t_vector_2d	pos;
	char		**map;

	map = data.map.map_2d;
	pos = data.player.pos;
	if (map[pos.y - 1][pos.x] && map[pos.y - 1][pos.x] == BLOC_ITEM)
		return (data.img.player_eat);
	if (map[pos.y + 1][pos.x] && map[pos.y + 1][pos.x] == BLOC_ITEM)
		return (data.img.player_eat);
	if (map[pos.y][pos.x - 1] && map[pos.y][pos.x - 1] == BLOC_ITEM)
		return (data.img.player_eat);
	if (map[pos.y][pos.x + 1] && map[pos.y][pos.x + 1] == BLOC_ITEM)
		return (data.img.player_eat);
	return (data.img.player);
}

