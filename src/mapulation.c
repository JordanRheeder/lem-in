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

void	free_path_node(t_path	*temp_curr, t_path *temp_prev)
{
  t_path *temp_next;

  temp_next = temp_curr->next;
  free(temp_curr->room_name);
  free(temp_curr);
  temp_prev->next = temp_next;
}

void path_cleanup(t_path	*the_path)
{
  
}