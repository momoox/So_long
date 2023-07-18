/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 05:53:28 by mgeisler          #+#    #+#             */
/*   Updated: 2023/07/15 16:38:04 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_tx(t_struct *mapi)
{
	mapi->tx = mlx_load_png("assets/cat.png");
	mapi->collectible_img = mlx_texture_to_image(mapi->mlx, mapi->tx);
	mlx_delete_texture(mapi->tx);
	mapi->tx = mlx_load_png("assets/wall.png");
	mapi->wall_img = mlx_texture_to_image(mapi->mlx, mapi->tx);
	mlx_delete_texture(mapi->tx);
	mapi->tx = mlx_load_png("assets/floor.png");
	mapi->floor_img = mlx_texture_to_image(mapi->mlx, mapi->tx);
	mlx_delete_texture(mapi->tx);
}

void	correct_images(t_struct *mapi, int x, int y)
{
	if (mapi->map[y][x] == '0')
		mlx_image_to_window(mapi->mlx, mapi->floor_img, x * 64, y * 64);
	if (mapi->map[y][x] == '1')
		mlx_image_to_window(mapi->mlx, mapi->wall_img, x * 64, y * 64);
	if (mapi->map[y][x] == 'C')
		mlx_image_to_window(mapi->mlx, mapi->collectible_img, x * 64, y * 64);
	if (mapi->map[y][x] == 'E' && mapi->collectible > 0)
		mlx_image_to_window(mapi->mlx, mapi->floor_img, x * 64, y * 64);
}

void	render_map(t_struct *mapi)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (!mapi->tx_loaded)
	{
		load_tx(mapi);
		load_tx_portal(mapi);
		load_tx_player(mapi);
		load_tx_enemy(mapi);
		mapi->tx_loaded = 1;
	}
	while (mapi->map[y])
	{
		x = 0;
		while (x <= mapi->length)
		{
			correct_images(mapi, x, y);
			x++;
		}
		y++;
	}
}
