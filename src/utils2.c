/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slatrech <slatrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:46:03 by slatrech          #+#    #+#             */
/*   Updated: 2025/05/01 13:52:20 by slatrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	free_list(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list -> next;
		free(list -> line);
		free(list);
		list = tmp;
	}
}

void	print_list(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	ft_printf("line: %s\n", tmp -> line);
	while (tmp -> next)
	{
		tmp = tmp -> next;
		ft_printf("line: %s\n", tmp -> line);
	}
}

char	*remove_n(char *map_line)
{
	int		i;
	char	*new_line;

	i = 0;
	while (map_line[i] && map_line[i] != '\n')
	{
		i++;
	}
	new_line = strndup(map_line, i);
	free(map_line);
	return (new_line);
}
