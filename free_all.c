/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:17:57 by mgeisler          #+#    #+#             */
/*   Updated: 2023/07/18 15:21:24 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_maps(t_struct *mapi)
{
	int	i;

	i = -1;
	while (++i < mapi->width)
	{
		free(mapi->map[i]);
	}
	i = 0;
	while (i < mapi->enemy)
	{
		free(mapi->enemy_pos[i]);
		i++;
	}
}

void	free_all(t_struct *mapi)
{
	if (mapi->tx_loaded)
	{
		mlx_delete_image(mapi->mlx, mapi->player_img_1);
		mlx_delete_image(mapi->mlx, mapi->player_img_2);
		mlx_delete_image(mapi->mlx, mapi->enemy_img_1);
		mlx_delete_image(mapi->mlx, mapi->enemy_img_2);
		mlx_delete_image(mapi->mlx, mapi->enemy_img_3);
		mlx_delete_image(mapi->mlx, mapi->portal_img_1);
		mlx_delete_image(mapi->mlx, mapi->portal_img_2);
		mlx_delete_image(mapi->mlx, mapi->portal_img_3);
		mlx_delete_image(mapi->mlx, mapi->portal_img_4);
		mlx_delete_image(mapi->mlx, mapi->portal_img_5);
		mlx_delete_image(mapi->mlx, mapi->collectible_img);
		mlx_delete_image(mapi->mlx, mapi->floor_img);
		mlx_delete_image(mapi->mlx, mapi->wall_img);
		free_maps(mapi);
	}
}
