/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:25:57 by mgeisler          #+#    #+#             */
/*   Updated: 2023/07/17 15:56:03 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parser(t_struct *mapi)
{
	if (valid_map(mapi) != 0 || long_line(mapi) != 0)
		return (1);
	else if (map_closed(mapi) != 0)
		return (1);
	else if (check_content(mapi) != 0)
		return (1);
	pos_player(mapi);
	if (valid_way(temp_struct(mapi),
			mapi->player_x, mapi->player_y) != 1)
		return (write(1, "Error: Impossible to finish level\n", 34));
	return (0);
}
