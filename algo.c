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
	t_links *next_link;
	t_links *ret_link;

	ret_link = room_links;
	ft_putstr("\n");
	ft_putstr(ret_link->room->name);
	ft_putstr("\n");
	if (ret_link->next)
	{
	ft_putstr("NEXT");
		ft_putstr(ret_link->next->room->name);
	}
	ft_putstr("\n");
	if (ret_link && ret_link->next)
	{
		ft_putstr("\nHERE: ");
		next_link = ret_link->next;
		while (next_link)
		{
			ft_putstr("\nret_link: ");
			ft_putnbr(ret_link->room->visited);
			ft_putstr(" AND comparing_link: ");
			ft_putnbr(next_link->room->visited);
			ft_putstr(";\n");
			if (ret_link->room->visited > next_link->room->visited)
				ret_link = next_link;
			if (next_link->next)
				next_link = next_link->next;
			else
				return (ret_link);
		}
	}
	return (ret_link);
}

void algo(t_log *node_array)
{
	t_room 	*current_room;
	t_links *temp_links;

	current_room = node_array->rooms[node_array->start_index];
	// ft_putstr("\nStart Index: ");
	// ft_putnbr(node_array->start_index);
	// ft_putstr("\n");

	// ft_putstr("\nName: ");
	// ft_putstr(current_room->name);
	// ft_putstr("; Type: ");
	// ft_putnbr(current_room->room_type);
	// ft_putstr("\n");
	while (current_room->room_type != 1 && current_room->room_links->room)
	{
		current_room = find_least_visited(current_room->room_links)->room;
		current_room->visited++;
		// ft_putstr("\nHERE\n");
		// if (current_room->dead_end)
		// {
			// ft_putstr("\nDEAD END\n");
		// }
		// ft_putstr("\nvisited\n");

		// ft_putstr("\nName: ");
		// ft_putstr(current_room->name);
		// ft_putstr("; Type: ");
		// ft_putnbr(current_room->room_type);
		// ft_putstr("\n\n");

		if (!current_room->room_links->room && current_room->room_type != 1)
		{
			temp_links = current_room->room_links->next;
			free_room(current_room->room_links->room);
			free(current_room->room_links);
			current_room->room_links = current_room->room_links;
			current_room = find_least_visited(current_room->room_links)->room;

			// ft_putstr("\nName: ");
			// ft_putstr(current_room->name);
			// ft_putstr("; Type: ");
			// ft_putnbr(current_room->room_type);
			// ft_putstr("\n");

			current_room = node_array->rooms[node_array->start_index];
		}
	}
}