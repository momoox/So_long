/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:17:49 by mgeisler          #+#    #+#             */
/*   Updated: 2023/07/16 18:20:39 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_portal(t_struct *mapi)
{
	if (mapi->portal_frame == 1)
		mlx_image_to_window(mapi->mlx, mapi->portal_img_1, mapi->portal_x * 64,
			mapi->portal_y * 64);
	if (mapi->portal_frame == 2)
		mlx_image_to_window(mapi->mlx, mapi->portal_img_2, mapi->portal_x * 64,
			mapi->portal_y * 64);
	if (mapi->portal_frame == 3)
		mlx_image_to_window(mapi->mlx, mapi->portal_img_3, mapi->portal_x * 64,
			mapi->portal_y * 64);
	if (mapi->portal_frame == 4)
		mlx_image_to_window(mapi->mlx, mapi->portal_img_4, mapi->portal_x * 64,
			mapi->portal_y * 64);
	if (mapi->portal_frame == 5)
		mlx_image_to_window(mapi->mlx, mapi->portal_img_5, mapi->portal_x * 64,
			mapi->portal_y * 64);
	if (mapi->portal_frame == 6)
		mlx_image_to_window(mapi->mlx, mapi->portal_img_1, mapi->portal_x * 64,
			mapi->portal_y * 64);
	if (mapi->portal_frame == 7)
		mlx_image_to_window(mapi->mlx, mapi->portal_img_2, mapi->portal_x * 64,
			mapi->portal_y * 64);
	if (mapi->portal_frame == 8)
		mlx_image_to_window(mapi->mlx, mapi->portal_img_3, mapi->portal_x * 64,
			mapi->portal_y * 64);
	mapi->portal_frame++;
}

void	render_player(t_struct *mapi)
{
	if (mapi->player_frame == 1)
		mlx_image_to_window(mapi->mlx, mapi->player_img_1, mapi->player_x * 64,
			mapi->player_y * 64);
	if (mapi->player_frame == 2)
		mlx_image_to_window(mapi->mlx, mapi->player_img_2, mapi->player_x * 64,
			mapi->player_y * 64);
	mapi->player_frame++;
}

void	portal_anim(void *param)
{
	t_struct	*mapi;

	mapi = param;
	if (mapi->collectible == 0)
	{
		while (mapi->frame_1-- >= 0)
			return ;
		mapi->frame_1 = 12;
		if (mapi->portal_frame > 8)
			mapi->portal_frame = 1;
		render_portal(mapi);
	}
}

void	player_anim(void *param)
{
	t_struct	*mapi;

	mapi = param;
	while (mapi->frame-- >= 0)
		return ;
	mapi->frame = 14;
	if (mapi->player_frame > 2)
		mapi->player_frame = 1;
	render_player(mapi);
}
