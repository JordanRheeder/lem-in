/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:34:57 by rengelbr          #+#    #+#             */
/*   Updated: 2020/05/29 15:05:04 by rengelbr         ###   ########.fr       */
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

t_log *create_links(t_log *node_array, t_data *raw_data, int i)
{
	int j;
	int k;
	char **rooms;
	t_data *temp;

	temp = raw_data;
	while (temp)
	{
		if (is_link(temp->line))
		{
			j = 0;
			k = 0;
			rooms = ft_strsplit(temp->line, '-');
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
			if (node_array->rooms[k]->room_links == NULL)
				node_array->rooms[k]->room_links = start_links(node_array, j);
			else if (node_array->rooms[k]->room_type != 1)
				node_array->rooms[k]->room_links = add_link(node_array, j, k);
			ft_free_two_d_arr((void **)rooms);
		}
		temp = temp->next;
		i++;
	}
	return (node_array);
}

t_log *create_node_array(t_data *raw_data)
{
	int		i;
	int		j;
	t_log	*node_array;
	t_data	*temp;
	char	*ant_amount;

	i = 0;
	j = 0;
	node_array = (t_log *)malloc(sizeof(t_log));
	node_array->rooms = (t_room **)malloc(sizeof(t_room *) * room_count(raw_data));
	node_array->room_count = room_count(raw_data);
	temp = raw_data;
	while (temp && !is_link(temp->line))
	{
		if (ft_only_digits(temp->line))
		{
			node_array->ant_amnt = ft_atoi(temp->line);
			ant_amount = ft_itoa(node_array->ant_amnt);
			if (!ft_strequ(ant_amount, temp->line) || node_array->ant_amnt < 1)
			{
				free(ant_amount);
				free(node_array->rooms);
				free(node_array);
				free_data(raw_data);
				ANT_ERR;
			}
			free(ant_amount);
		}
		else if (is_command(temp->line))
		{
			if (ft_strequ("##start", temp->line))
			{
				while (!is_room(temp->line))
					temp = temp->next;
				node_array->rooms[j] = create_node(temp->line);
				node_array->start_index = j;
				node_array->rooms[j]->room_type = 0;
			}
			else if (ft_strequ("##end", temp->line))
			{
				while (!is_room(temp->line))
					temp = temp->next;
				node_array->rooms[j] = create_node(temp->line);
				node_array->end_index = j;
				node_array->rooms[j]->room_type = 1;
			}
			i++;
			j++;
		}
		else if (is_room(temp->line))
		{
			node_array->rooms[j] = create_node(temp->line);
			j++;
		}
		temp = temp->next;
		i++;
	}
	if (!validate_links(node_array, temp))
	{
		free_map(node_array);
		free_data(raw_data);
		LINK_ERR;
	}
	create_links(node_array, raw_data, i);
	return (node_array);
}
