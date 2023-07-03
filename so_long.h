/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:26:23 by mgeisler          #+#    #+#             */
/*   Updated: 2023/07/03 20:54:26 by mgeisler         ###   ########.fr       */
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
	char	**map;
	int		player_x;
	int		player_y;
	int		length;
	int		width;
	int		player;
	int		collectible;
	int		exit;
	int		ennemies;
}			t_struct;

//print_test
void	print_map(t_struct	*mapi);

// utils
int		ft_strlen(char *str);
void	init_struct(t_struct *mapi);

//init_map
void	init_map(t_struct *mapi, char *file);

// parser
int		parser(t_struct *mapi);

//valid_map
void	map_size(t_struct *mapi);
int		map_closed(t_struct *mapi);
int		valid_map(t_struct *mapi);

//playable_map
void	map_content(t_struct *mapi);
int		check_content(t_struct *mapi);
void	pos_player(t_struct *mapi);
//void	fill(?);
//void	flood_fill();
///////
char	*ft_strjoin(char *s1, char *s2);

char	**ft_split(const char *s, char c);

#endif