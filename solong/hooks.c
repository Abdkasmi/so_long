/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkasmi <abkasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:53:41 by abkasmi           #+#    #+#             */
/*   Updated: 2022/03/27 15:51:06 by abkasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	player_pos(t_character *pos)
{
	int	x;
	int	y;

	y = -1;
	pos->player_x = 0;
	pos->player_y = 0;
	while (++y < pos->y)
	{
		x = -1;
		while (++x < pos->x)
		{
			if (pos->mp[y][x] == 'P')
			{
				pos->player_x = x;
				pos->player_y = y;
				break ;
			}
		}
	}
}

int	free_and_close(t_character *mandatory)
{
	int	i;

	i = mandatory->y - 1;
	mlx_destroy_window(mandatory->mlx, mandatory->win);
	write (1, "Thanks for playing !\n", 22);
	if (mandatory->mp)
	{
		while (i >= 0)
		{
			free(mandatory->mp[i]);
			i--;
		}
		free(mandatory->mp);
	}
	if (mandatory)
		free(mandatory);
	exit (0);
}

int	hook(int keycode, t_character *mandatory)
{
	if (keycode == ESC)
		free_and_close(mandatory);
	else if (keycode == W || keycode == UP)
		ft_move_up(mandatory);
	else if (keycode == A || keycode == LEFT)
		ft_move_left(mandatory);
	else if (keycode == S || keycode == DOWN)
		ft_move_down(mandatory);
	else if (keycode == D || keycode == RIGHT)
		ft_move_right(mandatory);
	return (0);
}
