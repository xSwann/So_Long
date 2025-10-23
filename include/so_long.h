/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slatrech <slatrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:07:23 by slatrech          #+#    #+#             */
/*   Updated: 2025/05/01 13:52:54 by slatrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 60

/* INCLUDES */
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include "include/so_long.h"
# include "get_next_line/get_next_line.h"
# include "src/ft_printf/ft_printf.h"

/* STRUCTURES */

// map
typedef struct s_list
{
	char			*line;
	struct s_list	*next;
}	t_list;

// game
typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_bg;
	void	*img_wall;
	void	*img_coll;
	void	*img_player;
	void	*img_exit;
	int		player_x;
	int		player_y;
	int		width;
	int		height;
	int		score;
	int		score_to_reach;
	int		mooves;
	t_list	*map;
}	t_game;

// count
typedef struct s_counts
{
	int	c_count;
	int	e_count;
}	t_counts;
// x and y
typedef struct s_x_and_y
{
	int	x;
	int	y;
}	t_x_and_y;
// data
typedef struct s_flood_data
{
	char		**map;
	char		**visited;
	t_counts	*counts;
}	t_flood_data;
// clean
typedef struct s_cleanup_data
{
	char		**visited;
	char		**tab_map;
	t_counts	*counts;
	t_x_and_y	*pos;
}	t_cleanup_data;

/* PROTOTYPES */

void	is_map_name_valid(char *map_name);
int		is_line_valid(char *line);
t_list	*create_node(char *line);
t_list	*read_map(char *map_name);
void	add_back(t_list **list, t_list *new_node);
int		list_size(t_list *list);
void	free_list(t_list *list);
void	print_list(t_list *list);
char	*remove_n(char *map_line);
void	is_map_valid(t_list *map);
void	create_map(t_game *game, t_list *map);
void	init_game(t_game *game, t_list *map);
void	start_game(t_game *game);
int		key_hook(int keycode, t_game *game);
void	draw_map(t_game *game);
void	clean_exit(t_game *game, int status);
void	free_map(t_list *map);
int		close_window(t_game *game);
void	flood_fill(int x, int y, t_flood_data *data);
char	**put_list_in_tabs(t_list *map, int is_map);
void	initialise(t_list *map);
char	get_tile_at(t_list *map, int y, int x);
void	change_coll_to_bg(t_list *map, int y, int x);
void	fill_tab(t_list *tmp_map, char **tab_map, int is_map, int i);
void	free_all(char **visited, char **tab_map, t_counts *counts,
			t_x_and_y *x_and_y);
int		find_c_count(char **tab_map);
void	find_start_position(char **tab_map,
			int *start_position_x, int *start_position_y);
void	move_handler(t_game *game, int keycode);

#endif
