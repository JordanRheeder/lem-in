/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:28:51 by hde-vos           #+#    #+#             */
/*   Updated: 2019/09/22 18:06:13 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/colony.h"

// typedef struct		s_links
// {
// 	struct	s_room	*room;
// 	struct	s_links	*next;
// 	struct	s_links	*prev;
// }									t_links;

// typedef struct		s_room
// {
// 	t_str						name;
// 	int							dead_end;
// 	int							visited;
// 	unsigned int		room_type : 2;
// 	unsigned int		x : 8;
// 	unsigned int		y : 8;
// 	struct	s_links	*room_links;
// 	struct	s_room	*next;
// }									t_room;

// typedef struct		s_log
// {
// 	int							ant_amnt;
// 	int							start_index;
// 	int							end_index;
// 	int							room_count;
// 	t_str						*links;
// 	struct	s_room	**rooms;
// }									t_log;

t_links	*find_least_visited(t_links	*room_links)
{
  t_links *current_link;
  t_links *next_link;
  t_links *ret_link;

  current_link = room_links;
  ret_link = NULL;
  if (current_link->next)
  {
    next_link = current_link->next;
    ft_putstr(current_link->next->room->name);
    while (next_link)
    {
      ft_putstr("\n====\n");
      ft_putstr(next_link->room->name);
      ft_putstr("\n====\n");
      if (current_link->room->visited < next_link->room->visited)
        ret_link = current_link;
      current_link = current_link->next;
      if (next_link->next)
        next_link = next_link->next;
      else
        return (ret_link);
    }
  }
  else if (!current_link->next)
  {
    ft_putstr("\n====\nElse: ");
    ft_putstr(current_link->room->name);
    ft_putstr("\n====\n");
    return (current_link);
  }
  return (NULL);
}

void algo(t_log *node_array)
{
  t_room *current_room;

  current_room = node_array->rooms[node_array->start_index];
  while (current_room->room_links->room->name)
  {
    current_room->visited++;
    ft_putstr("\n\n");

    ft_putstr("Name: ");
    ft_putstr(current_room->room_links->room->name);
    ft_putstr("; Type: ");
    ft_putnbr(current_room->room_links->room->room_type);

    current_room = find_least_visited(current_room->room_links)->room;
  }
}