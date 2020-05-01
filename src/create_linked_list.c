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
#include "../libft/libft.h"
#include <stdio.h>

/*
int main()
{
  char  *line;
  // Required variables
  int i;
  t_room **node_array;
  t_room *node;
  i = 0;
  node_array = (t_room **)malloc(sizeof(t_room *));
  while (get_next_line(0, &line))
  {
    // Required code inside get_next_line() loop
    if (is_room(line)) {
      node = create_node(line);
      node_array[i] = (t_room *)malloc(sizeof(node));
      node_array[i] = node;
      i++;
    }
  }
  i = 0;
  while (node_array[i]) {
    printf("node_array[%d]:\n\tname: %s; x: %d; y: %d\n\n", i, node_array[i]->name, node_array[i]->x, node_array[i]->y);
    i++;
  }
}
*/

t_room *create_node(t_str line)
{
  t_room *node;
  char  **room_data;

  room_data = ft_strsplit(line, ' ');
  node = (t_room *)malloc(sizeof(t_room));
  node->name = (t_str)malloc(ft_strlen(room_data[0]) * sizeof(char));
  node->name = room_data[0];
  node->x = atoi(room_data[1]);
  node->y = atoi(room_data[2]);
  return (node);
}