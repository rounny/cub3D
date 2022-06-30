/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_features.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:01:50 by lemmon            #+#    #+#             */
/*   Updated: 2022/06/30 13:45:59 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	check_first_line(int i, int j, t_map *map)
{		
	if (j == 0)
	{
		if (map->map[i][j + 1] == 0 || map->map[i + 1][j] == 0)
			ft_error("map_error_1");
	}
	else if (j == map->width - 1)
	{
		if (map->map[i][j - 1] == 0 || map->map[i + 1][j] == 0)
			ft_error("map_error_2");
	}
	else
	{
		if (map->map[i][j - 1] == 0 || map->map[i][j + 1] == 0
			|| map->map[i + 1][j] == 0)
			ft_error("map middle error 1");
	}
}

static void	check_last_line(int i, int j, t_map *map)
{		
	if (j == 0)
	{
		if (map->map[i - 1][j] == 0 || map->map[i][j + 1] == 0)
			ft_error("map_error_3");
	}
	else if (j == map->width -1)
	{
		if (map->map[i][j - 1] == 0 || map->map[i - 1][j] == 0)
			ft_error("map_error_4");
	}
	else
	{
		if (map->map[i][j - 1] == 0 || map->map[i][j + 1] == 0
			|| map->map[i - 1][j] == 0)
			ft_error("map middle error 2");
	}
}

static void	check_middle_line(int i, int j, t_map *map)
{
	if (j == 0)
	{
		if (map->map[i - 1][j] == 0 || map->map[i + 1][j] == 0
			|| map->map[i][j + 1] == 0)
			ft_error("map middle error 3");
	}
	else if (j == map->width - 1)
	{
		if (map->map[i - 1][j] == 0 || map->map[i + 1][j] == 0
			|| map->map[i][j - 1] == 0)
			ft_error("map middle error 4");
	}
	else
	{
		if (map->map[i][j - 1] == 0 || map->map[i][j + 1] == 0
			|| map->map[i - 1][j] == 0 || map->map[i + 1][j] == 0)
			ft_error("map heart error");
	}
}

static void	check_height_map(int i, int j, t_map *map)
{
	if (i == 0)
	{
		check_first_line(i, j, map);
	}
	else if (i == map->height - 1)
	{
		check_last_line(i, j, map);
	}
	else
	{
		check_middle_line(i, j, map);
	}
}

void	check_empty(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 8)
			{
				check_height_map(i, j, map);
			}
			++j;
		}
		++i;
	}
}
