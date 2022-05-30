/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:39:53 by lemmon            #+#    #+#             */
/*   Updated: 2022/05/30 18:45:14 by lemmon           ###   ########.fr       */
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

void	parsing(t_map *map)
{
	char	**line;
	
	line = get_line_file(map->fd);
	int i = 0;
	while (line[i]) {
		printf ("%s\n", line[i]);
		++i;
	}
	int j = 0;
	// int k = 0;
	printf("line - %s\n", line[j]);
	// while (j < 20) // из get_line_file взять количество получившихся строк
	// {
	// 	int  k = 0;
	// 	if ((line[j][k] == "NO") || (line[j][k] == "SO")
	// 		|| (line[j][k] == "WE") || (line[j][k] == "EA")
	// 		parse_direction(line[j][k]);
	// 	else if ((line[j][k] == "F") || (line[j][k]] == "C"))
	// 		parse_floor_ceiling(line[j][k]); // возможно лучше посылать именно указатель
	// 	else if (line[])
	// }
	// choice_parcing_path()
	
	
}
