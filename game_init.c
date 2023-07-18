/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:55:34 by mgeisler          #+#    #+#             */
/*   Updated: 2023/07/15 17:49:42 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_init(t_struct *mapi)
{
	pos_portal(mapi);
	pos_enemy(mapi);
	mapi->mlx = mlx_init(mapi->length * 64, mapi->width * 64, "so_long", true);
	render_map(mapi);
	mlx_loop_hook(mapi->mlx, &player_anim, mapi);
	mlx_loop_hook(mapi->mlx, &enemy_anim, mapi);
	mlx_loop_hook(mapi->mlx, &portal_anim, mapi);
	mlx_key_hook(mapi->mlx, &keyb, mapi);
	mlx_loop(mapi->mlx);
}
