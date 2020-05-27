/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:34:57 by rengelbr          #+#    #+#             */
/*   Updated: 2020/05/24 17:16:28 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/colony.h"

int room_count(t_data *raw_data)
{
	int		j;
	t_data	*temp;

	j = 0;
	temp = raw_data;
	while (temp != NULL)
	{
		if (is_room(temp->line))
			j++;
		temp = temp->next;
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

void free_map(t_log *node_array)
{
	int i;

	while (node_array->rooms[i])
	{
		free_room(node_array->rooms[i]);
	}
	free(node_array);
}

void free_room(t_room *room)
{
	free(room->name);
	if (room->next)
		free(room->next);
	if (room->room_links)
		free(room->room_links);
}

void free_path(t_path *the_path)
{
	t_path *temp;

	while (the_path != NULL)
	{
		temp = the_path;
		the_path = the_path->next;
		free(temp->room_name);
		free(temp);
	}
}

void free_data(t_data *data)
{
	t_data *temp;

	while (data != NULL)
	{
		temp = data;
		data = data->next;
		free(temp->line);
		free(temp);
	}
}

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

t_path *copy_path(t_path *path)
{
	t_path *ret_path;
	t_path *temp;

	temp = path;
	ret_path = start_path(temp->room_name);
	temp = temp->next;
	while (temp)
	{
		add_to_path(ret_path, temp->room_name);
		temp = temp->next;
	}
	return (ret_path);
}

t_path *shortest_path(t_path **paths, int path_count)
{
	int i;
	int len;
	int min_len;
	int ml_index;
	t_path *temp;

	i = -1;
	min_len = 0;
	ml_index = 0;
	while (++i < path_count)
	{
		len =  0;
		temp = paths[i];
		while (temp)
		{
			len++;
			temp = temp->next;
		}
		if (len < min_len || min_len == 0)
		{
			min_len = len;
			ml_index = i;
		}
	}
	return (paths[ml_index]);
}

void ft_putroom(int ant_name, char *room_name)
{
	ft_putstr("L");
	ft_putnbr(ant_name);
	ft_putstr("-");
	ft_putstr(room_name);
	ft_putstr(" ");
}
