#include "../includes/colony.h"
#include <stdio.h>

int validate_file(t_data *data)
{
	int start;
	int end;
	int phase;
	t_data *temp;

	start = -1;
	end = -1;
	phase = 0;
	temp = data;
	// Phase 0 = getting the number of ants.
	// Phase 1 = Finding ##start and ##end AND setting up room array
	// Phase 2 = the rooms getting linked
	// Phase 3 = Completed successfully and return (1);
	while (temp != NULL)
	{
		if (ft_only_digits(temp->line) && phase == 0)
			phase = 1;
		if (ft_strequ(temp->line, "##start") && phase == 1)
		{
			if (start != -1)
				ORDER_ERR;
			start = 1;
		}
		else if (ft_strequ(temp->line, "##end") && phase == 1)
		{
			if (end != -1)
				ORDER_ERR;
			end = 1;
		}
		else if (is_room(temp->line))
		{
			if (phase != 1)
				ORDER_ERR;
			if (!validate_room_name(temp->line))
			{
				ft_putstr_fd("Error: Room names wrong\n", 2);
				return (0);
			}
			if (start == 1)
				start = 0;
			else if (end == 1)
				end = 0;
		}
		else if (is_link(temp->line))
		{
			if (phase == 1)
				phase = 2;
			if (phase == 0 || start != 0 || end != 0)
				ORDER_ERR;
		}
		temp = temp->next;
	}
	if (phase != 2)
	{
		ft_putstr("Error: Room links wrong\n");
		return (0);
	}
	return (1);
}
