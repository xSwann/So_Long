/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slatrech <slatrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:07:09 by slatrech          #+#    #+#             */
/*   Updated: 2025/05/01 13:52:12 by slatrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	is_map_name_valid(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (len <= 4 || map_name[len -4] != '.' || map_name[len -3] != 'b'
		|| map_name[len -2] != 'e' || map_name[len -1] != 'r'
		|| map_name[len] != '\0')
	{
		ft_printf("Map should be a .ber file");
		exit(EXIT_FAILURE);
	}
}

int	is_line_valid(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1'
			&& line[i] != 'C' && line[i] != 'E'
			&& line[i] != 'P' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*create_node(char *line)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node -> line = line;
	new_node -> next = NULL;
	return (new_node);
}

void	add_back(t_list **list, t_list *new_node)
{
	t_list	*tmp;

	if (*list == NULL)
	{
		*list = new_node;
		return ;
	}
	tmp = *list;
	while (tmp -> next)
		tmp = tmp -> next;
	tmp -> next = new_node;
}

int	list_size(t_list *list)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = list;
	while (tmp)
	{
		tmp = tmp -> next;
		i++;
	}
	return (i);
}
