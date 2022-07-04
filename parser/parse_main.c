/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:39:53 by lemmon            #+#    #+#             */
/*   Updated: 2022/07/04 11:51:10 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	parse_map(t_map *map, char **array)
{
	int	j;
	int	i;

	i = 0;
	while (i < map->height)
	{
		map->map[i] = ft_calloc_int(map->width, 8);
		j = 0;
		while (array[i][j])
		{
			parse_map_key(i, j, map, array);
			++j;
		}
		++i;
	}
}

void	start_parse_map(char **array, t_map *map, int index)
{
	count_width(array, map, index);
	map->pers.flag = 0;
	map->height = map->count_line - index;
	map->map = ft_calloc(map->height, sizeof(int *));
	parse_map(map, array);
	check_empty(map);
}

static	void	skip_next_space(char *line, int *i)
{
	while (line[*i] == ' ')
		++(*i);
}

void	parsing(t_map *map, int ac, char **av)
{
	char	**line;
	int		i;
	int		j;

	map->flag_line = 0;
	map->fd = open(av[ac - 1], O_RDONLY);
	line = get_line_file(map->fd, map);
	i = -1;
	while (++i < map->count_line)
	{
		j = 0;
		skip_next_space(line[i], &j);
		map->count_argc = 0;
		if (is_direction(line[i], map, j))
			parse_direction(line[i] + j, map);
		else if (is_floor_ceiling(line[i], map, j))
			parse_floor_ceiling(line[i] + j, map);
		else if (is_map(line[i], j))
		{
			start_parse_map(line + i, map, i);
			break ;
		}
		else
			ft_error("invalid content of map, hhmm...");
	}
}
