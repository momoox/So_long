/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playable_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:42:05 by mgeisler          #+#    #+#             */
/*   Updated: 2023/07/11 19:32:51 by mgeisler         ###   ########.fr       */
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
			if (mapi->map[y][x] == 'Z')
				mapi->enemy += 1;
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
		return (write(1, "Error: Wrong number of exit (only one needed)\n",
				46));
	else
		return (0);
}

t_struct	*temp_struct(t_struct *mapi)
{
	t_struct	*temp;
	int			y;

	y = -1;
	temp = malloc(sizeof(t_struct));
	temp->map = malloc(sizeof(char *) * (mapi->width + 1));
	while (mapi->map[++y])
		temp->map[y] = ft_strdup(mapi->map[y]);
	temp->length = mapi->length;
	temp->width = mapi->width;
	temp->player = mapi->player;
	temp->collectible = mapi->collectible + 1;
	return (temp);
}

int	valid_way(t_struct *temp, int x, int y)
{
	if (temp->map[y][x] == '1' || temp->map[y][x] == 'Z')
		return (0);
	if (temp->map[y][x] == 'C' || temp->map[y][x] == 'E')
		temp->collectible--;
	temp->map[y][x] = '1';
	valid_way(temp, (x + 1), y);
	valid_way(temp, (x - 1), y);
	valid_way(temp, x, (y + 1));
	valid_way(temp, x, (y - 1));
	if (!temp->collectible)
		return (1);
	return (0);
}
