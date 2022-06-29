/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:37:45 by lemmon            #+#    #+#             */
/*   Updated: 2022/06/29 15:01:17 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

// libft
# include "./libft/libft.h"
// mlx
# include <mlx.h>
// printf
# include <stdio.h>
// exit
# include <stdlib.h>
// open
# include <fcntl.h>
// read
#include <unistd.h> 
// mathematica
#include <math.h>

# define WIDTH 	1000
# define HEIGHT 1000
# define KEY_ESC 53
# define KEY_CROSS 17
# define MASK_CROSS 131072L

typedef struct	s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*img_wall;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
	int		keycode[260];
	// t_map	*map;
}t_mlx;

typedef struct s_player
{
	float		x; //
	float		y; //
	float		a; // angle
	int		flag;
	char	direction; //
} t_player;

typedef struct s_map
{
	int			fd;
	int			width;
	int			height;
	int 		**map; //
	char 		**test2;
	int			*test;
	char		*north_path; //
	char		*south_path; //
	char		*west_path; //
	char		*east_path; //
	int			count_line;
	int			count_argc;
	int			flag_line;
	int			flag_north;
	int			flag_south;
 	int			flag_east;
	int			flag_west;
	int			flag_map;
	int			flag_f;
	int			flag_c;
	int			f_red; //
	int			f_green; //
	int			f_blue; //
	int			c_red; //
	int			c_green; //
	int			c_blue; //
	t_player	pers;
	t_mlx		mlx; //
	
} t_map;


int		ft_strcmp(const char *s1, const char *s2);
void	ft_error(char *msg);
char	*ft_chrjoin(char *s1, char s2);
char	**get_line_file(int fd, t_map *map);

void	parsing(t_map *map, int ac, char **av);
void	check_line(char *line);

char	*get_next_line(int fd);
char	**ft_split_cub(char const *s, char c, t_map *map);

// void	parse_direction(char *line);
void	parse_direction(char *line, t_map *map);
int		is_direction(char *line, t_map *map);

int		is_floor_ceiling(char *line, t_map *map);
void	parse_floor_ceiling(char *line, t_map *map);

void	check_map(int ac, char **av, t_map *map);
int	check_extention(char *av, int flag);

int		is_map(char *line);
void	start_parse_map(char **array, t_map *map, int index);
void	count_width(char **array, t_map *map, int index);
void	check_empty(t_map *map);

// int draw(t_mlx *mlx);
int draw(t_map *map);

void	free_map(t_map *map);


#endif
