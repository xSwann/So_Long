/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slatrech <slatrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:42:41 by swann             #+#    #+#             */
/*   Updated: 2025/05/01 14:14:21 by slatrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"
//echap croix
void	exit_handler(t_game *game, int keycode)
{
	if (keycode == 65307)
		clean_exit(game, EXIT_SUCCESS);
	if (keycode == 17)
		clean_exit(game, EXIT_SUCCESS);
}

void	*load_image(t_game *game, char *path, int *width, int *height)
{
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, path, width, height);
	if (!img)
		perror("Erreur de chargement de l'image\n");
	return (img);
}

void	create_window_and_assets(t_game *game)
{
	int	img_width;
	int	img_height;

	if (!game->mlx)
	{
		ft_printf("Erreur : mlx_init a échoué\n");
		exit(EXIT_FAILURE);
	}
	game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE,
			game->height * TILE_SIZE, "So Long");
	if (!game->win)
		perror("Erreur de création de la fenêtre\n");
	game->img_bg = load_image(game, "as/bg.xpm", &img_width, &img_height);
	game->img_wall = load_image(game, "as/wall.xpm", &img_width, &img_height);
	game->img_coll = load_image(game, "as/col.xpm", &img_width, &img_height);
	game->img_exit = load_image(game, "as/exit.xpm", &img_width, &img_height);
	game->img_player = load_image(game, "as/sora.xpm", &img_width, &img_height);
	if (!game->win || !game->img_bg || !game->img_wall || !game->img_coll
		|| !game->img_exit || !game->img_player)
		exit(1);
}

void	start_game(t_game *game)
{
	create_window_and_assets(game);
	draw_map(game);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_player, game->player_x, game->player_y);
	mlx_key_hook(game->win, key_hook, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
}

int	key_hook(int keycode, t_game *game)
{
	int		tile_x;
	int		tile_y;
	char	wich_tile;

	tile_x = game->player_x / 60;
	tile_y = game->player_y / 60;
	wich_tile = get_tile_at(game->map, tile_y, tile_x);
	if (wich_tile == 'C')
	{
		game->score++;
		change_coll_to_bg(game->map, tile_y, tile_x);
	}
	if (wich_tile == 'E' && game-> score == game->score_to_reach)
		clean_exit(game, EXIT_SUCCESS);
	move_handler(game, keycode);
	exit_handler(game, keycode);
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_player, game->player_x, game->player_y);
	return (0);
}
