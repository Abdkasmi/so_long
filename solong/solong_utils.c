/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkasmi <abkasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:01:36 by abkasmi           #+#    #+#             */
/*   Updated: 2022/03/27 15:51:03 by abkasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	error(t_character *map, char *full_map)
{
	write(1, "Error\nMap not recognized.\n", 27);
	if (full_map)
		free(full_map);
	if (map->mp)
		free(map->mp);
	if (map)
		free(map);
	exit(0);
}

int	error2(t_character *map, char *full_map)
{
	write(1, "Error\nNothing to read, pls set a correct map.\n", 47);
	if (full_map)
		free(full_map);
	if (map->mp)
		free(map->mp);
	if (map)
		free(map);
	exit(0);
}

void	exit_map(t_character *coord)
{
	if (coord->mp[coord->player_y][coord->player_x] == 'e')
		free_and_close(coord);
}

void	print_char(char value)
{
	write (1, &value, 1);
}

void	print_decimal(long long value)
{
	if (value < 0)
	{
		write(1, "-", 1);
		print_decimal(value * (-1));
	}
	else if (value > 9)
	{
		print_decimal(value / 10);
		print_decimal(value % 10);
	}
	else
	{
		print_char(48 + value);
	}
}
