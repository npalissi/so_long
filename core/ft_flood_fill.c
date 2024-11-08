/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 23:05:49 by npalissi          #+#    #+#             */
/*   Updated: 2024/11/07 10:50:37 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	fti(t_vector_2d *p, t_data data, t_vector_2d *stack,
							int *size)
{
	*p = stack[--(*size)];
	if (p->x < 0 || p->y < 0 || p->x >= data.map.size.x
		|| p->y >= data.map.size.y)
		return (1);
	if (data.map.map_2d[p->y][p->x] == BLOC_WALL)
		return (1);
	return (0);
}

static void	flood_fill_map(t_data data, t_vector_2d *item_exit, int size,
							int *visited)
{
	t_vector_2d	*stack;
	t_vector_2d	p;

	stack = malloc(data.map.size.x * data.map.size.y * sizeof(t_vector_2d));
	if (!stack)
		return ;
	stack[size++] = (t_vector_2d){data.player.pos.x, data.player.pos.y};
	while (size > 0)
	{
		if (fti(&p, data, stack, &size) || visited[p.y * data.map.size.x + p.x])
			continue ;
		if (data.map.map_2d[p.y][p.x] == BLOC_EXIT)
			item_exit->y += 1;
		if (data.map.map_2d[p.y][p.x] == BLOC_ITEM)
			item_exit->x += 1;
		visited[p.y * data.map.size.x + p.x] = 1;
		if (size + 4 >= data.map.size.x * data.map.size.y)
			continue ;
		stack[size++] = (t_vector_2d){p.x + 1, p.y};
		stack[size++] = (t_vector_2d){p.x - 1, p.y};
		stack[size++] = (t_vector_2d){p.x, p.y + 1};
		stack[size++] = (t_vector_2d){p.x, p.y - 1};
	}
	free(stack);
}

int	map_is_valid(t_data *data)
{
	int			*visited;
	t_vector_2d	item_exit;

	visited = ft_calloc(data->map.size.x * data->map.size.y, sizeof(int *));
	if (!visited)
		return (0);
	item_exit = (t_vector_2d){0, 0};
	flood_fill_map(*data, &item_exit, 0, visited);
	free(visited);
	return (item_exit.x == data->map.item && item_exit.y == 1);
}
