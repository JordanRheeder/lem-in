/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:34:57 by rengelbr          #+#    #+#             */
/*   Updated: 2020/05/22 12:42:59 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/colony.h"

t_room *create_node(t_str line)
{
	t_room *node;
	char **room_data;

	room_data = ft_strsplit(line, ' ');
	node = (t_room *)malloc(sizeof(t_room));
	node->name = ft_strdup(room_data[0]);
	node->x = ft_atoi(room_data[1]);
	node->y = ft_atoi(room_data[2]);
	node->room_links = NULL;
	node->room_type = 2;
	node->dead_end = 0;
	ft_free_two_d_arr((void **)room_data);
	return (node);
}

t_links *start_links(t_log *node_array, int index)
{
	t_links *temp_link;

	temp_link = (t_links*)malloc(sizeof(t_links));
	temp_link->room = node_array->rooms[index];
	temp_link->next = NULL;

	return (temp_link);
}

t_links *add_link(t_log *node_array, int add_room_i, int room_link_i)
{
	t_links *temp_link;

	temp_link = (t_links*)malloc(sizeof(t_links));
	temp_link->room = node_array->rooms[add_room_i];
	temp_link->next = node_array->rooms[room_link_i]->room_links;

	return (temp_link);
}

t_log *create_links(t_log *node_array, t_str *raw_data, int i)
{
	int j;
	int k;
	char **rooms;

	while (raw_data[i])
	{
		if (is_link(raw_data[i]))
		{
			j = 0;
			k = 0;
			rooms = ft_strsplit(raw_data[i], '-');
			while (!ft_strequ(rooms[0], node_array->rooms[j]->name))
				j++;
			while (!ft_strequ(rooms[1], node_array->rooms[k]->name))
				k++;
			if (j == node_array->end_index || k == node_array->start_index)
			{
				j = j ^ k;
				k = j ^ k;
				j = j ^ k;
			}
			if (node_array->rooms[j]->room_links == NULL && node_array->rooms[k]->room_type != 1)
				node_array->rooms[j]->room_links = start_links(node_array, k);
			else if (node_array->rooms[j]->room_type != 1)
				node_array->rooms[j]->room_links = add_link(node_array, k, j);
			if (node_array->rooms[k]->room_links == NULL && k != node_array->end_index
					&& j != node_array->start_index)
				node_array->rooms[k]->room_links = start_links(node_array, j);
			else if (node_array->rooms[k]->room_type != 1 && j != node_array->start_index)
				node_array->rooms[k]->room_links = add_link(node_array, j, k);
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
	node_array = (t_log *)malloc(sizeof(t_log));
	node_array->rooms = (t_room **)malloc(sizeof(t_room *) * room_count(raw_data));
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
			j++;
		}
		i++;
	}
	if (!validate_links(node_array, raw_data, i))
	{	// free erryting
		LINK_ERR;
	}
	create_links(node_array, raw_data, i);
	ft_free_two_d_arr((void **)raw_data);
	return (node_array);
}
