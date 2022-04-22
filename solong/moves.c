/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkasmi <abkasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:58:43 by abkasmi           #+#    #+#             */
/*   Updated: 2022/03/27 12:15:31 by abkasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	check_move(t_character *coord)
{
	int	x;
	int	y;

	y = -1;
	if (coord->mp[coord->player_y][coord->player_x] == 'C')
	{
		coord->c--;
		coord->mp[coord->player_y][coord->player_x] = '0';
	}
	while (++y < coord->y && coord->c == 0)
	{
		x = -1;
		while (++x < coord->x)
		{
			if (coord->mp[y][x] == 'E')
			{
				mlx_put_image_to_window(coord->mlx, coord->win,
					coord->space, x * 24, y * 24);
				mlx_put_image_to_window(coord->mlx, coord->win,
					coord->e_open, x * 24, y * 24);
				coord->mp[y][x] = 'e';
			}
		}
	}
	exit_map(coord);
}

void	ft_move_up(t_character *coord)
{
	char	wall;
	char	exit;

	wall = coord->mp[coord->player_y - 1][coord->player_x];
	exit = coord->mp[coord->player_y - 1][coord->player_x];
	if (wall != '1' && exit != 'E')
	{
		mlx_put_image_to_window(coord->mlx, coord->win, coord->space,
			coord->player_x * 24, coord->player_y * 24);
		coord->player_y--;
		mlx_put_image_to_window(coord->mlx, coord->win, coord->player,
			coord->player_x * 24, coord->player_y * 24);
		coord->count++;
		print_decimal(coord->count);
		write(1, "\n", 1);
	}
	check_move(coord);
}

void	ft_move_left(t_character *coord)
{
	char	wall;
	char	exit;

	wall = coord->mp[coord->player_y][coord->player_x - 1];
	exit = coord->mp[coord->player_y][coord->player_x - 1];
	if (wall != '1' && exit != 'E')
	{
		mlx_put_image_to_window(coord->mlx, coord->win, coord->space,
			coord->player_x * 24, coord->player_y * 24);
		coord->player_x--;
		mlx_put_image_to_window(coord->mlx, coord->win, coord->player,
			coord->player_x * 24, coord->player_y * 24);
		coord->count++;
		print_decimal(coord->count);
		write(1, "\n", 1);
	}
	check_move(coord);
}

void	ft_move_down(t_character *coord)
{
	char	wall;
	char	exit;

	wall = coord->mp[coord->player_y + 1][coord->player_x];
	exit = coord->mp[coord->player_y + 1][coord->player_x];
	if (wall != '1' && exit != 'E')
	{
		mlx_put_image_to_window(coord->mlx, coord->win, coord->space,
			coord->player_x * 24, coord->player_y * 24);
		coord->player_y++;
		mlx_put_image_to_window(coord->mlx, coord->win, coord->player,
			coord->player_x * 24, coord->player_y * 24);
		coord->count++;
		print_decimal(coord->count);
		write(1, "\n", 1);
	}
	check_move(coord);
}

void	ft_move_right(t_character *coord)
{
	char	wall;
	char	exit;

	wall = coord->mp[coord->player_y][coord->player_x + 1];
	exit = coord->mp[coord->player_y][coord->player_x + 1];
	if (wall != '1' && exit != 'E')
	{
		mlx_put_image_to_window(coord->mlx, coord->win, coord->space,
			coord->player_x * 24, coord->player_y * 24);
		coord->player_x++;
		mlx_put_image_to_window(coord->mlx, coord->win, coord->player,
			coord->player_x * 24, coord->player_y * 24);
		coord->count++;
		print_decimal(coord->count);
		write(1, "\n", 1);
	}
	check_move(coord);
}
