/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colony.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:35:08 by jrheeder          #+#    #+#             */
/*   Updated: 2020/05/24 17:32:16 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
#	define LEM_IN_H
# define INTMIN -2147483648
# define INTMAX 2147483648

#define NAME_ERR                                  \
{                                               \
	ft_putstr_fd("Error: Room names wrong\n", 2); \
	exit(2);                                      \
}
#define LINK_ERR                                  \
{                                               \
	ft_putstr_fd("Error: Room links wrong\n", 2); \
	exit(2);                                      \
}
#define XY_ERR                                          \
{                                                     \
	ft_putstr_fd("Error: Room coordinates wrong\n", 2); \
	exit(2);                                            \
}
#define ORDER_ERR									\
{													\
	ft_putstr_fd("Error: Input order wrong\n", 2);	\
	exit(2);										\
}
#define SOLVE_ERR								\
{												\
	ft_putstr_fd("Error: Cannot solve\n", 2);	\
	exit(2);									\
}
#include "../libft/libft.h"
#include <stdio.h>

typedef char		*t_str;

typedef struct		s_links
{
	struct	s_room	*room;
	struct	s_links	*next;
	struct	s_links	*prev;
}					t_links;

typedef struct		s_room
{
	t_str			name;
	int				dead_end;
	int				visited;
	unsigned int	room_type;
	unsigned int	x : 8;
	unsigned int	y : 8;
	struct	s_links	*room_links;
	struct	s_room	*next;
}					t_room;

typedef struct		s_log
{
	int				ant_amnt;
	int				start_index;
	int				end_index;
	int				room_count;
	t_str			*links;
	struct	s_room	**rooms;
}					t_log;

typedef struct		s_path
{
	t_str			room_name;
	struct 		s_path	*next;
}					t_path;

typedef struct		s_ants
{
	int			ant_name;
	int			moves;
	struct	s_path *room;
	struct	s_ants *next;
	struct	s_ants *prev;
}					t_ants;

typedef struct		s_data
{
	t_str			line;
	struct	s_data	*next;
}					t_data;


/*
**	read_input functions
*/
int		is_command(char *line);
int		is_comment(char *line);
int		is_room(char *line);
int		is_link(char *line);
t_data		*read_input(char *line);

/*
**	validation functions
*/
int		check_name(t_log *data /*, int phase*/);
int		check_name_XY(t_log *data);
int		check_links(t_log *data);
void	validate(t_log *data);
int		validate_file(t_data *data); //new
int		validate_room_name(char *line);
int		validate_links(t_log *data, t_data *input_data);

/*
**	pathfinder functions
*/
char	**get_linked_rooms(t_str name, t_str *all_links);
int		get_coordinate(t_str room, char type);
t_room	*new_maze(t_str room, unsigned int type);
void	add_room(t_room **maze, t_str room, unsigned int type);
t_room	*init_rooms(t_log *data);
void	find_path(t_log *data);

/*
**	linked list functions
*/
t_room	*create_node(t_str line);
t_log	*create_node_array(t_data *raw_data);
t_log	*create_links(t_log *node_array, t_data *raw_data, int i);

/*
**	helper functions
*/
int		room_count(t_data *raw_data);
t_room	*find_room(t_log *data, t_str room_name);
void	print_map(t_log *node_array);
void	free_room(t_room *room);
void	free_map(t_log *node_array);
void	free_path(t_path *the_path);
void	free_data(t_data *data);
t_path	*start_path(t_str room_name);
void	add_to_path(t_path *the_path, t_str room_name);
t_path	*copy_path(t_path *path);
t_path *shortest_path(t_path **paths, int path_count);

/*
**	helper functions2
*/
void ft_putroom(int ant_name, char *room_name);

/*
**	algo functions
*/
t_path	*algo(t_log *node_array);
void	find_path(t_log *data);
t_links *find_least_visited(t_links *room_links);

#endif
