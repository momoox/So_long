/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:24:16 by mgeisler          #+#    #+#             */
/*   Updated: 2023/07/02 18:02:10 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

	//while gnl != NULL
	//str = gnl;
	//struct->map[i] = join str map

void	init_map(t_struct *mapi, char *file)
{
	int		fd;
	char	*str;
	char	*tempo;

	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	tempo = get_next_line(fd);
	while (tempo)
	{
		str = ft_strjoin(str, tempo);
		tempo = get_next_line(fd);
	}
	mapi->map = ft_split(str, '\n');
	return (close(fd), free(str));
}