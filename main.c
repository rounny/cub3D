#include "cub.h"

// int	check_extention(char *av)
// {
// 	size_t	len;

// 	len = ft_strlen(av);
// 	if (av[len - 4] == '.' && av[len - 3] == 'c' 
// 		&& av[len - 2] == 'u' && av[len - 1] == 'b')
// 		return (0);
// 	else
// 		return (1);
// }

int	check_extention(char *av, int flag)
{
	size_t	len;

	len = ft_strlen(av);
	if (flag == 1)
	{
		if (av[len - 4] == '.' && av[len - 3] == 'c' 
			&& av[len - 2] == 'u' && av[len - 1] == 'b')
			return (0);
	}
	else if (flag == 2) // or '.png'
	{
		if (av[len - 4] == '.' && av[len - 3] == 'x'
			&& av[len - 2] == 'p' && av[len - 1] == 'm')
			return (0);
	}
	return (1);
}


void	check_map(int ac, char **av, t_map *map)
{	
	// int		fd;
	// int		bytes;
	char	*buf;

	buf = NULL;
	map->fd = open(av[ac - 1], O_RDONLY); // хорошо бы в структурку это все дело закинуть
	// printf("fd - |%d|\n", fd);
	// printf("map->fd - %d\n", map->fd);
	if (map->fd < 0) // проверка на то, что вообще файл существует
		ft_error("can't open this file, sorry..");
	if (check_extention(av[1], 1)) // проверка на расширение файла .cub
		ft_error("need only '.cub' extention");
	// bytes = read(map->fd, &buf, 1); //if 0 - end of file; -1 - mistake // проверка на пустой файл и папку с таким же названием
	// printf ("bytes - |%d|\n", bytes);
	if (read(map->fd, &buf, 1) <= 0)
		ft_error("can't read this file, sorry..");
}

int main (int ac, char **av)
{
	t_map	map;
	if (ac != 2)
		ft_error("wrong number of arguments");
	check_map(ac, av, &map);
	parsing(&map);
	printf("north - %s\n", map.north_path);
	printf("south - %s\n", map.south_path);
	printf("west - %s\n", map.west_path);
	printf("east - %s\n", map.east_path);
	return (0);
}