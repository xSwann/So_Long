/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slatrech <slatrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:56:05 by slatrech          #+#    #+#             */
/*   Updated: 2025/05/01 14:04:35 by slatrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	make_x_move(t_game *game, char signe)
{
	if (signe == '-')
		game->player_x -= 60;
	else if (signe == '+')
		game->player_x += 60;
	game->mooves++;
	ft_printf("\r%d", game->mooves);
}

void	make_y_move(t_game *game, char signe)
{
	if (signe == '-')
		game->player_y -= 60;
	else if (signe == '+')
		game->player_y += 60;
	game->mooves++;
	ft_printf("\r%d", game->mooves);
}
//gauche droite haut bas

void	handle_x_move(t_game *game, int x, int y, int dx)
{
	char	wich_tile;

	wich_tile = get_tile_at(game->map, y, x + dx);
	if (wich_tile != '1')
	{
		if (dx == -1)
			make_x_move(game, '-');
		else
			make_x_move(game, '+');
	}
}

void	handle_y_move(t_game *game, int x, int y, int dy)
{
	char	wich_tile;

	wich_tile = get_tile_at(game->map, y + dy, x);
	if (wich_tile != '1')
	{
		if (dy == -1)
			make_y_move(game, '-');
		else
			make_y_move(game, '+');
	}
}
//left right up down

void	move_handler(t_game *game, int keycode)
{
	int	x;
	int	y;

	x = game->player_x / 60;
	y = game->player_y / 60;
	if (keycode == 65361)
		handle_x_move(game, x, y, -1);
	else if (keycode == 65363)
		handle_x_move(game, x, y, 1);
	else if (keycode == 65362)
		handle_y_move(game, x, y, -1);
	else if (keycode == 65364)
		handle_y_move(game, x, y, 1);
}
