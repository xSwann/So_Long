/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slatrech <slatrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:00:14 by swann             #+#    #+#             */
/*   Updated: 2025/05/01 13:51:26 by slatrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

char	**put_list_in_tabs(t_list *map, int is_map)
{
	t_list	*tmp_map;
	char	**tab_map;
	int		len;
	int		i;

	tmp_map = map;
	i = 0;
	len = 0;
	while (tmp_map)
	{
		tmp_map = tmp_map -> next;
		len++;
	}
	tmp_map = map;
	tab_map = malloc(sizeof(char *) * (len + 1));
	tab_map[len] = 0;
	fill_tab(tmp_map, tab_map, is_map, i);
	return (tab_map);
}

void	flood_fill(int x, int y, t_flood_data *data)
{
	if (data->map[x][y] == '1')
		return ;
	if (data->visited[x][y] == '1')
		return ;
	data->visited[x][y] = '1';
	if (data->map[x][y] == 'C')
		data->counts->c_count++;
	else if (data->map[x][y] == 'E')
		data->counts->e_count++;
	flood_fill(x + 1, y, data);
	flood_fill(x - 1, y, data);
	flood_fill(x, y + 1, data);
	flood_fill(x, y - 1, data);
}

static int	init_structs(t_counts **counts, t_x_and_y **pos)
{
	*counts = malloc(sizeof(t_counts));
	*pos = malloc(sizeof(t_x_and_y));
	if (!*counts || !*pos)
		return (0);
	(*counts)->c_count = 0;
	(*counts)->e_count = 0;
	(*pos)->x = 0;
	(*pos)->y = 0;
	return (1);
}

void	exit_map_error(t_list *map, t_cleanup_data *cleanup)
{
	ft_printf("Map is not resolvable\n");
	free_all(cleanup->visited, cleanup->tab_map,
		cleanup->counts, cleanup->pos);
	free_map(map);
	exit(1);
}

void	initialise(t_list *map)
{
	t_counts		*counts;
	t_x_and_y		*pos;
	t_flood_data	data;
	t_cleanup_data	cleanup;
	int				c_number;

	if (!init_structs(&counts, &pos))
		return ;
	cleanup.visited = put_list_in_tabs(map, 0);
	data.map = put_list_in_tabs(map, 1);
	cleanup.tab_map = data.map;
	data.visited = cleanup.visited;
	data.counts = counts;
	cleanup.counts = counts;
	cleanup.pos = pos;
	c_number = find_c_count(data.map);
	find_start_position(data.map, &pos->y, &pos->x);
	flood_fill(pos->x, pos->y, &data);
	if (!(counts->c_count == c_number && counts->e_count == 1))
		exit_map_error(map, &cleanup);
	free_all(cleanup.visited, cleanup.tab_map, counts, pos);
}
