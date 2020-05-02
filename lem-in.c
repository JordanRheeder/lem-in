/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:28:51 by jrheeder          #+#    #+#             */
/*   Updated: 2020/05/02 11:39:36 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/colony.h"
#include <stdio.h>
int main()
{
	char *line;
	t_str *raw_data;
	// t_log *ret;
	// t_room **maze;

	line = NULL;
	// maze = (t_room **)malloc(sizeof(t_room *));
printf("reading input\n");
	raw_data = read_input(line);				//*****DOES NOT LEAK****
	int i = 0;
	while (raw_data[i]) {
		printf("%s\n", raw_data[i]);
		i++;
	}
printf("input read\n");
printf("mapping input\n");
// 	maze = init_rooms(ret);				//*****SOMEWHAT LEAKY******
// printf("input initialized\n");
}
