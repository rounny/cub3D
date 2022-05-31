/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:37:45 by lemmon            #+#    #+#             */
/*   Updated: 2022/05/31 20:10:55 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

// libft
# include "./libft/libft.h"
// # include "get_next_line.h"
// printf
# include <stdio.h>
// exit
# include <stdlib.h>
// open
# include <fcntl.h>
// read
#include <unistd.h>

typedef struct s_map
{
	int		fd;
	char	width;
	int		w;
	char	height;
	int		h;
	char 	**map;
	char	*north_path;
	char	*south_path;
	char	*west_path;
	char	*east_path;
	int		count_line;
	int		flag_north;
	int		flag_south;
	int		flag_east;
	int		flag_west;
	int		flag_map;
	
}t_map;


int		ft_strcmp(const char *s1, const char *s2);
void	ft_error(char *msg);
char	*ft_chrjoin(char *s1, char s2);
// char	**get_line_file(int fd);
char	**get_line_file(int fd, t_map *map);

void	parsing(t_map *map);
void	check_line(char *line);

char	*get_next_line(int fd);
char	**ft_split_cub(char const *s, char c, t_map *map);

// void	parse_direction(char *line);
void	parse_direction(char *line, t_map *map);
int	is_direction(char *line, t_map *map);
// int	is_direction(char *line);

void	check_map(int ac, char **av, t_map *map);
int	check_extention(char *av, int flag);

#endif
