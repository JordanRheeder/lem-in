/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:34:57 by rengelbr          #+#    #+#             */
/*   Updated: 2020/05/14 17:08:55 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/colony.h"

int room_count(t_str *raw_data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (raw_data[i])
	{
		if (is_room(raw_data[i]))
			j++;
		i++;
	}
	return (j);
}

t_room *find_room(t_room **rooms, t_room *room)
{
	int i;

	i = 0;
	while (rooms[i])
	{
		if (ft_strequ(rooms[i]->name, room->name))
			return (rooms[i]);
		i++;
	}
	return (rooms[i]);
}

void print_map(t_log *node_array)
{
	t_room *temp_room;
	t_links *temp_link;

	ft_putstr("All Links: \n");
	for (int j = 0; node_array->rooms[j]->room_links->room; j++)
	{
		temp_room = node_array->rooms[j];
		ft_putstr("\t[");
		ft_putstr(temp_room->name);
		ft_putstr("] -> ");
		temp_link = temp_room->room_links;
		while (temp_link) {
			ft_putstr(temp_link->room->name);
			ft_putstr(" ");
			temp_link = temp_link->next;
		}
			ft_putstr("\n");
	}
	ft_putstr("\n");
}

void free_map(t_log *node_array)
{
	int i;

	ft_putstr("HERE");
	while (node_array->rooms[i])
	{
		ft_putstr("In Loop");
		free_room(node_array->rooms[i]);
	}
	ft_putstr("Exit Loop");
	free(node_array);
}

void free_room(t_room *room)
{
	free(room->name);
	free(room->next);
	free(room->room_links);
}
