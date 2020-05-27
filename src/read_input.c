/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 07:23:10 by rengelbr          #+#    #+#             */
/*   Updated: 2020/05/24 11:50:03 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This file contains functions that read from standard output the data needed
**	to build the "ant farm". Depending on the input, these functions will call
**	functions from other files to complete the game.
*/

#include "../libft/libft.h"
#include "../includes/colony.h"

#include <stdio.h>

t_data		*read_input(char *line)
{
	t_data *raw_data;
	t_data *temp_data;
	t_data *temp;

	raw_data = NULL;
	while (get_next_line(0, &line))
	{
		temp = (t_data *)malloc(sizeof(t_data));
		temp->line = ft_strdup(line);
		temp->next = NULL;
		if (!raw_data)
			raw_data = temp;
		else
		{
			temp_data = raw_data;
			while (temp_data->next)
				temp_data = temp_data->next;
			temp_data->next = temp;
		}
		free(line);
	}
	return (raw_data);
}
