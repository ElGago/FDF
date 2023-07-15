/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:48:22 by jocorrea          #+#    #+#             */
/*   Updated: 2023/07/13 12:15:35 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "fdf.h"
#define MAX1(a, b)(a > b ? a : b)
#define MOD(a)((a < 0) ? -a : a)

void    bresenham_1(float x, float y, float x1, float y1, fdf *data)
{
    float   x_step;
    float   y_step;
	int		max;

	//zoom
	x *= 20;
	y *= 20;
	x1 *= 20;
	y1 *= 20;
	
	x_step = (x1 - x);
	y_step = (y1 - y);
	max = MAX1(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y -y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xffffff);
		x += x_step;
		y += y_step;
	}
}

void	draw(fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->width)
	{
		x = 0;
		while (x < data->height)
		{
			bresenham_1(x, y, (x + 1), y, data);	
			bresenham_1(x, y, x, (y + 1), data);	
			x++;		
		}
		y++;
	}
} 

int main(int args, char **argv)
{
	fdf	*data;

	data = (fdf *)malloc(sizeof(fdf));
	if (!data)
		return (1);
	read_file(argv[1], data);

	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 500, 500, "fdf");
	
	//bresenham_1(10, 10, 500, 500, data);
	//data->zoom = 20;
	draw(data);
	mlx_hook(data->win_ptr, 17, 0, exit_tutorial, &data);
    mlx_loop(data->mlx_ptr);
}

