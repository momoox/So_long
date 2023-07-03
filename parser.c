/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:25:57 by mgeisler          #+#    #+#             */
/*   Updated: 2023/07/03 21:02:20 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parser(t_struct *mapi)
{
	if (valid_map(mapi) > '0' || map_closed(mapi) > '0' 
		|| check_content(mapi) > '0')
		return (1);
	pos_player(mapi);
	return (0);
}
