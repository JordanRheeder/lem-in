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
	return (node);
}

t_log *create_links(t_log *node_array, t_str *raw_data, int i)
{
	int j;
	int k;
	int l;
	char **rooms;

	while (raw_data[i])
	{
		if (is_link(raw_data[i]))
		{
			j = 0;
			k = 0;
			l = 0;
			rooms = ft_strsplit(raw_data[i], '-');
			while (rooms[0] != node_array->rooms[j]->name)
				j++;
			while (rooms[1] != node_array->rooms[k]->name)
				k++;

			if (node_array->rooms[j]->room_links)
			{
				t_links *new_node;
				new_node->room = node_array->rooms[k];
				while (node_array->rooms[j]->room_links[l])
					l++;
				node_array->rooms[j]->room_links[l]->next = new_node;
				new_node->prev = node_array->rooms[j]->room_links[l];
			}
			else
			{
				t_links *new_node;
				new_node->room = node_array->rooms[k];
				node_array->rooms[j]->room_links[l] = new_node;
			}
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