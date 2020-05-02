// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   validation.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: rengelbr <rengelbr@42.fr>                  +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2019/09/05 11:33:09 by jrheeder          #+#    #+#             */
// /*   Updated: 2019/09/20 09:53:43 by rengelbr         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../includes/colony.h"
// #include "../libft/libft.h"
// #include <stdio.h>

// char	*get_room_name(char *room)
// {
// 	char	*retRoomName;
// 	char	**roomName;

// 	roomName = ft_strsplit(room, ' ');
// 	retRoomName = ft_strdup(roomName[0]);
// 	return (retRoomName);
// }

// int     check_name(t_log *data)
// {
//     int i;
//     int j;

//     i = 0;

//     while (data->rooms[i])
//     {
//         j = i + 1;
//         while (data->rooms[j])
//         {
//             if (ft_strequ(data->rooms[i], data->rooms[j]))
//                 return (0);
//             j++;
//         }
//         i++;
//     }
//     return (1);
// }

// int     check_name_XY(t_log *data)
// {
// 	int i;
// 	int j;
// 	char **roomName;
// 	char **roomNameComp;

// 	roomNameComp = NULL;
// 	roomName = NULL;
// 	i = 0;
// 	j = 1;
// 	while(data->rooms[i])
// 	{
// 		roomName = ft_strsplit(data->rooms[i], ' ');
// 		while (data->rooms[j])
// 		{
// 			roomNameComp = ft_strsplit(data->rooms[j], ' ');
// 			if (ft_strequ(roomName[1], roomNameComp[1])
// 					&& ft_strequ(roomName[2], roomNameComp[2]))
// 				return (0);
// 			j++;
// 		}
// 		i++;
//     }
//     i = 0;
//     return (1);
// }

// int		check_links(t_log *data)
// {
// 	int i;
// 	int j;
// 	int k;
// 	int linkAmnt;
// 	char *names;
// 	char *curLink;
// 	char **linkNames;

// 	i = 0;
// 	j = 0;
// 	k = 0;
// 	linkAmnt = 0;
// 	while (data->links[linkAmnt])
// 		linkAmnt++;
// 	names = NULL;
// 	curLink = NULL;
// 	while (i < linkAmnt)
// 	{
// 		curLink = ft_strdup(data->links[i]);
// 		linkNames = ft_strsplit(curLink, '-');
// 		j = 0;
// 		while (data->rooms[j])
// 		{
// 			names = get_room_name(data->rooms[j]);
// 			if (ft_strequ(names, linkNames[0]))
// 			{
// 				k = 0;
// 				while (data->rooms[k])
// 				{
// 					names = get_room_name(data->rooms[k]);
// 					if (ft_strequ(names, linkNames[1]))
// 						break;
// 					k++;
// 					if (!data->rooms[k])
//  						return (0);
// 				}
// 				break;
// 			}
// 			j++;
// 			if (!data->rooms[j])
//  				return (0);
// 		}
// 		i++;
// 	}
// 	return (1);
// }

// void		validate(t_log *data)
// {
// 	if (!(check_links(data)))
// 		LINK_ERR;
// 	if (!(check_name(data)))
// 		NAME_ERR;
// 	if (!(check_name_XY(data)))
// 		XY_ERR;
// }
