/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:28:51 by jrheeder          #+#    #+#             */
/*   Updated: 2020/05/21 16:18:09 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/colony.h"

int main()
{
	char	*line;
	t_str	*raw_data;
	t_log	*node_array;
	t_path	*the_path;
	t_path	*new_path;

	line = NULL;
	raw_data = read_input(line);
	validate_file(raw_data);
	node_array = create_node_array(raw_data);
	// print_map(node_array);
	the_path = algo(node_array);
	path_cleanup(&the_path);
	// free_map(node_array);
}
