/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:03:30 by npalissi          #+#    #+#             */
/*   Updated: 2024/11/07 16:16:53 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>


int ft_mouse_press(int button , int x , int y, t_data *data)
{
	
	if (button != 1)
		return (0);
	printf("%d %d %d\n%p\n",button, x / W_IMG, y /W_IMG, data);
	data->mouse.start =  (t_vector_2d){x / W_IMG, y /W_IMG};
	
	data->mouse.stat = 1;
	return (0);
}



int ft_mouse_release(int button, int x , int y, t_data *data)
{
	if (button != 1)
		return (0);
	
	x = data->mouse.start.x - x/W_IMG + data->start_win.x;
	y = data->mouse.start.y - y/W_IMG + data->start_win.y;
	if (x < 0)
		x = 0;
	else if (x + W_MAX >= data->map.size.x)
		x = data->map.size.x - W_MAX;
	if (y < 0)
		y = 0;
	else if (y + H_MAX >= data->map.size.y)
		y = data->map.size.y - H_MAX;

	data->start_win.x = x;
	data->start_win.y = y;

	data->mouse.stat = 0;
	return (0);
}

int ft_mouse_move(int x , int y , t_data *data)
{
	if (!data->mouse.stat)
		return (0);
	x = data->mouse.start.x - x/W_IMG + data->start_win.x;
	y = data->mouse.start.y - y/W_IMG + data->start_win.y;

	if (x < 0)
		x = 0;
	else if (x + W_MAX >= data->map.size.x)
		x = data->map.size.x - W_MAX;
	if (y < 0)
		y = 0;
	else if (y + H_MAX >= data->map.size.y)
		y = data->map.size.y - H_MAX;

	// printf("%d %d",data->mouse.start.x - x /  + data->start_win.x, data->mouse.start.y - y + data->start_win.y);
	draw_img(data, x,y, data->player.pos);
	return (0);
}