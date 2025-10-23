/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slatrech <slatrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:23:38 by slatrech          #+#    #+#             */
/*   Updated: 2025/04/29 14:58:52 by slatrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	draw_utils(t_list *tmp_map, int j, t_game *game)
{
	int	i;
	int	i_map;

	i = 0;
	i_map = 0;
	while (i < game->width * TILE_SIZE)
	{
		if (tmp_map->line[i_map] == '0' || tmp_map->line[i_map] == 'P')
			mlx_put_image_to_window(game->mlx, game->win, game->img_bg, i, j);
		else if (tmp_map->line[i_map] == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->img_wall, i, j);
		else if (tmp_map->line[i_map] == 'C')
			mlx_put_image_to_window(game->mlx, game->win, game->img_coll, i, j);
		else if (tmp_map->line[i_map] == 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->img_exit, i, j);
		i_map++;
		i += 60;
	}
}

void	draw_map(t_game *game)
{
	int		j;
	t_list	*tmp_map;

	j = 0;
	tmp_map = game->map;
	while (j < game->height * TILE_SIZE)
	{
		draw_utils(tmp_map, j, game);
		tmp_map = tmp_map->next;
		j += 60;
	}
}
