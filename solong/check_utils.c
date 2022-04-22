/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkasmi <abkasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:25:51 by abkasmi           #+#    #+#             */
/*   Updated: 2022/03/27 14:59:23 by abkasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	check_walls(char **map, t_character *mandatory, int line, int i)
{
	int	j;
	int	len;

	j = -1;
	len = ft_strlen(map[i]) - 1;
	if (len != line)
		free_exit(map, i, mandatory);
	while (++j < len)
		if (map[i][j] != '1')
			free_exit(map, i, mandatory);
}

int	check_map_file(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	i--;
	if (map[i] != 'r')
		return (1);
	if (map[i - 1] != 'e')
		return (1);
	if (map[i - 2] != 'b')
		return (1);
	if (map[i - 3] != '.')
		return (1);
	return (0);
}

void	check_mandatory(char c, t_character *mandatory, char **map, int i)
{
	if (c == 'P' && mandatory->p)
		free_exit(map, i, mandatory);
	if (c == 'P' && !mandatory->p)
		mandatory->p = 1;
	else if (c == 'E')
		mandatory->e = 1;
	else if (c == 'C')
		mandatory->c = 1;
}

void	check_if_contain(t_character *mandatory, int i, char **map)
{
	if (!mandatory->c || !mandatory->p || !mandatory->e)
		free_exit(map, i, mandatory);
}

int	check_inside(t_character *mandatory, int line, int i)
{
	int	j;
	int	len;

	j = 0;
	len = ft_strlen(mandatory->full_map[i]) - 1;
	if (len != line)
		free_exit(mandatory->full_map, i, mandatory);
	if (mandatory->full_map[i][0] != '1'
		&& mandatory->full_map[i][len - 1] != '1')
		free_exit(mandatory->full_map, i, mandatory);
	while (++j < len)
	{
		if (mandatory->full_map[i][j] == '0' || mandatory->full_map[i][j] == '1'
			|| mandatory->full_map[i][j] == 'C'
			|| mandatory->full_map[i][j] == 'E'
			|| mandatory->full_map[i][j] == 'P')
			check_mandatory(mandatory->full_map[i][j], mandatory,
				mandatory->full_map, i);
		else
			return (1);
	}
	return (0);
}
