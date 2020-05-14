/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:34:57 by rengelbr          #+#    #+#             */
/*   Updated: 2019/10/03 11:21:02 by rengelbr         ###   ########.fr       */
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
	int i;

	i = 0;
	while (node_array->rooms[i]->name)
	{
		ft_putstr("Room: ");
		ft_putstr(node_array->rooms[i]->name);
		ft_putstr("; Links: ");
		t_room *temp;
		temp = node_array->rooms[i]->room_links->room;
		while (temp)
		{
			ft_putstr(temp->name);
			if (temp->next)
				ft_putstr(", ");
			temp = temp->next;
		}
		ft_putstr(";\n");
		i++;
	}
	ft_putstr("\n");
}