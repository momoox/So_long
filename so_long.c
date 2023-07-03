/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:52:31 by mgeisler          #+#    #+#             */
/*   Updated: 2023/07/03 21:01:57 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_struct	*mapi;
	int			i;

	i = ft_strlen(argv[1]) - 1;
	if (argc != 2)
		return (write(1, "Error: No file\n", 15));
	if (!(argv[1][i] == 'r' && argv[1][i - 1] == 'e' && argv[1][i - 2] == 'b' 
			&& argv[1][i - 3] == '.'))
		write(1, "Error: Wrong file type\n", 24);
	mapi = malloc(sizeof(t_struct));
	init_map(mapi, argv[1]);
	init_struct(mapi);
	if (parser(mapi) != 0)
		return (1);
	//print_map(mapi);
	//printf("length: %d, width: %d\n", mapi->length, mapi->width);
	printf("fin du prog");
}




	// void	*mlx_ptr;

	// mlx_ptr = mlx_init(800, 600, "test", true);
	// mlx_loop(mlx_ptr);
	// free(mlx_ptr);