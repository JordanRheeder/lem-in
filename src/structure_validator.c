#include "../includes/colony.h"
#include <stdio.h>

int validate_file(t_str *data)
{
	int start;
	int end;
	int phase;
	int i;

	start = -1;
	end = -1;
	phase = 0;
	i = 0;
	// Phase 0 = getting the number of ants.
	// Phase 1 = Finding ##start and ##end AND setting up room array
	// Phase 2 = the rooms getting linked
	// Phase 3 = Completed successfully and return (1);
	while (data[i])
	{
		if (ft_only_digits(data[i]) && phase == 0)
			phase = 1;
		if (ft_strequ(data[i], "##start") && phase == 1)
			start = 1;
		else if (ft_strequ(data[i], "##end") && phase == 1)
			end = 1;
		else if (is_room(data[i]))
		{
			if (phase != 1)
				ORDER_ERR;
			if (!validate_room_name(data[i]))
				NAME_ERR;
			if (start == 1)
				start = 0;
			else if (end == 1)
				end = 0;
		}
		else if (is_link(data[i]))
		{
			if (phase == 1)
				phase = 2;
			if (phase == 0 || start < 0 || end < 0)
				ORDER_ERR;
		}
		ft_putendl(data[i]);
		i++;
	}
	return (1);
}
