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

t_room *find_room(t_room **rooms, t_room *room)
{
  int i;

  i = 0;
  while (rooms[i])
  {
    if (ft_strequ(rooms[i]->name, room->name))
      return (rooms[i]);
    i++;
  }
  return (rooms[i]);
}

t_links *create_link_node()
{
  t_links * node;

  node = (t_links *)malloc(sizeof(t_links));
  node->next = NULL;
  return (node);
}