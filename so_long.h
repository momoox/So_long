/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:26:23 by mgeisler          #+#    #+#             */
/*   Updated: 2023/07/16 19:35:43 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "gnl/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_struct
{
	char			**map;
	int				length;
	int				width;
	int				player;
	int				collectible;
	int				exit;
	int				enemy;

	int				steps;

	int				frame;
	int				frame_1;
	int				frame_2;
	int				portal_frame;
	int				portal_x;
	int				portal_y;
	int				player_frame;
	int				player_x;
	int				player_y;
	int				enemy_frame;
	int				**enemy_pos;

	int				tx_loaded;
	mlx_t			*mlx;
	mlx_texture_t	*tx;
	mlx_image_t		*player_img_1;
	mlx_image_t		*player_img_2;
	mlx_image_t		*enemy_img_1;
	mlx_image_t		*enemy_img_2;
	mlx_image_t		*enemy_img_3;
	mlx_image_t		*portal_img_1;
	mlx_image_t		*portal_img_2;
	mlx_image_t		*portal_img_3;
	mlx_image_t		*portal_img_4;
	mlx_image_t		*portal_img_5;
	mlx_image_t		*collectible_img;
	mlx_image_t		*floor_img;
	mlx_image_t		*wall_img;
	mlx_image_t		*steps_img;
}					t_struct;

//print_test
void		print_map(t_struct	*mapi);

// utils
int			ft_strlen(char *str);
void		init_struct(t_struct *mapi);
char		*ft_strdup(char *src);
int			ft_strlcpy(char *dest, char *src, int size);

//utils_2
void		ft_putchar(char c);
void		ft_putnbr(int n);

//init_map
int			init_map(t_struct *mapi, char *file);

// parser
int			parser(t_struct *mapi);

//valid_map
void		map_size(t_struct *mapi);
int			map_closed(t_struct *mapi);
int			valid_map(t_struct *mapi);
int			long_line(t_struct *mapi);

//playable_map
void		map_content(t_struct *mapi);
int			check_content(t_struct *mapi);
void		pos_player(t_struct *mapi);
t_struct	*temp_struct(t_struct *mapi);
int			valid_way(t_struct *temp, int x, int y);

//img_init
void		render_init(t_struct *mapi);

//render_map
void		load_tx(t_struct *mapi);
void		correct_images(t_struct *mapi, int x, int y);
void		render_map(t_struct *mapi);

//load_img
void		load_tx_player(t_struct *mapi);
void		load_tx_portal(t_struct *mapi);
void		load_tx_enemy(t_struct *mapi);

//anim
void		render_portal(t_struct *mapi);
void		render_player(t_struct *mapi);
void		render_enemy(t_struct *mapi);
void		portal_anim(void *param);
void		player_anim(void *param);
void		enemy_anim(void *param);

//find_pos
void		pos_portal(t_struct *mapi);
void		pos_enemy(t_struct *mapi);

//move
void 		end(int i);
void		display_move(t_struct *mapi);
void		keyb(mlx_key_data_t keydata, void *param);
void		keyb_2(mlx_key_data_t keydata, void *param);
int			canmove(t_struct *mapi, int x, int y);

///////
char		*ft_strjoin(char *s1, char *s2);

char		**ft_split(const char *s, char c);

void		ft_putstr(char *s);

char		*ft_itoa(int n);

//free 
void		free_all(t_struct *mapi);
void		free_maps(t_struct *mapi);

#endif