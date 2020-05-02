// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   mapulation.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2019/09/12 13:34:57 by rengelbr          #+#    #+#             */
// /*   Updated: 2019/10/03 11:21:02 by rengelbr         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../includes/colony.h"
// #include "../libft/libft.h"
// #include <stdio.h>
// //finds every link in all_links that references name, returns it in 2d array
// char	**get_linked_rooms(t_str name, t_str *all_links)
// {
// 	//unsigned int	name_len;  **UNUSED**
// 	unsigned int	i;
// 	unsigned int	j;
// 	char			**connected;

// 	//name_len = ft_strlen(name); **UNUSED**
// 	i = 0;
// 	j = 0;
// 	connected = (char**)malloc(sizeof(char*) * ft_two_d_arrsize(all_links));
// 	while (all_links[i])
// 	{
// 		if (ft_strnstr(all_links[i], name, ft_strlen(all_links[i])))
// 		{
// 			connected[j] = ft_strdup(all_links[i]);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (connected);
// }

// int		get_coordinate(t_str room, char type)
// {
// 	int		x_y;
// 	char	**coordinates;

// 	x_y = 0;
// 	coordinates = ft_strsplit(room, ' ');
// 	if (type == 'x')
// 		x_y = ft_atoi(coordinates[1]);
// 	else if (type == 'y')
// 		x_y = ft_atoi(coordinates[2]);
// 	return (x_y);
// }

// void	add_room(t_room **maze, t_str room, unsigned int type)
// {
// 	t_room *new_room;

// 	new_room = malloc(sizeof(t_room));
// 	new_room->room_type = type;
// 	new_room->name = get_room_name(room);
// 	new_room->x = get_coordinate(room, 'x');
// 	new_room->y = get_coordinate(room, 'y');
// 	new_room->visited = 0;
// 	new_room->next = *maze;
// 	*maze = new_room;
// }

// t_room	*new_maze(t_str room, unsigned int type)
// {
// 	t_room	*maze;

// 	maze = malloc(sizeof(t_room));
// 	maze->room_type = type;
// 	maze->name = get_room_name(room);
// 	maze->x = get_coordinate(room, 'x');
// 	maze->y = get_coordinate(room, 'y');
// 	maze->visited = 0;
// 	maze->next = NULL;
// 	return (maze);
// }

// //Returns name of room linked to r_name from string link
// char *get_linked_name(t_str r_name, t_str link)
// {
// 	t_str *arr_names;

// 	arr_names = ft_strsplit(link, '-');
// 	if (ft_strequ(r_name, arr_names[0]))
// 		return (arr_names[1]);
// 	if (ft_strequ(r_name, arr_names[1]))
// 		return (arr_names[0]);
// 	return (NULL);
// }

// void	link_rooms(t_room **maze, t_str *links)
// {
// 	t_room	*maze_head;
// 	t_room	*temp;
// 	t_str	*cur_lnks;
// 	// t_str	cur_lnk_name; // Got too many variables
// 	int		i;
// 	int		j;

// 	i = 0;
// 	cur_lnks = NULL;
// 	maze_head = *maze;
// 	while ((*maze))
// 	{
// 		cur_lnks = get_linked_rooms((*maze)->name, links);
// printf("Amount of possible links == %d\n", ft_two_d_arrsize(cur_lnks));
// 		if (!((*maze)->room_links = malloc(sizeof(t_room*) * ft_two_d_arrsize(cur_lnks))))
// 			return ;
// 		temp = maze_head;
// // printf("temp->name = %s\n", temp->name);
// 		while (temp)
// 		{
// 			j = 0;
// 			// i = 0;
// 			while (cur_lnks[j]/**cur_lnks*/)
// 			{
// 				// cur_lnk_name = get_linked_name((*maze)->name, cur_lnks[j]/**cur_lnks*/);
// printf("curr_lnk_name == %s  temp->name == %s\n", get_linked_name((*maze)->name, cur_lnks[j]), temp->name);
// 				if (ft_strequ(temp->name, get_linked_name((*maze)->name, cur_lnks[j])))
// 				{
// printf("about to link maze room %s to temp room %s\n", (*maze)->name, temp->name);
// 					if (!(temp->room_links = malloc(sizeof(t_room*) * ft_two_d_arrsize(cur_lnks))))
// 						return ;
// 					temp->room_links[i] = *maze;
// for (int p = 0; temp->room_links[p]; p++) {
// 	printf("\ntemp->room_lnk[%i] = %s\n\n", p, temp->room_links[p]->name);
// }
// 					(*maze)->room_links[i] = temp;
// printf("room linked names = %s\n", (*maze)->room_links[i]->name);
// // printf("(*maze)->room_links[%i]->name + coords = %s %d %d->type %d\n", i, (*maze)->room_links[i]->name, (*maze)->room_links[i]->x, (*maze)->room_links[i]->y, (*maze)->room_links[i]->room_type);
// 					i++;
// printf("room[%s] linked to room[%s]\n", (*maze)->name, temp->name);
// 				}
// 				j++;
// 				// cur_lnks++;
// 			}
// 			temp = temp->next;
// 		}
// 		// i = 0;
// 		// while ((*maze)->room_links[i]) {
// 			// free((*maze)->room_links[i]);
// 			// printf("(%s)->room_links[%i]=%s->room_links[0]=%s\n", (*maze)->name,i,(*maze)->room_links[i]->name,(*maze)->room_links[i]->room_links[i]->name);
// 		// 	i++;
// 		// }
// 		*maze = (*maze)->next;
// 		i = 0;

// 	}
// 	*maze = maze_head;
// }

// t_room	*init_rooms(t_log *data)
// {
// 	t_room *maze;
// 	int i;
// 	char **cur_links;
// 	char *room_name;

// 	maze = NULL;
// 	i = 0;
// 	if(!(cur_links = (char**)malloc(sizeof(sizeof(char*)))))
// 		return NULL;
// 	while (data->rooms[i])
// 	{
// 		room_name = get_room_name(data->rooms[i]);
// 		cur_links = get_linked_rooms(room_name, data->links);
// 		if (!maze)
// 		{
// 			if (i == data->start_index)
// 				maze = new_maze(data->rooms[i], 0);
// 			else if (i == data->end_index)
// 				maze = new_maze(data->rooms[i], 1);
// 			else
// 				maze = new_maze(data->rooms[i], 2);
// 			// printf("new maze: %s\n", maze->name);
// 		}
// 		else
// 		{
// 			if (i == data->start_index)
// 				add_room(&maze, data->rooms[i], 0);
// 			else if (i == data->end_index)
// 				add_room(&maze, data->rooms[i], 1);
// 			else
// 				add_room(&maze, data->rooms[i], 2);
// 			// printf("room added: %s\n", maze->name);
// 		}
// 		i++;
// 	}
// printf("initial mapping done, entering link_rooms\n");
// 	link_rooms(&maze, data->links);
// 	return (maze);
// }
