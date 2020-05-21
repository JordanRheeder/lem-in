/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:28:51 by hde-vos           #+#    #+#             */
/*   Updated: 2020/05/21 16:01:24 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/colony.h"

t_path	*start_path(t_str room_name)
{
	t_path *the_path;

	the_path = (t_path *)malloc(sizeof(t_path));
	the_path->room_name = ft_strdup(room_name);
	the_path->next = NULL;

	return (the_path);
}

void	add_to_path(t_path *the_path, t_str room_name)
{
	t_path *updated_path;
	t_path *temp;

	updated_path = (t_path *)malloc(sizeof(t_path));
	temp = the_path;
	updated_path->room_name = ft_strdup(room_name);
	updated_path->next = NULL;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = updated_path;
}

t_links *find_least_visited(t_links *room_links)
{
	t_links *next_link;
	t_links *ret_link;

	ret_link = room_links;
	if (ret_link && ret_link->next)
	{
		next_link = ret_link->next;
		while (next_link)
		{
			if (ret_link->room->dead_end)
				ret_link = next_link;
			else if (ret_link->room->visited > next_link->room->visited && !next_link->room->dead_end)
				ret_link = next_link;
			if (next_link->next)
				next_link = next_link->next;
			else
				return (ret_link);
		}
	}
	return (ret_link);
}

t_path	*algo(t_log *node_array)
{
	t_room	*current_room;
	t_room	*previous_room;
	t_links	*temp_links;
	t_path	*the_path;

	current_room = node_array->rooms[node_array->start_index];
	the_path = NULL;

	// ft_putstr("Name: ");
	// ft_putstr(current_room->name);
	// ft_putstr("; Type: ");
	// ft_putnbr(current_room->room_type);
	// ft_putstr("\n");
	while (current_room->room_type != 1)
	{
		previous_room = current_room;
		current_room = find_least_visited(current_room->room_links)->room;
		if (!the_path)
			the_path = start_path(current_room->name);
		else
			add_to_path(the_path, current_room->name);
		current_room->visited++;

		// ft_putstr("Name: ");
		// ft_putstr(current_room->name);
		// ft_putstr("; Type: ");
		// ft_putnbr(current_room->room_type);
		// ft_putstr("\n");

		if (!current_room->room_links && current_room->room_type != 1)
		{
			current_room->dead_end = 1;
			free_path(the_path);
			the_path = NULL;
			current_room = node_array->rooms[node_array->start_index];

			// ft_putstr("Name: ");
			// ft_putstr(current_room->name);
			// ft_putstr("; Type: ");
			// ft_putnbr(current_room->room_type);
			// ft_putstr("\n");
		}
	}
	return (the_path);
}
