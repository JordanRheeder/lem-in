/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:28:51 by hde-vos           #+#    #+#             */
/*   Updated: 2019/09/22 18:06:13 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/colony.h"

t_links *find_least_visited(t_links *room_links)
{
	t_links *current_link;
	t_links *next_link;
	t_links *ret_link;

	current_link = room_links;
	ret_link = current_link;
	if (current_link && current_link->next)
	{
		next_link = current_link->next;
		while (next_link)
		{
			if (ret_link->room->visited > next_link->room->visited)
				ret_link = next_link;
			if (next_link->next)
				next_link = next_link->next;
			else
				return (ret_link);
		}
	}
	return (current_link);
}

void algo(t_log *node_array)
{
	t_room *current_room;

	current_room = node_array->rooms[node_array->start_index];
	ft_putstr("\nStart Index: ");
	ft_putnbr(node_array->start_index);
	ft_putstr("\n");

	ft_putstr("\nName: ");
	ft_putstr(current_room->name);
	ft_putstr("; Type: ");
	ft_putnbr(current_room->room_type);
	ft_putstr("\n");	
	while (current_room->room_type != 1 && current_room->room_links->room)
	{
		current_room->visited++;

		ft_putstr("\nName: ");
		ft_putstr(current_room->name);
		ft_putstr("; Type: ");
		ft_putnbr(current_room->room_type);
		ft_putstr("\n");

		current_room = find_least_visited(current_room->room_links)->room;

		if (!current_room->room_links->room)
		{
			ft_putstr("\nName: ");
			ft_putstr(current_room->name);
			ft_putstr("; Type: ");
			ft_putnbr(current_room->room_type);
			ft_putstr("\n");
			current_room = node_array->rooms[node_array->start_index];
		}
	}
	ft_putstr("\n");
	ft_putstr("Name: ");
	ft_putstr(current_room->name);
	ft_putstr("; Type: ");
	ft_putnbr(current_room->room_type);
	ft_putstr("\n\n");
}