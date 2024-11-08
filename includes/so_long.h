/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:38:40 by npalissi          #+#    #+#             */
/*   Updated: 2024/11/07 15:55:33 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define KEY_UP 119
# define KEY_DOWN 115
# define KEY_LEFT 97
# define KEY_RIGHT 100

# define W_IMG 50
# define W_MAX 38 // 1900 / 50
# define H_MAX 20 // 1000 / 50

# define BLOC_EMPTY	'0'
# define BLOC_WALL	'1'
# define BLOC_ITEM	'C'
# define BLOC_EXIT	'E'
# define BLOC_BEGIN	'P'

typedef struct s_vector_2d
{
	int				x;
	int				y;
}					t_vector_2d;

typedef struct s_player
{
	void			*img;
	int				item;
	t_vector_2d		pos;
}					t_player;

typedef struct s_img
{
	void			*wall;
	void			*empty;
	void			*player;
	void			*player_eat;
	void			*item;
	void			*end;
	t_vector_2d		size;
}					t_img;

typedef struct s_map
{
	char			**map_2d;
	int				item;
	t_vector_2d		size;

}					t_map;

typedef struct s_mouse
{
	t_vector_2d start;
	int			stat;

}	t_mouse;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	int				count;
	int				stat_mouse;
	int				w;
	int				h;
	t_vector_2d		start_win;
	t_mouse			mouse;
	t_map			map;
	t_img			img;
	t_player		player;
}					t_data;

int			key_hook(int key, t_data *data);
int			ft_create_map(t_data *data, char *file_name);
int			free_array(char **map);
int			map_is_valid(t_data *data);
void		ft_draw_img(t_data *data, void *img, int x, int y);
void		*ft_f_to_img(t_data *data, char *mat);
void		ft_init_img(t_data *data);
int			ft_exit(t_data *data);
void		ft_destroy_img(t_data data);
void		v2_draw(t_data *data);
int			ft_has_item_player(char **map, t_data *data, int y);
void		*ft_get_img_player(t_data data);
int 		ft_mouse_press(int button , int x , int y, t_data *data);
int 		ft_mouse_release(int button, int x , int y, t_data *data);
int			ft_mouse_move(int x , int y , t_data *data);
void		draw_img(t_data *data, int x_start, int y_start, t_vector_2d pos_player);
#endif
