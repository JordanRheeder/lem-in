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
	t_room *temp_room;
	t_links *temp_link;

	ft_putstr("All Links: \n");
	for (int j = 0; node_array->rooms[j]->room_links->room; j++)
	{
		temp_room = node_array->rooms[j];
		temp_link = temp_room->room_links;
		while (temp_link != NULL ) {
			ft_putstr("\t[");
			ft_putstr(temp_room->name);
			ft_putstr("] -> ");
			ft_putstr(temp_link->room->name);
			ft_putstr("\n");
			temp_link = temp_link->next;
		}
	}
	ft_putstr("\n");
}


// typedef struct		s_links
// {
// 	struct	s_room	*room;
// 	struct	s_links	*next;
// 	struct	s_links	*prev;
// }									t_links;

// typedef struct		s_room
// {
// 	t_str						name;
// 	struct	s_links	*room_links;
// 	struct	s_room	*next;
// }									t_room;

// typedef struct		s_log
// {
// 	t_str						*links;
// 	struct	s_room	**rooms;
// }									t_log;
// void free_map(t_log *node_array)
// {
// 	int i;

// 	i = 0;
// 	free(node_array->links);
// 	while (node_array->rooms[i])
// 	{

// 	}
// }