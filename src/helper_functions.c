/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:34:57 by rengelbr          #+#    #+#             */
/*   Updated: 2020/05/20 09:50:16 by rengelbr         ###   ########.fr       */
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

t_room *find_room(t_log *data, t_str room_name)
{
	int i;

	i = 0;
	while (i < data->room_count)
	{
		if (ft_strequ(data->rooms[i]->name, room_name))
			return (data->rooms[i]);
		i++;
	}
	return NULL;
}

void print_map(t_log *node_array)
{
	t_room *temp_room;
	t_links *temp_link;

	ft_putstr("All Links: \n");
	for (int j = 0; j < node_array->room_count; j++)
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
