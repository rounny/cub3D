/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:48:27 by lemmon            #+#    #+#             */
/*   Updated: 2022/06/29 12:33:02 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
#define DRAW_H

#include "../cub.h"

# define KEY_ESC 53
# define KEY_CROSS 17
# define MASK_CROSS 131072L
# define RED_COL			0x00FF0000

# define W_KEY				13
# define A_KEY				0
# define S_KEY				1
# define D_KEY				2
# define LEFT_KEY			123
# define RIGHT_KEY			124
# define DOWN_KEY			125
# define MAP_KEY			48
# define UP_KEY				126

# define MMFOV				0.80f
# define MMANG_START		-0.80f
# define MMANG_STEP			0.05f

typedef struct s_vls
{
	float	x1;
	float	x2;
	float	y1;
	float	y2;
}	t_vls;


#endif