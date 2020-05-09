/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:28:51 by jrheeder          #+#    #+#             */
/*   Updated: 2019/09/22 18:06:13 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/colony.h"
#include <stdio.h>
int main()
{
	char *line;
	t_str *raw_data;
	t_log *node_array;

	line = NULL;
	printf("reading input\n");
	raw_data = read_input(line);
	printf("validating input\n");
	validate_file(raw_data);
	printf("storing input\n");
	node_array = create_node_array(raw_data);
	int i = 0;
	while (node_array->rooms[i])
	{
		ft_putstr("Room Name: ");
		ft_putstr(node_array->rooms[i]->name);
		ft_putstr("; Linked Room Names: ");
		t_room *temp;
		temp = node_array->rooms[i]->room_links->room;
		while (temp)
		{
			ft_putstr(temp->name);
			ft_putstr(", ");
			temp = temp->next;
		}
		i++;
	}
	// TODO: Perform algorithm
	// TODO: Print everything
}
