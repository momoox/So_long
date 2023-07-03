/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 18:02:50 by mgeisler          #+#    #+#             */
/*   Updated: 2023/07/03 19:36:10 by mgeisler         ###   ########.fr       */
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

	y = -1;
	x = -1;
	while (mapi->map[++y])
		if (mapi->map[y][0] != '1')
			return (write(1, "Error: Map isn't closed\n", 24));
	y = -1;
	while (mapi->map[++y])
		if (mapi->map[y][mapi->length - 1] != '1')
			return (write(1, "Error: Map isn't closed\n", 24));
	while (mapi->map[0][++x])
		if (mapi->map[0][x] != '1')
			return (write(1, "Error: Map isn't closed\n", 24));
	x = -1;
	while (mapi->map[mapi->width - 1][++x])
		if (mapi->map[mapi->width - 1][x] != '1')
			return (write(1, "Error: Map isn't closed\n", 24));
	return (0);
}

int	valid_map(t_struct *mapi)
{
	map_size(mapi);
	if (mapi->length <= mapi->width)
		return (write(1, "Error: Map isn't rectangle\n", 27));
	else
		return (0);
}
