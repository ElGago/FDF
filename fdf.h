/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:19:12 by jocorrea          #+#    #+#             */
/*   Updated: 2023/07/30 14:29:19 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./libft/get_next_line.h"
# include "./minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

typedef struct s_fdf
{
	int		width;
	int		height;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	int		**map;
	int		factor;
	float	angle;

	void	*mlx_ptr;
	void	*win_ptr;
}		t_fdf;

typedef struct s_point
{
	float	x;
	float	y;
	float	x1;
	float	y1;
}		t_point;
//----file----
int		read_file(char *file, t_fdf *data);
//----draw----
int		bresenham(t_point *p, t_fdf *data);
int		draw(t_fdf *data);
//-----utils----
int		max1(float a, float b);
int		mod1(float a);
int		ft_err(char *msg);
void	map_free(int i, t_fdf *data);
int		close_window(t_fdf *data);
//-----keycontrol event mouse----
int		deal_key(int key, t_fdf *data);
int		mouse_press(int button, int x, int y, t_fdf *data);
#endif
