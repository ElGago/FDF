/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:03:04 by jocorrea          #+#    #+#             */
/*   Updated: 2023/07/29 18:00:34 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(float *x, float *y, float angle, int z)
{
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
}

int	bresenham(float x, float y, float x1, float y1, fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;
	
	z = data->map[(int)y][(int)x];
	z1 = data->map[(int)y1][(int)x1];
	//----zoom----
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	//----color----
	data->color = (z || z1) ? 0xe80c0c : 0xffffff;
	//----3d----
	isometric(&x, &y, data->angle, z);
	isometric(&x1, &y1, data->angle, z1);
	//----shift----
	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;
	// ----step-size---
	x_step = x1 -x;
	y_step = y1 -y;
	max = MAX1(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x -x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
	}
	return (1);
}

int	draw(fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1) 
				bresenham(x, y, (x + 1), y, data);
			if (y < data->height -1)
				bresenham(x, y, x, (y + 1), data);
			x++;
		}
		y++;
	}
	return (1);
}
