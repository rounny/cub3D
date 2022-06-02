/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:42:07 by lemmon            #+#    #+#             */
/*   Updated: 2022/06/02 19:33:07 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	is_direction(char *line, t_map *map)
{
	if ((line[0] == 'N' && line[1] == 'O' && map->flag_north == 0) 
		|| (line[0] == 'S' && line[1] == 'O' && map->flag_south == 0)
		|| (line[0] == 'W' && line[1] == 'E' && map->flag_west == 0)
		|| (line[0] == 'E' && line[1] == 'A' && map->flag_east == 0))
		return (1);
	return (0);
}

void	fill_direction(char *line, t_map *map, char *array)
{
	if (line[0] == 'N' && line[1] == 'O')
	{
		map->flag_north = 1;
		map->north_path = array;
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		map->flag_south = 1;
		map->south_path = array;
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		map->flag_west = 1;
		map->west_path = array;
	}
	else if(line[0] == 'E' && line[1] == 'A')
	{
		map->flag_east = 1;
		map->east_path = array;
	}
}

void	parse_direction(char *line, t_map *map)
{
	char **array;
	int	fd;
	char *buf;
	
	buf = NULL;
	// array = ft_split(line, ' ');
	array = ft_split_cub(line, ' ', map);
	if (map->count_argc != 2)
		ft_error("invalid content of direction, hmm...");
	// if (!array[1] || array[2]) // переписать на map->count_argc;
	// 	ft_error("invalid content of direction, hmm...");
	if (check_extention(line, 2)) 
		ft_error("need only '.xpm' extention"); // or '.png'
	fd = open(array[1], O_RDONLY);
	if (fd < 0)
		ft_error("can't open this file, sorry..");
	if (read(fd, &buf, 1) <= 0)
		ft_error("can't read this file, sorry..");
	fill_direction(line, map, array[1]);
	// int bytes = read(fd, &buf, 1);
	// printf("bytes - %d\n", bytes);
}
