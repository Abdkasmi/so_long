/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkasmi <abkasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:14:15 by abkasmi           #+#    #+#             */
/*   Updated: 2022/03/27 15:25:57 by abkasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	free_exit(char **map, int i, t_character *mandatory)
{
	if (map)
	{
		while (i >= 0)
		{
			free(map[i]);
			i--;
		}
		free(map);
	}
	error(mandatory, NULL);
}

int	line_in_map(char *map, t_character *coord)
{
	char	*full_map;
	int		fd;
	int		count;

	(void)coord;
	fd = open(map, O_RDONLY);
	full_map = get_next_line(fd);
	if (!full_map)
		error2(coord, NULL);
	count = 1;
	while (full_map)
	{
		free(full_map);
		full_map = get_next_line(fd);
		count++;
		coord->y++;
	}
	free(full_map);
	close(fd);
	return (count - 1);
}

char	**ft_parsing(char *map, t_character *mand)
{
	int			line;
	int			fd;
	int			i;

	line = line_in_map(map, mand);
	mand->full_map = malloc(sizeof(char *) * line + 1);
	fd = open(map, O_RDONLY);
	mand->full_map[0] = get_next_line(fd);
	if (!mand->full_map[0])
		error2(mand, NULL);
	i = 0;
	check_walls(mand->full_map, mand, ft_strlen(mand->full_map[0]) - 1, i);
	while (++i < line - 1)
	{
		mand->full_map[i] = get_next_line(fd);
		if (check_inside(mand, ft_strlen(mand->full_map[0]) - 1, i))
			free_exit(mand->full_map, i, mand);
	}
	mand->full_map[i] = get_next_line(fd);
	check_walls(mand->full_map, mand, ft_strlen(mand->full_map[0]) - 1, i);
	check_if_contain(mand, i, mand->full_map);
	close(fd);
	return (mand->full_map);
}
