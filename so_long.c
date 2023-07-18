/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:52:31 by mgeisler          #+#    #+#             */
/*   Updated: 2023/07/17 16:21:46 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_struct	*mapi;
	int			fd;
	char		test[1];

	if (argc != 2)
		return (write(1, "Error: No file\n", 15));
	mapi = malloc(sizeof(t_struct));
	if (!mapi)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || read(fd, test, 1) <= 0)
		return (write(1, "Error: File empty\n", 18));
	close(fd);
	if (init_map(mapi, argv[1]) != 0)
		return (0);
	init_struct(mapi);
	if (parser(mapi) != 0)
	{
		free_all(mapi);
		exit(0);
	}
	render_init(mapi);
	mlx_terminate(mapi->mlx);
	free_all(mapi);
	exit(0);
}
