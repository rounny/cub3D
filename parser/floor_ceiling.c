/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:42:12 by lemmon            #+#    #+#             */
/*   Updated: 2022/06/02 19:19:13 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int	ft_isspace(char s)
{
	if (s == ' ' || s == '\t' || s == '\n' || \
	s == '\v' || s == '\f' || s == '\r')
		return (1);
	return (0);
}

int	ft_atoi_cub(const char *str)
{
	size_t	i;
	int		num;
	int		count_num;
	size_t		j;

	count_num = 0;
	i = 0;
	num = 0;
	j = 0;
	while (str[j])
	{
		if ((str[j] >= '0' && str[j] <= '9') || str[j] == ' ')
			j++;
		else
			ft_error("wrong color argument");
	}
	while (ft_isspace(str[i]))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i++] - '0';
	}
	if (num < 0 || num > 255)
		ft_error("wrong color argument");
	return (num);
}

void	fill_color(char *line, char **array, t_map *map)
{
	if (*line == 'F')
	{
		map->f_red = ft_atoi_cub(array[0]);
		printf("f_red - %d\n", map->f_red);
		map->f_green = ft_atoi_cub(array[1]);
		printf("f_green - %d\n", map->f_green);
		map->f_blue = ft_atoi_cub(array[2]);
		printf("f_blue - %d\n", map->f_blue);
	}
	else if (*line == 'C')
	{	
		map->c_red = ft_atoi_cub(array[0]);
		printf("c_red - %d\n", map->c_red);
		map->c_green = ft_atoi_cub(array[1]);
		printf("c_green - %d\n", map->c_green);
		map->c_blue = ft_atoi_cub(array[2]);
		printf("c_blue - %d\n", map->c_blue);
	}
}

void	parse_floor_ceiling(char *line, t_map *map)
{
	char	**array;

	map->h = 0;
	array = ft_split_cub(line + 1, ',', map);
	// array = ft_split(line + 1, ',');// 'line + 1' - скипаем ключ F/C 
	for (int  i = 0; array[i]; ++i)
	{
		printf("array - %s\n", array[i]);
	}
	if (map->count_argc != 3)
		ft_error("wrong number of color argumets");
	fill_color(line, array, map);
	if (line[0] == 'F')
		map->flag_f = 1;
	if (line[0] == 'C')
		map->flag_c = 1;
	printf("count  - %d\n", map->count_argc);
	
}

int	is_floor_ceiling(char *line, t_map *map)
{
	if ((line[0] == 'F' && map->flag_f == 0)
		|| (line[0] == 'C' && map->flag_c == 0))
		return (1);
	return (0);
}

