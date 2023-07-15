/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 09:24:47 by jocorrea          #+#    #+#             */
/*   Updated: 2023/07/13 12:14:24 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "./libft/libft.h"
#include "./libft/get_next_line.h"
#include "./minilibx-linux/mlx.h"

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}		t_win;

typedef struct s_img
{
	t_win	win;
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}		t_img;

typedef struct 
{
	int		width;
	int		height;
	int		**matriz;
	int		zoom;

	void	*win_ptr;
	void	*mlx_ptr;
}		fdf;

/*#image function*/
t_win new_program(int w, int h, char *str);
t_img new_img(int w, int h, t_win window);
void put_pixel_img(t_img img, int x, int y, int color);
/*#event function*/
int exit_tutorial(t_win *window);
/*#reads function*/
void    read_file(char *file_name, fdf *data);
/*# DRAW*/
void    bresenham_1(float x, float y, float x1, float y1, fdf *data);
void	draw(fdf *data);
#endif