/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:59:39 by lemmon            #+#    #+#             */
/*   Updated: 2022/06/29 15:07:05 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
static void	line_math_minimap(t_map *data, float rad);
static int	draw_map(t_map *map);

static void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static t_mlx	*new_image(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->mlx, HEIGHT, WIDTH);
	// if (!data->img)
	// 	exit(INIT_ERROR);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	// if (!data->addr)
	// 	exit(INIT_ERROR);
	return (mlx);
}

static void	square(t_mlx *mlx, int i, int j, int size)
{
	for (int k = 0; k < size; ++k){
		for (int l = 0; l < size; ++l){
			my_mlx_pixel_put(mlx, i + l, j + k, 255);
		}
	}
}

static void	square2(t_mlx *mlx, int i, int j, t_map *map)
{
	int size = 20;
	int color;
	color = ((255 - map->f_red) << 16)
			+ ((255 - map->f_green) << 8) + (255 - map->f_red);
	for (int k = 0; k < size; ++k){
		for (int l = 0; l < size; ++l){
			my_mlx_pixel_put(mlx, i + l, j + k, color);
		}
	}
}

static int	draw_map(t_map *map)
{
	int		i;
	int		j;
	int	map_size = 20;
	// int color;
	// int		iter;
	
	// mlx_destroy_image(map->mlx.mlx, map->mlx.img);
	// mlx_clear_window(map->mlx.mlx, map->mlx.mlx_win);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			// printf("x - %f  ||| y - %f \n", map->pers.x, map->pers.y);	
			// color = ((255 - map->f_red) << 16)
			// 	+ ((255 - map->f_green) << 8) + (255 - map->f_red);
			if (map->map[i][j] == 1)
				square(&map->mlx, j * map_size, i * map_size, map_size);
			else if (i == (int)map->pers.x && j == (int)map->pers.y){
				// printf("x - %f  ||| y - %f \n", map->pers.x, map->pers.y);	
				square2(&map->mlx, j * map_size, i * map_size, map);
			}
				// my_mlx_pixel_put(mlx, i, j, color);
			// else if (map->map[i][j] == 0)
			// 	my_mlx_pixel_put(mlx, i, j, 200);
			j++;
		}
		i++;
	}
	// sector_light(map);
	float	rad = -0.52;
	while (rad < 0.52f) // fov - field of view
	{
		line_math_minimap(map, rad);
		rad += 0.01f;
	}
	
	line_math_minimap(map, rad);

	// line_math_minimap(map, map->pers.a + 0.5f);

	mlx_put_image_to_window(map->mlx.mlx, map->mlx.mlx_win, map->mlx.img, 100, 100); // img - wall - img
	mlx_destroy_image(map->mlx.mlx, map->mlx.img);
	new_image(&map->mlx);
	// printf("2x - %f  ||| 2y - %f \n", map->pers.x, map->pers.y);
	return (0);
}

//
void	map_exit_case(int keycode, t_map *map)
{
	// if (keycode == MINIMAP_KEY)
	// {
	// 	if (data->map->play.f_minimap)
	// 		data->map->play.f_minimap = 0;
	// 	else
	// 		data->map->play.f_minimap = 1;
	// }
	// if (keycode == MAP_KEY)
	// {
	// 	if (data->map->play.f_map)
	// 		data->map->play.f_map = 0;
	// 	else
	// 		data->map->play.f_map = 1;
	// }
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx.mlx, map->mlx.mlx_win);
		ft_error("END GAME");
	}
}

int	key_press(int keycode, t_map *map)
{
	int	tmp_x;
	int	tmp_y;
	mlx_clear_window(map->mlx.mlx, map->mlx.mlx_win);
	
	map_exit_case(keycode, map);
	
	
	if (keycode >= 0 && keycode < 260) {
		printf("I press %d button\n", keycode);
		tmp_x = map->pers.x;
		tmp_y = map->pers.y;
		if (keycode == A_KEY)
			map->pers.y--;
		else if (keycode == D_KEY)
			map->pers.y++;
		else if (keycode == W_KEY)
			map->pers.x--;
		else if (keycode == S_KEY) 
			map->pers.x++;
		else if (keycode == LEFT_KEY)
			map->pers.a += 0.05f;
		else if (keycode == RIGHT_KEY)
			map->pers.a -= 0.05f;
		if (map->map[(int)map->pers.x][(int)map->pers.y] == 1)
		{
			map->pers.x = tmp_x;
			map->pers.y = tmp_y;
		}
		map->mlx.keycode[keycode] = 1;
	}
	draw_map(map);
	// mlx_clear_window(map->mlx.mlx, map->mlx.mlx_win);
	// mlx_destroy_image(map->mlx.mlx, map->mlx.img);
	return (0);
}

int	key_unpress(int keycode, t_map *map)
{
	if (keycode >= 0 && keycode < 260) {
		map->mlx.keycode[keycode] = 0;
	}
	return (0);
}

int	end_program(int keycode, t_map *map)
{
	(void) keycode;
	(void) map;
		ft_error("rrr");
	return (0);
}
//


// void	algorihm_dda(float x1, float y1, float x2, float y2)
// {
//   int i, L, xstart, ystart, xend, yend;
//   float dX, dY, x[1000], y[1000];    
//   xstart = roundf(x1);
//   ystart = roundf(y1);
//   xend = roundf(x2);
//   yend = roundf(y2);
//   L = max(abs(xend-xstart), abs(yend-ystart));
//   dX = (x2-x1) / L;
//   dY = (y2-y1) / L;
//   i = 0;
//   x[i] = x1;
//   y[i] = y1;
//   i++;
//   while (i < L)
//   {
//     x[i] = x[i-1] + dX;
//     y[i] = y[i-1] + dY;
//     i++;
//   }
//   x[i] = x2;
//   y[i] = y2;
//   /* Output: -----------------------*/
//   i = 0;
//   while (i <= L)
//   {
// 	mlx_pixel_put()
//     plot (roundf(x[i]), roundf(y[i])); /* Draws a point. */
//     i++;
//   }
//   /* -------------------------------*/
// }


