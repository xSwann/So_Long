/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slatrech <slatrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:48:06 by slatrech          #+#    #+#             */
/*   Updated: 2025/05/01 13:51:10 by slatrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	free_map(t_list *map)
{
	t_list	*current;
	t_list	*next;

	current = map;
	while (current)
	{
		next = current->next;
		if (current->line)
			free(current->line);
		free(current);
		current = next;
	}
}

void	finish_exit(int status, t_game *game)
{
	if (status == EXIT_SUCCESS && game->score == game->score_to_reach)
		ft_printf("GG ! Partie terminée en %d mouvements.\n", game->mooves);
	else if (status == EXIT_SUCCESS)
	{
		ft_printf("Jeu terminé. Score final : %d/%d en %d mouvements.\n",
			game->score, game->score_to_reach, game->mooves);
	}
	exit(status);
}

void	clean_exit(t_game *game, int status)
{
	if (game->img_bg)
		mlx_destroy_image(game->mlx, game->img_bg);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_coll)
		mlx_destroy_image(game->mlx, game->img_coll);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(game->map);
	finish_exit(status, game);
}

int	close_window(t_game *game)
{
	clean_exit(game, EXIT_FAILURE);
	return (0);
}
