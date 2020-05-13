/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:28:51 by jrheeder          #+#    #+#             */
/*   Updated: 2020/05/13 13:56:07 by rengelbr         ###   ########.fr       */
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
	printf("input stored\n");
	find_path(node_array);
	// TODO: Perform algorithm
	// TODO: Print everything
}