// void	draw_line(t_map *data, t_vls xyz, int color)
// {
// 	t_line	line_w;

// 	init_list(&line_w, &xyz);
// 	while ((int)(xyz.x1 - xyz.x2) || (int)(xyz.y1 - xyz.y2))
// 	{
// 		my_mlx_pixel_put(data, xyz.x1, xyz.y1, color);
// 		line_w.error2 = line_w.error * 2;
// 		if (line_w.error2 > -line_w.delta_y)
// 		{
// 			line_w.error -= line_w.delta_y;
// 			xyz.x1 += line_w.sign_x;
// 		}
// 		if (line_w.error2 < line_w.delta_x)
// 		{
// 			line_w.error += line_w.delta_x;
// 			xyz.y1 += line_w.sign_y;
// 		}
// 	}
// }

static void	line_math_minimap(t_map *data, float rad)
{
	float	c;
	float	ang;
	float	ray_x;
	float	ray_y;
	int		color;

	color = ((255 - data->f_red) << 10)
			+ ((255 - data->f_green) << 5) + ((255 - data->f_blue) << 3); // 24 -  16 - 8
			
	ang = data->pers.a + rad;
	// ang = 0;
	
	c = 0;
	// float dis;
		float	tmp_x = 0;
		float	tmp_y = 0;
		
	// float 	ceilig = 0;
	// float	floor = 0;
	// while (c < MMTEXSIZE / 10)
	while (1)
	{
		
		ray_x = (data->pers.x + 0.5) + c * cos(ang);
		ray_y = (data->pers.y + 0.5) + c * sin(ang);
		// printf("i'm here\n");
		if (data->map[(int)ray_x][(int)ray_y] == 1)
		{
			tmp_x = ray_x + c;
			tmp_y = ray_y + c;
			// printf("ray - %f\n", tmp_x);
			// printf("ray2 - %f\n", tmp_y);
			break ;
		}
		// ray_x *= 20;
		// ray_y *= 20;
		c = c + 0.1f;
		if (c > 5) // ограничение на длину испускаемого луча
			break ;
		// printf("tmp - %f\n", tmp_y);
		while (tmp_y < 0)
		{
			mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, tmp_x, tmp_y, color);
			tmp_y++;
		}
		// dis = c;
		// ceilig = (float)(HEIGHT/2.0) - HEIGHT / dis;
		// floor = HEIGHT - ceilig;
		// tmp_x = (ray_x * floor);
		// pixel_put_map_move(ray_x, ray_y, data, PLAYERCOL);
		my_mlx_pixel_put(&data->mlx, ray_y * 20, ray_x * 20, RED_COL);
		// my_mlx_pixel_put(&data->mlx, tmp_x, tmp_y, color);

		// for(int j = 0; j < HEIGHT; ++j)
		// 	my_mlx_pixel_put(&data->mlx, tmp_y * j, tmp_x, color);
	}
}

int draw(t_map *map)
{
	map->mlx.mlx = mlx_init();
	map->mlx.mlx_win = mlx_new_window(map->mlx.mlx, WIDTH, HEIGHT, "Such big world");
	map->mlx.img_wall = mlx_xpm_file_to_image(\
		map->mlx.mlx, map->north_path, &(map->mlx.img_width), \
		&(map->mlx.img_height));
	new_image(&map->mlx);
	// mlx_key_hook(mlx->mlx_win, key_hook, mlx);
	mlx_hook(map->mlx.mlx_win, 2, 0, &key_press, map);
	mlx_hook(map->mlx.mlx_win, 3, 0, &key_unpress, map);
	mlx_hook(map->mlx.mlx_win, 17, 0, &end_program, map);
	mlx_loop_hook(map->mlx.mlx, draw_map, map);
	// mlx_loop_hook(map->mlx.mlx, draw_sector, map);

	// mlx_hook(mlx->mlx_win, KEY_CROSS, MASK_CROSS, close_window, mlx);
	// start(map);
	mlx_loop(map->mlx.mlx);
	return(0);
} 