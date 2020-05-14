/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leminAlgo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 11:58:05 by rengelbr          #+#    #+#             */
/*   Updated: 2020/05/14 15:26:14 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/colony.h"
#include <stdio.h>

t_str find_least_visited(t_links *links)
{
	t_links *temp;
	unsigned int min;
	char *name;

	temp = (t_links*)malloc(sizeof(t_links));
	temp = links;
	min = 0;
printf("find_least reached temp->room->visited == %i\n", temp->room->visited);
printf("find_least reached temp->room->name == %s\n", temp->room->name);
	while (temp->next && temp->room->visited > min)
	{
		printf("moving to next node");
		temp = temp->next;
	}
	name = ft_strdup(temp->room->name);
	return (name);
}

void	find_path(t_log *data)
{
	int		start;
	int		end;
	int		i;
	t_room	**rooms;
	t_room	*current_room;
	char	**current_path;
	char	*least_visited;

	start = data->start_index;
	end = data->end_index;
	i = start;
	rooms = data->rooms;
	current_path = (char**)malloc(sizeof(char*) * data->room_count);
	while (rooms[i]->room_links && i != end)
	{
		current_room = rooms[i]->room_links->room;
		if (current_room->room_type == 0 || current_room->room_type == 1) {
			*current_path = current_room->name;
			current_path++;
		}
		current_room->visited += 1;
		if (current_room->room_type == 1)
			break;
		else if (current_room->room_links != NULL)
		{
			least_visited = find_least_visited(current_room->room_links);
			printf("least visited == %s\n", least_visited);
			// while (!ft_strequ(current_room->room_links->room->name, least_visited))
			// {
			// 	current_room->room_links = current_room->room_links->next;
			// }
		}
				i=end;
		// rooms[i]->room_links = rooms[i]->room_links->next;
	}
}
