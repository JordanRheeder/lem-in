/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:03:12 by rengelbr          #+#    #+#             */
/*   Updated: 2020/05/19 15:10:16 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/colony.h"

#include <stdio.h>

// Checking whether it is a command. By identifying if input has ##
int		is_command(char *line)
{
	if (ft_strequ(line, "##start") || ft_strequ(line, "##end"))
		return (1);
	return (0);
}

int		is_comment(char *line)
{
	if (line[0] == '#' && line[1] != '#')
		return (1);
	return (0);
}

// Checking whether input is a room. By checking if wordcount is three.
int		is_room(char *line)
{
	char** split_room;

	ft_putstr(line);
	ft_putstr("\n");
	if (ft_wordcount(line, ' ') == 3)
	{
		split_room = ft_strsplit(line, ' ');
		if (ft_only_digits(split_room[1]) && ft_only_digits(split_room[2])
			 && ft_strncmp("L", split_room[0], 1))
		{
			ft_free_two_d_arr((void**)split_room);
			return (1);
		}
		else
			NAME_ERR;
		ft_free_two_d_arr((void**)split_room);
	}
	return (0);
}

// Checking whether if there is a - between numbers. **Could cause negative ants to think it's a link
int		is_link(char *line)
{
	char *str;

	str = line;
	if (ft_strchr(str, '-') )
		return (1);
	return (0);
}
