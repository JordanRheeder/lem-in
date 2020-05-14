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

int main()
{
	char *line;
	t_str *raw_data;
	t_log *node_array;

	line = NULL;
	printf("Reading Input\n");
	raw_data = read_input(line);
	printf("Validating Input\n");
	validate_file(raw_data);
	printf("Storing Input\n");
	node_array = create_node_array(raw_data);
	// print_map(node_array);
	printf("====================\nStarting Algorithm\n");
	algo(node_array);
	printf("Algorithm Finished\n====================\n");
	free_map(node_array);
	// TODO: Perform algorithm
	// TODO: Print everything
}
