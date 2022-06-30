/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:18:50 by lemmon            #+#    #+#             */
/*   Updated: 2022/06/30 14:48:13 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	is_map(char *line)
{
	if (line[0] == ' ' || line[0] == '1')
		return (1);
	return (0);
}

static void	check_player(char array, t_map *map, int i, int j)
{
	if (map->pers.flag == 0)
	{
		map->pers.flag = 1;
		map->pers.x = i;
		map->pers.y = j;
		printf("x - %f  ||| y - %f \n", map->pers.x, map->pers.y);
		map->pers.direction = array;
		map->map[i][j] = 0;
	}
	else
		ft_error("map error");
}

static void	catch_exeption(char	**array, int i, int j, t_map *map)
{
	if ((i == 0 || j == 0 || i == map->height
			|| j == map->width) && array[i][j] == '0')
		ft_error("map error 234");
}

static	void	choose_direction(char dir, t_map *map)
{
	if (dir == 'N')
		map->pers.a = 3.14f;
	else if (dir == 'S')
		map->pers.a = 0;
	else if (dir == 'E')
		map->pers.a = 1.57f;
	else if (dir == 'W')
		map->pers.a = 4.71f;
}

void	parse_map_key(int i, int j, t_map *map, char **array)
{
	if (array[i][j] == '1' || array[i][j] == '0')
	{
		catch_exeption(array, i, j, map);
		map->map[i][j] = (int)array[i][j] - 48;
	}
	else if ((array[i][j] == 'N' || array[i][j] == 'S' || array[i][j] == 'W'
			|| array[i][j] == 'E'))
	{
		choose_direction(array[i][j], map);
		check_player(array[i][j], map, i, j);
	}
	else if (array[i][j] != ' ' && array[i][j] != '\n' && array[i][j] != '\0')
		ft_error("map error55");
}
