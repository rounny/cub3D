/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:39:53 by lemmon            #+#    #+#             */
/*   Updated: 2022/06/02 19:34:12 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

// int	is_map(char *line, t_map *map)
// {
// 	if (line[0] == ' ' || line[0] == '1')
// 		return (1);
// 	return (0);
// }


void	parsing(t_map *map)
{
	char	**line;
	int		i;
	
	map->flag_line = 0;
	line = get_line_file(map->fd, map);
	int j = 0;
	while (line[j]) { //
		printf ("%d %s\n", j, line[j]);
		++j;
	} //
	i = 0;
	while (i < map->count_line)
	{
		map->count_argc = 0;
		if (is_direction(line[i], map))
			parse_direction(line[i], map);
		else if (is_floor_ceiling(line[i], map))
			parse_floor_ceiling(line[i], map);
		// else if (is_map(line[i], map))
		// 	parse_map(line, map);
		// else
		// {
		// 	printf("line - %s\n", line[i]);
		// 	ft_error("invalid content of map, hhmm...");
		// }
		++i;
	}
}
