/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:24:16 by mgeisler          #+#    #+#             */
/*   Updated: 2023/07/18 15:23:28 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_map(t_struct *mapi, char *file)
{
	int		fd;
	char	*str;
	char	*tempo;
	int		i;

	fd = open(file, O_RDONLY);
	i = ft_strlen(file) - 1;
	if (!(file[i] == 'r' && file[i - 1] == 'e' && file[i - 2] == 'b'
			&& file[i - 3] == '.'))
		write(1, "Error: Wrong file type\n", 24);
	str = get_next_line(fd);
	tempo = get_next_line(fd);
	while (tempo)
	{
		str = ft_strjoin(str, tempo);
		tempo = get_next_line(fd);
	}
	mapi->map = ft_split(str, '\n');
	close(fd);
	free(str);
	return (0);
}
