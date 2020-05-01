/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colony.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:35:08 by jrheeder          #+#    #+#             */
/*   Updated: 2019/09/28 07:04:38 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define NAME_ERR {ft_putstr_fd("Error: Room names wrong\n", 2); exit(2);}
# define LINK_ERR {ft_putstr_fd("Error: Room links wrong\n", 2); exit(2);}
# define XY_ERR {ft_putstr_fd("Error: Room coordinates wrong\n", 2); exit(2);}
# define ORDER_ERR {ft_putstr_fd("Error: Input order wrong\n", 2); exit(2);}
#include "../libft/libft.h"

typedef char *t_str;

typedef struct		s_room
{
	unsigned int	room_type : 2;
	t_str			name;
	unsigned int	x : 8;
	unsigned int	y : 8;
	unsigned int	visited;
	struct s_room	*next;
	struct s_room	**room_links;
}					t_room;

typedef struct		s_log
{
	int				ant_amnt;		//make unsigned ints
	int				start_index;	//make unsigned ints
	int				end_index;		//make unsigned ints
	t_str			*rooms;
	t_str			*links;
}					t_log;

/*
**	read_input functions
*/
int		is_command(char *line);
int		is_comment(char *line);
int		is_room(char *line);
int		is_link(char *line);
t_log	*read_input(char *line);

/*
**	validation functions
*/
char	*get_room_name(char *room);
int		check_name(t_log *data/*, int phase*/);
int		check_name_XY(t_log *data);
int		check_links(t_log *data);
t_log	*read_input(char *line);
void	validate(t_log *data);

/*
**	pathfinder functions
*/
char	**get_linked_rooms(t_str name, t_str *all_links);
int		get_coordinate(t_str room, char type);
t_room	*new_maze(t_str room, unsigned int type);
void	add_room(t_room **maze, t_str room, unsigned int type);
t_room	*init_rooms(t_log *data);

/*
**	linked list functions
*/
t_room *create_node(t_str line)

#endif
