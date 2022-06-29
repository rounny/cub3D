/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:35:46 by lemmon            #+#    #+#             */
/*   Updated: 2022/06/08 14:07:15 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	count_width(char **array, t_map *map, int index)
{
	int	i;
	int	j;
	int	count;
	
	i = 0;
	j = 0;
	count = 0;
	while (index < map->count_line)
	{
		i = 0;
		while (array[j][i])
			i++;
		if (i > count)
			count = i;
		j++;
		index++;
	}
	map->width = count;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

void	ft_error(char *msg)
{
	printf("Error: %s\n", msg);
	exit(1);
}

char	*ft_chrjoin(char *s1, char s2)
{
	char	*tmp;
	long	i;

	i = -1;
	if (s1)
	{
		tmp = malloc(sizeof(char) * ((ft_strlen(s1) + 2)));
		if (!tmp)
			return (NULL);
		while (s1[++i])
			tmp[i] = s1[i];
		tmp[i] = s2;
		tmp[i + 1] = '\0';
		free (s1);
	}
	else
	{
		tmp = malloc(sizeof(char) * 2);
		if (!tmp)
			return (NULL);
		tmp[0] = s2;
		tmp[1] = '\0';
	}
	return (tmp);
}

char	**get_line_file(int fd, t_map *map)
{
	char	ch;
	char	*res;
	char	**string;
	int		i;

	i = -1;
	res = NULL;
	string = NULL;
	if (fd >= 0)
	{
		while (read(fd, &ch, 1))
			res = ft_chrjoin(res, ch);
		res = ft_chrjoin(res, '\0');
		string = ft_split_cub(res, '\n', map);
		if (!string)
			return (NULL);
		return (string);
	}
	return (NULL);
}
