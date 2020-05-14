/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:34:57 by rengelbr          #+#    #+#             */
/*   Updated: 2020/05/14 17:06:21 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/colony.h"

t_room *create_node(t_str line)
{
	t_room *node;
	char **room_data;

	room_data = ft_strsplit(line, ' ');
	node = (t_room *)malloc(sizeof(t_room));

	node->name = (t_str)malloc(ft_strlen(room_data[0]) * sizeof(char) + 1);
	node->name = room_data[0];
	node->x = atoi(room_data[1]);
	node->y = atoi(room_data[2]);
	node->room_links = (t_links *)malloc(sizeof(t_links));
	node->room_type = 2;
	return (node);
}

t_log *create_links(t_log *node_array, t_str *raw_data, int i)
{
	int j;
	int k;
	char **rooms;
	t_links *temp_link;

	while (raw_data[i])
	{
		if (is_link(raw_data[i]))
		{
			j = 0;
			k = 0;
			rooms = ft_strsplit(raw_data[i], '-');
			temp_link = (t_links*)malloc(sizeof(t_links));
			while (ft_strequ(rooms[0], node_array->rooms[j]->name) != 1)
				j++;
			while (ft_strequ(rooms[1], (char *)node_array->rooms[k]->name) != 1)
				k++;
			if (!node_array->rooms[j]->room_links->room)
			{
				temp_link->room = node_array->rooms[k];
				temp_link->next = NULL;
				node_array->rooms[j]->room_links = temp_link;
			}
			else if (node_array->rooms[j]->room_type != 1)
			{
				temp_link->room = node_array->rooms[k];
				temp_link->next = node_array->rooms[j]->room_links;
				node_array->rooms[j]->room_links = temp_link;
			}
			ft_free_two_d_arr((void **)rooms);
		}
		i++;
	}
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
	node_array->rooms = (t_room **)malloc(sizeof(t_room *) * room_count(raw_data));
	//
	node_array->room_count = room_count(raw_data);
	while (!(is_link(raw_data[i])))
	{
		if (ft_only_digits(raw_data[i]))
			node_array->ant_amnt = ft_atoi(raw_data[i]);
		else if (is_command(raw_data[i]))
		{
			node_array->rooms[j] = create_node(raw_data[i + 1]);
			if (ft_strequ("##start", raw_data[i]))
			{
				node_array->start_index = j;
				node_array->rooms[j]->room_type = 0;
			}
			else if (ft_strequ("##end", raw_data[i]))
			{
				node_array->end_index = j;
				node_array->rooms[j]->room_type = 1;
			}
			i++;
			j++;
		}
		else if (is_room(raw_data[i]))
		{
			node_array->rooms[j] = create_node(raw_data[i]);
			node_array->room_count++;
			j++;
		}
		i++;
	}
	create_links(node_array, raw_data, i);
	ft_free_two_d_arr((void **)raw_data);
	return (node_array);
}
