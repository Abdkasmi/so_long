/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkasmi <abkasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:00:04 by abkasmi           #+#    #+#             */
/*   Updated: 2022/03/27 13:00:15 by abkasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	*init_size_window(t_character *coord)
{
	int		j;
	int		i;
	void	*win;

	j = 0;
	i = 0;
	while (coord->mp[0][j])
		j++;
	coord->x = j - 1;
	win = mlx_new_window(coord->mlx, coord->x * 24, coord->y * 24, "so_long");
	if (!win)
		error(coord, NULL);
	return (win);
}

void	convert_img(void *mlx, t_character *map)
{
	int	measure;

	measure = 24;
	map->player = mlx_xpm_file_to_image(mlx, PLAYER, &measure, &measure);
	map->wall = mlx_xpm_file_to_image(mlx, WALL, &measure, &measure);
	map->collec = mlx_xpm_file_to_image(mlx, COLLECTIBLE, &measure, &measure);
	map->e_close = mlx_xpm_file_to_image(mlx, E_CLOSE, &measure, &measure);
	map->e_open = mlx_xpm_file_to_image(mlx, E_OPEN, &measure, &measure);
	map->space = mlx_xpm_file_to_image(mlx, SPACE, &measure, &measure);
}

void	replace_with_image(t_character *use, int i, int j, int m)
{
	if (use->mp[i][j] == '1')
		mlx_put_image_to_window(use->mlx, use->win, use->wall, j * m, i * m);
	else if (use->mp[i][j] == '0')
		mlx_put_image_to_window(use->mlx, use->win, use->space, j * m, i * m);
	else if (use->mp[i][j] == 'C')
	{
		mlx_put_image_to_window(use->mlx, use->win, use->space, j * m, i * m);
		mlx_put_image_to_window(use->mlx, use->win,
			use->collec, j * 24, i * 24);
		use->c++;
	}
	else if (use->mp[i][j] == 'P')
	{
		mlx_put_image_to_window(use->mlx, use->win, use->space, j * m, i * m);
		mlx_put_image_to_window(use->mlx, use->win, use->player, j * m, i * m);
	}
	else if (use->mp[i][j] == 'E')
	{
		mlx_put_image_to_window(use->mlx, use->win, use->e_close,
			j * m, i * m);
		use->e++;
	}
}

void	put_image(t_character *used)
{
	int	i;
	int	j;

	convert_img(used->mlx, used);
	used->c = 0;
	used->e = 0;
	i = -1;
	while (++i < used->y)
	{
		j = -1;
		while (++j < used->x)
			replace_with_image(used, i, j, 24);
	}
}
