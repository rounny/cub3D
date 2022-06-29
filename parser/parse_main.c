/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:39:53 by lemmon            #+#    #+#             */
/*   Updated: 2022/06/29 15:04:14 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	parsing(t_map *map, int ac, char **av)
{
	char	**line;
	int		i;

	map->flag_line = 0;
	map->fd = open(av[ac - 1], O_RDONLY);
	line = get_line_file(map->fd, map);
	i = -1;
	while (++i < map->count_line)
	{
		map->count_argc = 0;
		if (is_direction(line[i], map))
			parse_direction(line[i], map);
		else if (is_floor_ceiling(line[i], map))
			parse_floor_ceiling(line[i], map);
		else if (is_map(line[i]))
		{
			start_parse_map(line + i, map, i);
			break ;
		}
		else
			ft_error("invalid content of map, hhmm...");
	}
}
