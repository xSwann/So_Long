/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slatrech <slatrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:27:03 by slatrech          #+#    #+#             */
/*   Updated: 2025/05/01 13:52:01 by slatrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "include/so_long.h"
#include "get_next_line/get_next_line.h"

int	main(int argc, char **argv)
{
	char	*map_name;
	t_list	*map;
	t_game	game;

	if (argc != 2)
	{
		ft_printf("You have to enter a map");
		return (0);
	}
	map_name = argv[1];
	is_map_name_valid(map_name);
	map = read_map(map_name);
	is_map_valid(map);
	create_map(&game, map);
	initialise(map);
	init_game(&game, map);
	start_game(&game);
	return (0);
}
