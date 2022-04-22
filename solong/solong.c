/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkasmi <abkasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:43:16 by abkasmi           #+#    #+#             */
/*   Updated: 2022/03/27 15:42:01 by abkasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int ac, char *av[])
{
	t_character	*mandatory;

	mandatory = malloc(sizeof(t_character));
	mandatory->p = 0;
	mandatory->c = 0;
	mandatory->e = 0;
	mandatory->y = 0;
	mandatory->x = 0;
	mandatory->count = 0;
	if (ac != 2 || check_map_file(av[1]))
		error(mandatory, NULL);
	mandatory->mp = ft_parsing(av[1], mandatory);
	mandatory->mlx = mlx_init();
	mandatory->win = init_size_window(mandatory);
	put_image(mandatory);
	player_pos(mandatory);
	mlx_key_hook(mandatory->win, hook, mandatory);
	mlx_hook(mandatory->win, QUIT, 0, free_and_close, mandatory);
	mlx_loop(mandatory->mlx);
	return (0);
}
