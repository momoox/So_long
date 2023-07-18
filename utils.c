/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:16:25 by mgeisler          #+#    #+#             */
/*   Updated: 2023/07/17 16:05:43 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_struct *mapi)
{
	mapi->length = 0;
	mapi->width = 0;
	mapi->player = 0;
	mapi->collectible = 0;
	mapi->exit = 0;
	mapi->enemy = 0;
	mapi->steps = 0;
	mapi->tx_loaded = 0;
	mapi->player_frame = 1;
	mapi->portal_frame = 1;
	mapi->enemy_frame = 1;
	mapi->frame = 14;
	mapi->frame_1 = 12;
	mapi->frame_2 = 20;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strlcpy(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(char *src)
{
	char	*dst;

	dst = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dst)
		return (0);
	ft_strlcpy(dst, src, ft_strlen(src) + 1);
	dst[ft_strlen(src)] = '\0';
	return (dst);
}
