/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slatrech <slatrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:03:10 by slatrech          #+#    #+#             */
/*   Updated: 2025/05/01 13:52:07 by slatrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	put_map_in_list(char *map_line, t_list **map, int last_size, int line_size)
{
	t_list	*node;

	if (map_line)
	{
		if (is_line_valid(map_line) == 0)
		{
			node = create_node(map_line);
			add_back(map, node);
			last_size = line_size;
		}
		else
		{
			ft_printf("Non-valid map");
			free_map(*map);
			exit(EXIT_FAILURE);
		}
	}
	return (last_size);
}

void	handle_invalid_map(char *map_line, t_list **map)
{
	ft_printf("Non-valid map");
	free_map(*map);
	free(map_line);
	exit(EXIT_FAILURE);
}

void	read_map_lines(int fd, t_list **map)
{
	char	*map_line;
	int		line_size;
	int		last_size;

	map_line = "debut";
	line_size = 0;
	last_size = 0;
	while (map_line)
	{
		map_line = get_next_line(fd);
		if (map_line && map_line[0] == '\n')
			handle_invalid_map(map_line, map);
		if (map_line)
		{
			map_line = remove_n(map_line);
			line_size = ft_strlen(map_line);
		}
		else
			line_size = 0;
		if (last_size != 0 && line_size != 0 && line_size != last_size)
			handle_invalid_map(map_line, map);
		last_size = put_map_in_list(map_line, map, last_size, line_size);
	}
	free(map_line);
}

t_list	*read_map(char *map_name)
{
	int		fd;
	t_list	*map;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("File does not exit");
		exit(EXIT_FAILURE);
	}
	map = NULL;
	read_map_lines(fd, &map);
	return (map);
}

void	create_map(t_game *game, t_list *map)
{
	t_list	*head;

	game->height = 0;
	game->width = 0;
	head = map;
	while (head)
	{
		game->height++;
		head = head -> next;
	}
	while (map->line[game->width])
		game->width++;
}
