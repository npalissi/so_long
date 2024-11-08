/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 03:19:17 by npalissi          #+#    #+#             */
/*   Updated: 2024/11/07 15:51:23 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/so_long.h"

static void	ft_init_player(t_data *data)
{
	int	x;
	int	y;

	data->player.item = 0;
	y = 0;
	while (data->map.map_2d[y])
	{
		x = 0;
		while (data->map.map_2d[y][x])
		{
			if (data->map.map_2d[y][x] == BLOC_BEGIN)
			{
				data->player.pos = (t_vector_2d){x, y};
				return ;
			}
			x++;
		}
		y++;
	}
}

int	ft_exit(t_data *data)
{
	ft_destroy_img(*data);
	mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free_array(data->map.map_2d);
	free(data->mlx);
	exit(0);
	return (0);
}

int	main(int c, char **v)
{
	t_data	data;

	if (c != 2)
		return (write(1, "Error\nmap invalid !", 19));
	if (!ft_strnstr(v[1], ".ber", ft_strlen(v[1]))
		|| !ft_create_map(&data, v[1]))
		return (write(1, "Error\nmap invalid !", 19));
	ft_init_player(&data);
	if (!map_is_valid(&data))
		return (!free_array(data.map.map_2d)
			&& write(1, "Error\nmap invalid !", 19));
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	ft_init_img(&data);
	data.win = mlx_new_window(data.mlx, data.w, data.h, "so_long");
	data.count = 0;
	v2_draw(&data);
	mlx_hook(data.win, 17, 4, ft_exit, &data);
	mlx_hook(data.win, 2, 1L << 0, key_hook, &data);
	mlx_hook(data.win, 4, 1L<<2, ft_mouse_press  , &data);
	mlx_hook(data.win, 5, 1L<<3, ft_mouse_release, &data);
	mlx_hook(data.win, 6, 1L<<6, ft_mouse_move , &data);

	// mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
}
