/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:39:53 by lemmon            #+#    #+#             */
/*   Updated: 2022/05/31 20:23:08 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// void	id_direction(char *line)

int		ft_wdcounter(char const *str, char c)
{
	int i;
	int words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

void	check_line(char *line)
{
	int	north_flag = 0;
	int	south_flag = 0;
	int	west_flag = 0;
	int	east_flag = 0;
	
	if ((line[0] == 'N' && line[1] == 'O') || (line[0] == 'S' && line[1] == 'O') 
		|| (line[0] == 'W' && line[1] == 'E') || (line[0] == 'E' &&line[1] == 'A'))
		{
			if (line[0] == 'N')
				north_flag = 1;
			else if (line[0] == 'S')
				south_flag = 1;
			else if (line[0] == 'W')
				west_flag = 1;
			else if (line[0] == 'E')
				east_flag = 1;
			else
				ft_error("invalid directions");
			// map->north_path = s21_strtok(line, " ");§
			printf("north - %d\n", north_flag);
			printf("south - %d\n", south_flag);
			printf("west - %d\n", west_flag);
			printf("east - %d\n", east_flag);
		}
}

// void	parsing(t_map *map)
// {
// 	char	*test_line;
// 	// int		bytes;
// 	int count = 0;
// 	// char *buf = NULL;0
	
// 	// bytes = read(map->fd, &buf, 1);
// 	int i = 0;
// 	while (i < 38)
// 	{
// 			// test_line = get_next_line(map->fd);
// 			test_line = get_next_line(map->fd);
// 			// check_line(test_line);
// 			// check_direction(test_line); //стороны света
// 			// check_floor_ceiling(test_line);
// 			//parse
// 			count++;
// 			printf("line %d - //%s", count, test_line);
// 			i++;
// 			// printf("bytes - %d\n", bytes);
// 	}
// }

/* ************************************************************************ */

// void	parsing(t_map *map)
// {
// 	char	*test_line;
// 	// int		bytes;
// 	int count = 0;
// 	char *buf = NULL;
	
// 	// bytes = read(map->fd, &buf, 1);
	
// 	while (read(map->fd, &buf, 1))
// 	{
// 			// test_line = get_next_line(map->fd);
// 			test_line = get_next_line(map->fd);
// 			// printf("%s", test_line);
// 			// check_line(test_line);
// 			// check_direction(test_line); //стороны света
// 			// check_floor_ceiling(test_line);
// 			//parse
// 			count++;
// 			printf("line %d - //%s\n ", count, test_line);
// 			// bytes = read(map->fd, &buf, 1);
// 			// printf("bytes - %d\n", bytes);
// 	}
// }

int	is_direction(char *line, t_map *map)
{
	if ((line[0] == 'N' && line[1] == 'O' && map->flag_north == 0) 
		|| (line[0] == 'S' && line[1] == 'O' && map->flag_south == 0)
		|| (line[0] == 'W' && line[1] == 'E' && map->flag_west == 0)
		|| (line[0] == 'E' && line[1] == 'A' && map->flag_east == 0))
		return (1);
	return (0);
}

// int	is_floor_ceiling(char *line, t_map map)
// {
// 	if (line[0] == 'F' || line[0] == 'C')
// 		return (1);
// 	return (0);
// }

// int	is_map(char *line, t_map *map)
// {
// 	if (line[0] == ' ' || line[0] == '1')
// 		return (1);
// 	return (0);
// }
void	check_dublicate_direction(char *line, t_map *map)
{
	if (line[0] == 'N' && line[1] == 'O')
		map->flag_north = 1;
	else if (line[0] == 'S' && line[1] == 'O')
		map->flag_south = 1;
	else if (line[0] == 'W' && line[1] == 'E')
		map->flag_west = 1;
	else if(line[0] == 'E' && line[1] == 'A')
		map->flag_east = 1;
}

void	parse_direction(char *line, t_map *map)
{
	char **array;
	int	fd;
	char *buf;
	
	buf = NULL;
	check_dublicate_direction(line, map);
	array = ft_split(line, ' ');
	if (!array[1] || array[2])
		ft_error("invalid content of direction, hmm...");
	if (check_extention(line, 2)) 
		ft_error("need only '.xpm' extention"); // or '.png'
	fd = open(array[1], O_RDONLY);
	if (fd < 0)
		ft_error("can't open this file, sorry..");
	// printf("fd - %d\n", fd);
	if (read(fd, &buf, 1) <= 0)
		ft_error("can't read this file, sorry..");
	// int bytes = read(fd, &buf, 1);
	// printf("bytes - %d\n", bytes);
	
}

void	parsing(t_map *map)
{
	char	**line;
	int		i;
	
	line = get_line_file(map->fd, map);
	int j = 0;
	while (line[j]) { //
		printf ("%d %s\n", j, line[j]);
		++j;
	} //
	i = 0;
	while (i < map->count_line)
	{
		if (is_direction(line[i], map))
			parse_direction(line[i], map);
		// else if (is_floor_ceiling(line[i], map))
		// 	parse_floor_ceiling(line[i], map);
		// else if (is_map(line[i], map))
		// 	parse_map(line, map);
		else
		{
			printf("line - %s\n", line[i]);
			ft_error("invalid content of map, hhmm...");
		}
		++i;
	}
}
