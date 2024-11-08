/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 03:09:38 by npalissi          #+#    #+#             */
/*   Updated: 2024/11/06 12:11:15 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_map_is_close(char **map, int h, int w)
{
	int	x;
	int	y;

	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			if (y == 0 || y == h - 1)
			{
				if (map[y][x] != BLOC_WALL)
					return (0);
			}
			else if (x == 0 || x == w -1)
				if (map[y][x] != BLOC_WALL)
					return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static int	ft_get_size_map(t_data *data, char **map)
{
	int	w;
	int	h;
	int	last_w;

	h = 0;
	last_w = -1;
	while (map[h])
	{
		w = 0;
		while (map[h][w])
			w++;
		if (last_w != -1 && last_w != w)
			return (0);
		last_w = w;
		h++;
	}
	data->map.size.x = w;
	data->map.size.y = h;
	return (1);
}

char	*ft_add_buf(char *tab, char *buff, int read_bytes)
{
	char	*tbl;
	char	*save_tbl;
	char	*save_tab;

	save_tab = tab;
	tbl = malloc(ft_strlen(tab) + read_bytes + 1);
	if (!tbl)
		return (0);
	save_tbl = tbl;
	while (*tab)
		*tbl++ = *tab++;
	while (read_bytes--)
		*tbl++ = *buff++;
	*tbl = '\0';
	free(save_tab);
	return (save_tbl);
}

char	**ft_get_map(char *file_name)
{
	int		fd;
	char	*tab;
	char	**map;
	char	buffer[150];
	int		read_bytes;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	tab = ft_calloc(1, 1);
	read_bytes = 1;
	while (read_bytes)
	{
		read_bytes = read(fd, buffer, 150);
		if (read_bytes)
			tab = ft_add_buf(tab, buffer, read_bytes);
		if (!tab && close(fd))
			return (0);
	}
	close(fd);
	map = ft_split(tab, '\n');
	free(tab);
	if (!map)
		return (0);
	return (map);
}

int	ft_create_map(t_data *data, char *file_name)
{
	file_name = ft_strjoin("map/", file_name, 0, 0);
	data->map.map_2d = ft_get_map(file_name);
	free(file_name);
	if (!data->map.map_2d)
		return (0);
	if (!ft_get_size_map(data, data->map.map_2d))
		return (free_array(data->map.map_2d));
	if (!ft_has_item_player(data->map.map_2d, data, 0))
		return (free_array(data->map.map_2d));
	if (!ft_map_is_close(data->map.map_2d, data->map.size.y, data->map.size.x))
		return (free_array(data->map.map_2d));
	data->w = W_IMG * data->map.size.x;
	data->h = W_IMG * data->map.size.y;
	if (data->w > 1900)
		data->w = 1900;
	if (data->h > 1000)
		data->h = 1000;
	return (1);
}
