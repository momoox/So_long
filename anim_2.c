/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:58:27 by mgeisler          #+#    #+#             */
/*   Updated: 2023/07/16 18:20:55 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_enemy(t_struct *mapi)
{
	int	i;

	i = 0;
	while (i < mapi->enemy)
	{
		if (mapi->enemy_frame == 1)
			mlx_image_to_window(mapi->mlx, mapi->enemy_img_1,
				mapi->enemy_pos[i][0] * 64, mapi->enemy_pos[i][1] * 64);
		if (mapi->enemy_frame == 2)
			mlx_image_to_window(mapi->mlx, mapi->enemy_img_2,
				mapi->enemy_pos[i][0] * 64, mapi->enemy_pos[i][1] * 64);
		if (mapi->enemy_frame == 3)
			mlx_image_to_window(mapi->mlx, mapi->enemy_img_3,
				mapi->enemy_pos[i][0] * 64, mapi->enemy_pos[i][1] * 64);
		i++;
	}
	mapi->enemy_frame++;
}

void	enemy_anim(void *param)
{
	t_struct	*mapi;

	mapi = param;
	while (mapi->frame_2-- >= 0)
		return ;
	mapi->frame_2 = 20;
	if (mapi->enemy_frame > 3)
		mapi->enemy_frame = 1;
	render_enemy(mapi);
}
