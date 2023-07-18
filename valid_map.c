/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 18:02:50 by mgeisler          #+#    #+#             */
/*   Updated: 2023/07/18 15:26:19 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_size(t_struct *mapi)
{
	char	**tempo;
	int		i;

	i = 0;
	tempo = mapi->map;
	while (tempo[i])
	{
		i++;
		mapi->width += 1;
	}
	tempo = mapi->map;
	i = 0;
	while (tempo[1][i])
	{
		i++;
		mapi->length += 1;
	}
}

int	map_closed(t_struct *mapi)
{
	int		y;
	int		x;

	y = 0;
	x = -1;
	if (mapi->width > 25 || mapi->length > 35)
		return (write(1, "Error: Map is too big\n", 22));
	while (mapi->map[0][++x])
		if (mapi->map[0][x] != '1')
			return (write(1, "Error: Map isn't closed\n", 24));
	x = -1;
	while (mapi->map[mapi->width - 1][++x])
		if (mapi->map[mapi->width - 1][x] != '1')
			return (write(1, "Error: Map isn't closed\n", 24));
	while (mapi->map[++y])
		if (mapi->map[y][0] != '1' || mapi->map[y][mapi->length - 1] != '1')
			return (write(1, "Error: Map isn't closed\n", 24));
	return (0);
}

int	valid_map(t_struct *mapi)
{
	int	y;
	int	x;

	y = 0;
	while (mapi->map[y])
	{
		x = 0;
		while (mapi->map[y][x])
		{
			if (mapi->map[y][x] != 'P' && mapi->map[y][x] != 'E'
				&& mapi->map[y][x] != '0' && mapi->map[y][x] != '1'
				&& mapi->map[y][x] != 'C' && mapi->map[y][x] != 'Z')
				return (write(1, "Error: Wrong map settings\n", 26));
			x++;
		}
		y++;
	}
	map_size(mapi);
	return (0);
}

int	long_line(t_struct *mapi)
{
	int	i;

	i = 0;
	while (mapi->map[i])
	{
		if (ft_strlen(mapi->map[1]) != ft_strlen(mapi->map[i]))
			return (write(1, "Error: Line too long.\n", 22));
		i++;
	}
	return (0);
}
