/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playable_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:42:05 by mgeisler          #+#    #+#             */
/*   Updated: 2023/07/03 21:11:02 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_content(t_struct *mapi)
{
	int	y;
	int	x;

	y = 0;
	while (mapi->map[y])
	{
		x = 0;
		while (mapi->map[y][x])
		{
			if (mapi->map[y][x] == 'P')
				mapi->player += 1;
			if (mapi->map[y][x] == 'C')
				mapi->collectible += 1;
			if (mapi->map[y][x] == 'E')
				mapi->exit += 1;
			// if (mapi->map[y][x] = 'A')
			// 	mapi->ennemies += 1;
			x++;
		}
		y++;
	}
}

void	pos_player(t_struct *mapi)
{
	int	y;
	int	x;

	y = 0;
	while (mapi->map[y])
	{
		x = 0;
		while (mapi->map[y][x])
		{
			if (mapi->map[y][x] == 'P')
			{
				mapi->player_x = x;
				mapi->player_y = y;
			}
			x++;
		}
		y++;
	}
}

int	check_content(t_struct *mapi)
{
	map_content(mapi);
	if (mapi->player != 1)
		return (write(1, "Error: Wrong number of player (only one)\n", 41));
	else if (mapi->collectible < 1)
		return (write(1, "Error: Not enough collectible (one minimum)\n", 44));
	else if (mapi->exit != 1)
		return (write(1, "Error: Wrong number of exit (only one needed)\n", 46));
	else
		return (0);
}

// void	fill(t_struct *mapi, length & width, pos player, char pour remplacer 0)
// {
// 	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
// 		|| tab[cur.y][cur.x] != to_fill)
// 		return;

// 	tab[cur.y][cur.x] = 'F';
// 	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
// 	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
// 	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
// 	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
// }

// void	flood_fill(char **tab, t_point size, t_point begin)
// {
// 	fill(tab, size, begin, tab[begin.y][begin.x]);
// }
