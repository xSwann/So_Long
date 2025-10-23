/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swann <swann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:22:40 by slatrech          #+#    #+#             */
/*   Updated: 2025/04/29 19:24:42 by swann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	find_c_count(char **tab_map)
{
	int	i;
	int	j;
	int	c_count;

	i = 0;
	j = 0;
	c_count = 0;
	while (tab_map[i])
	{
		j = 0;
		while (tab_map[i][j])
		{
			if (tab_map[i][j] == 'C')
				c_count++;
			j++;
		}
		i++;
	}
	return (c_count);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
}

void	free_all(char **visited, char **tab_map,
	t_counts *counts, t_x_and_y *x_and_y)
{
	free_tab(visited);
	free_tab(tab_map);
	free(visited);
	free(tab_map);
	free(counts);
	free(x_and_y);
}

void	find_start_position(char **tab_map,
	int *start_position_x, int *start_position_y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab_map[i])
	{
		j = 0;
		while (tab_map[i][j])
		{
			if (tab_map[i][j] == 'P')
			{
				*start_position_x = j;
				*start_position_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	fill_tab(t_list *tmp_map, char **tab_map, int is_map, int i)
{
	int	line_len;
	int	j;

	line_len = 0;
	j = 0;
	while (tmp_map)
	{
		line_len = 0;
		j = 0;
		while (tmp_map->line[line_len])
			line_len++;
		tab_map[i] = malloc(sizeof(char) * line_len + 1);
		while (tmp_map->line[j])
		{
			if (is_map == 1)
				tab_map[i][j] = tmp_map->line[j];
			else if (is_map == 0)
				tab_map[i][j] = '0';
			j++;
		}
		tab_map[i][j] = '\0';
		tmp_map = tmp_map -> next;
		i++;
	}
}
