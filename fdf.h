/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:19:12 by jocorrea          #+#    #+#             */
/*   Updated: 2023/07/29 17:59:57 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#define MAX1(a, b) (a > b ? a : b)
#define MOD(a) ((a < 0) ? -a : a) 

#include "../libft/libft.h"
#include "../libft/get_next_line.h"
#include "./minilibx_macos/mlx.h"
#include <fcntl.h>
#include <math.h>
#include <stdio.h>

typedef struct
{
	int		width;
	int		height;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	int		**map;
	float	angle;

	void	*mlx_ptr;
	void	*win_ptr;
}		fdf;
//----file----
int		read_file(char *file, fdf *data);
//----draw----
int		bresenham(float x, float y, float x1, float y1, fdf *data);
int draw(fdf *data);
#endif
