/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkasmi <abkasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:43:58 by abkasmi           #+#    #+#             */
/*   Updated: 2022/03/27 15:43:49 by abkasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"

typedef struct s_characters {
	int		p;
	int		e;
	int		c;
	int		x;
	int		y;
	int		count;
	int		player_x;
	int		player_y;
	void	*player;
	void	*wall;
	void	*collec;
	void	*e_close;
	void	*e_open;
	void	*space;
	void	*mlx;
	void	*win;
	char	**mp;
	char	**full_map;
}	t_character;

# define PLAYER "graphic/oryx_16bit_scifi_creatures_1224.xpm"
# define WALL "graphic/oryx_16bit_scifi_world_35.xpm"
# define COLLECTIBLE "graphic/oryx_16bit_scifi_items_83.xpm"
# define E_CLOSE "graphic/oryx_16bit_scifi_world_79.xpm"
# define E_OPEN "graphic/oryx_16bit_scifi_world_78.xpm"
# define SPACE "graphic/oryx_16bit_scifi_world_832.xpm"
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define LEFT 123
# define DOWN 125
# define RIGHT 124
# define ESC 53
# define QUIT 17

void	check_walls(char **map, t_character *mandatory, int line, int i);
void	check_if_contain(t_character *mandatory, int i, char **map);
void	*init_size_window(t_character *coord);
void	convert_img(void *mlx, t_character *map);
void	put_image(t_character *used);
void	check_mandatory(char c, t_character *coord, char **map, int i);
void	replace_with_image(t_character *use, int i, int j, int m);
void	coordo(t_character *coord);
void	player_pos(t_character *pos);
void	ft_move_up(t_character *mandatory);
void	ft_move_left(t_character *coord);
void	ft_move_down(t_character *coord);
void	ft_move_right(t_character *coord);
void	print_decimal(long long value);
void	print_char(char value);
void	check_move(t_character *coord);
void	exit_map(t_character *coord);
void	free_exit(char **map, int i, t_character *mandatory);

char	*get_next_line(int fd);
char	**ft_parsing(char *map, t_character *mandatory);

int		error(t_character *map, char *full_map);
int		error2(t_character *map, char *full_map);
int		check_inside(t_character *mandatory, int line, int i);
int		check_map_file(char *map);
int		line_in_map(char *map, t_character *coord);
int		hook(int keycode, t_character *mandatory);
int		free_and_close(t_character *mandatory);

#endif