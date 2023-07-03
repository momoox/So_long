/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:16:25 by mgeisler          #+#    #+#             */
/*   Updated: 2023/07/03 19:34:28 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	init_struct(t_struct *mapi)
{
	mapi->length = 0;
	mapi->width = 0;
	mapi->player = 0;
	mapi->collectible = 0;
	mapi->exit = 0;
	//mapi->ennemies = 0;
}
