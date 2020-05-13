/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leminAlgo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 11:58:05 by rengelbr          #+#    #+#             */
/*   Updated: 2020/05/13 13:27:46 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/colony.h"
#include <stdio.h>

void	find_path(t_log *data)
{
	t_room **rooms;

	rooms = data->rooms;
	for (int i = 0; rooms[i]; i++) {
		printf(rooms[i]->name)
	}
}
