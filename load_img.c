/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:30:38 by mgeisler          #+#    #+#             */
/*   Updated: 2023/07/12 17:54:46 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_tx_player(t_struct *mapi)
{
	mapi->tx = mlx_load_png("assets/ghost_1.png");
	mapi->player_img_1 = mlx_texture_to_image(mapi->mlx, mapi->tx);
	mlx_delete_texture(mapi->tx);
	mapi->tx = mlx_load_png("assets/ghost_2.png");
	mapi->player_img_2 = mlx_texture_to_image(mapi->mlx, mapi->tx);
	mlx_delete_texture(mapi->tx);
}

void	load_tx_portal(t_struct *mapi)
{
	mapi->tx = mlx_load_png("assets/portal_1.png");
	mapi->portal_img_1 = mlx_texture_to_image(mapi->mlx, mapi->tx);
	mlx_delete_texture(mapi->tx);
	mapi->tx = mlx_load_png("assets/portal_2.png");
	mapi->portal_img_2 = mlx_texture_to_image(mapi->mlx, mapi->tx);
	mlx_delete_texture(mapi->tx);
	mapi->tx = mlx_load_png("assets/portal_3.png");
	mapi->portal_img_3 = mlx_texture_to_image(mapi->mlx, mapi->tx);
	mlx_delete_texture(mapi->tx);
	mapi->tx = mlx_load_png("assets/portal_4.png");
	mapi->portal_img_4 = mlx_texture_to_image(mapi->mlx, mapi->tx);
	mlx_delete_texture(mapi->tx);
	mapi->tx = mlx_load_png("assets/portal_5.png");
	mapi->portal_img_5 = mlx_texture_to_image(mapi->mlx, mapi->tx);
	mlx_delete_texture(mapi->tx);
}

void	load_tx_enemy(t_struct *mapi)
{
	mapi->tx = mlx_load_png("assets/reaper_1.png");
	mapi->enemy_img_1 = mlx_texture_to_image(mapi->mlx, mapi->tx);
	mlx_delete_texture(mapi->tx);
	mapi->tx = mlx_load_png("assets/reaper_2.png");
	mapi->enemy_img_2 = mlx_texture_to_image(mapi->mlx, mapi->tx);
	mlx_delete_texture(mapi->tx);
	mapi->tx = mlx_load_png("assets/reaper_3.png");
	mapi->enemy_img_3 = mlx_texture_to_image(mapi->mlx, mapi->tx);
	mlx_delete_texture(mapi->tx);
}
