/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:12:44 by mgeisler          #+#    #+#             */
/*   Updated: 2023/07/18 15:25:09 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end(int i)
{
	if (i == 1)
	{
		write(1, "\n", 1);
		write(1, "~~~~~~~~~~\n", 11);
		write(1, "Game exit.\n", 11);
		write(1, "~~~~~~~~~~\n", 11);
	}
	if (i == 2)
	{
		write(1, "\n", 1);
		write(1, "~~~~~~~~~~~~\n", 13);
		write(1, "Game over :(\n", 13);
		write(1, "~~~~~~~~~~~~\n", 13);
	}
	if (i == 3)
	{
		write(1, "\n", 1);
		write(1, "~~~~~~~~~\n", 10);
		write(1, "You won !\n", 10);
		write(1, "~~~~~~~~~\n", 10);
	}
}

void	display_move(t_struct *mapi)
{
	char	*move;

	mlx_delete_image(mapi->mlx, mapi->steps_img);
	move = ft_itoa(mapi->steps);
	mapi->steps_img = mlx_put_string(mapi->mlx, move, 0 * 64, 0 * 64);
	free(move);
}

int	canmove(t_struct *mapi, int x, int y)
{
	if (mapi->map[y][x] == '1')
		return (0);
	if (mapi->map[y][x] == 'Z')
	{
		end(2);
		exit(0);
	}
	if (mapi->map[y][x] == 'E' && mapi->collectible == 0)
	{
		end(3);
		exit(0);
	}
	if (mapi->map[y][x] == 'C')
	{
		mapi->collectible--;
		mlx_image_to_window(mapi->mlx, mapi->floor_img, x * 64, y * 64);
		mapi->map[y][x] = '0';
	}
	display_move(mapi);
	ft_putnbr(++mapi->steps);
	write(1, "\n", 1);
	return (1);
}

void	keyb_2(mlx_key_data_t keydata, void *param)
{
	t_struct	*mapi;

	(void) keydata;
	mapi = param;
	if (mlx_is_key_down(mapi->mlx, MLX_KEY_W)
		&& canmove(mapi, mapi->player_x, mapi->player_y - 1) == 1)
	{
		mlx_image_to_window(mapi->mlx, mapi->floor_img,
			mapi->player_x * 64, mapi->player_y * 64);
		mapi->player_y -= 1;
	}
	if (mlx_is_key_down(mapi->mlx, MLX_KEY_S)
		&& canmove(mapi, mapi->player_x, mapi->player_y + 1) == 1)
	{
		mlx_image_to_window(mapi->mlx, mapi->floor_img,
			mapi->player_x * 64, mapi->player_y * 64);
		mapi->player_y += 1;
	}
}

void	keyb(mlx_key_data_t keydata, void *param)
{
	t_struct	*mapi;

	(void)keydata;
	mapi = param;
	if (mlx_is_key_down(mapi-> mlx, MLX_KEY_ESCAPE))
	{
		end(1);
		free_all(mapi);
		exit(0);
	}
	if (mlx_is_key_down(mapi->mlx, MLX_KEY_A)
		&& canmove(mapi, mapi->player_x - 1, mapi->player_y) == 1)
	{
		mlx_image_to_window(mapi->mlx, mapi->floor_img,
			mapi->player_x * 64, mapi->player_y * 64);
		mapi->player_x -= 1;
	}
	if (mlx_is_key_down(mapi->mlx, MLX_KEY_D)
		&& canmove(mapi, mapi->player_x + 1, mapi->player_y) == 1)
	{
		mlx_image_to_window(mapi->mlx, mapi->floor_img,
			mapi->player_x * 64, mapi->player_y * 64);
		mapi->player_x += 1;
	}
	keyb_2(keydata, param);
}
