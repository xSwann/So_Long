/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slatrech <slatrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:51:27 by slatrech          #+#    #+#             */
/*   Updated: 2025/04/29 14:58:17 by slatrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	set_player_start_position_and_score(t_game *game)
{
	t_list	*tmp;
	int		y;
	int		x;

	y = 0;
	tmp = game->map;
	while (tmp)
	{
		x = 0;
		while (tmp->line[x])
		{
			if (tmp->line[x] == 'C')
				game->score_to_reach++;
			if (tmp->line[x] == 'P')
			{
				game->player_x = x * TILE_SIZE;
				game->player_y = y * TILE_SIZE;
			}
			x++;
		}
		y++;
		tmp = tmp->next;
	}
}

void	init_game(t_game *game, t_list *map)
{
	game->mlx = mlx_init();
	game->win = NULL;
	game->map = map;
	game->score = 0;
	game->score_to_reach = 0;
	game->mooves = 0;
	set_player_start_position_and_score(game);
}

char	get_tile_at(t_list *map, int y, int x)
{
	int	i;

	i = 0;
	while (i < y && map)
	{
		map = map->next;
		i++;
	}
	if (!map || x >= (int)ft_strlen(map->line))
		return ('\0');
	return (map->line[x]);
}

void	change_coll_to_bg(t_list *map, int y, int x)
{
	int	i;

	i = 0;
	while (i < y && map)
	{
		map = map->next;
		i++;
	}
	map->line[x] = '0';
}
