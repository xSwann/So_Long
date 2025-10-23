/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slatrech <slatrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:20:23 by slatrech          #+#    #+#             */
/*   Updated: 2025/05/01 13:57:36 by slatrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	wall_error_handler(t_list *map)
{
	ft_printf("Map must be bordered by walls (1)");
	free_map(map);
	exit(EXIT_FAILURE);
}

void	collec_exit_start_error_handler(t_list *map)
{
	ft_printf("Map must contain only 1 Position and Exit (E and P)");
	free_map(map);
	exit(EXIT_FAILURE);
}

void	is_first_line_valid(t_list	*tmp_map, t_list *map)
{
	int	i;

	i = 0;
	while (tmp_map->line[i])
	{
		if (tmp_map->line[i] != '1')
		{
			wall_error_handler(map);
		}
		i++;
	}
}

int	is_mids_line_valid(t_list **tmp_map, t_list *map, int *p, int *c)
{
	int	i;
	int	e;

	e = 0;
	i = 0;
	while ((*tmp_map)->next)
	{
		i = 0;
		if ((*tmp_map)->line[0] != '1'
			|| (*tmp_map)->line[ft_strlen(map->line) - 1] != '1')
			wall_error_handler(map);
		while ((*tmp_map)->line[i])
		{
			if ((*tmp_map)->line[i] == 'E')
				e++;
			if ((*tmp_map)->line[i] == 'P')
				(*p)++;
			if ((*tmp_map)->line[i] == 'C')
				(*c)++;
			i++;
		}
		(*tmp_map) = (*tmp_map)->next;
	}
	return (e);
}

void	is_map_valid(t_list	*map)
{
	int		i;
	int		e;
	int		p;
	int		c;
	t_list	*tmp_map;

	tmp_map = map;
	i = 0;
	e = 0;
	p = 0;
	c = 0;
	is_first_line_valid(tmp_map, map);
	tmp_map = tmp_map->next;
	e = is_mids_line_valid(&tmp_map, map, &p, &c);
	if (e != 1 || p != 1 || c < 1)
		collec_exit_start_error_handler(map);
	i = 0;
	while (tmp_map->line[i])
	{
		if (tmp_map->line[i] != '1')
			wall_error_handler(map);
		i++;
	}
}
