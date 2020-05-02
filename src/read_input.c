/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 07:23:10 by rengelbr          #+#    #+#             */
/*   Updated: 2020/05/02 12:22:52 by rengelbr         ###   ########.fr       */
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

t_str		*read_input(char *line)
{
	int i;
	t_str *raw_data;

	i = 0;
	raw_data = (t_str *)malloc(sizeof(t_str) * 2048);
	while (get_next_line(0, &line))
	{
		raw_data[i] = ft_strdup(line);
		i++;
		free(line);
	}
	// free(raw_data[i]);
	raw_data[i] = NULL;
	return (raw_data);
}
