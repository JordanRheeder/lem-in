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

t_room *create_node(t_str line)
{
	t_room *node;
	char **room_data;

	room_data = ft_strsplit(line, ' ');
	// check for leaks
	node = (t_room *)malloc(sizeof(t_room));
	//
	node->name = (t_str)malloc(ft_strlen(room_data[0]) * sizeof(char));
	node->name = room_data[0];
	node->x = atoi(room_data[1]);
	node->y = atoi(room_data[2]);
	node->room_links = (t_links *)malloc(sizeof(t_links));
	return (node);
}

t_log *create_links(t_log *node_array, t_str *raw_data, int i)
{
	int j;
	int k;
	char **rooms;
	// t_links *temp;

	while (raw_data[i])
	{
		if (is_link(raw_data[i]))
		{
			j = 0;
			k = 0;
			rooms = ft_strsplit(raw_data[i], '-');
			while (ft_strequ(rooms[0], node_array->rooms[j]->name) != 1)
				j++;
			while (ft_strequ(rooms[1], node_array->rooms[k]->name) != 1)
				k++;
			t_links *new_node;
			new_node = create_link_node();
			new_node->room = node_array->rooms[k];
			// if (!node_array->rooms[j]->room_links->room) {
				ft_putstr("New List\n");
				node_array->rooms[j]->room_links->room = new_node->room;
			// } else {
			// 	ft_putstr("Adding to List\n");
			// 	temp = node_array->rooms[j]->room_links;
			// 	while (temp->next)
			// 		temp = temp->next;
			// 	temp->next = new_node;
			// 	new_node->prev = temp;
			// }
			// free(temp);
		}
		i++;
	}
	free(rooms);
	return (node_array);
}

t_log *create_node_array(t_str *raw_data)
{
	int i;
	int j;
	t_log *node_array;

	i = 0;
	j = 0;
	// check for leaks
	node_array = (t_log *)malloc(sizeof(t_log));
	// check for leaks
	node_array->rooms = (t_room **)malloc(sizeof(t_room *) * room_count(raw_data));
	//
	while (!(is_link(raw_data[i])))
	{
		if (ft_only_digits(raw_data[i]))
			node_array->ant_amnt = ft_atoi(raw_data[i]);
		else if (is_command(raw_data[i]))
		{
			node_array->rooms[j] = create_node(raw_data[i + 1]);
			if (ft_strequ("##start", raw_data[i]))
				node_array->rooms[j]->room_type = 0;
			else if (ft_strequ("##end", raw_data[i]))
				node_array->rooms[j]->room_type = 1;
			i++;
			j++;
		}
		else if (is_room(raw_data[i]))
		{
			node_array->rooms[j] = create_node(raw_data[i]);
			j++;
		}
		i++;
	}
	create_links(node_array, raw_data, i);
	free(raw_data);
	return (node_array);
}