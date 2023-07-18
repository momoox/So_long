/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:41:05 by mgeisler          #+#    #+#             */
/*   Updated: 2023/07/12 22:11:17 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pos_portal(t_struct *mapi)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (mapi->map[y])
	{
		x = 0;
		while (mapi->map[y][x])
		{
			if (mapi->map[y][x] == 'E')
			{
				mapi->portal_x = x;
				mapi->portal_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	pos_enemy(t_struct *mapi)
{
	int	x;
	int	y;
	int	l;

	x = -1;
	y = -1;
	l = 0;
	mapi->enemy_pos = malloc(sizeof(int *) * mapi->enemy);
	while (mapi->map[++y])
	{
		x = 0;
		while (mapi->map[y][++x])
		{
			if (mapi->map[y][x] == 'Z')
			{
				mapi->enemy_pos[l] = malloc(sizeof(int) * 2);
				if (!mapi->enemy_pos[l])
					return ;
				mapi->enemy_pos[l][0] = x;
				mapi->enemy_pos[l][1] = y;
				l++;
			}
		}
	}
}
