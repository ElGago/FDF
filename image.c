/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 09:59:48 by jocorrea          #+#    #+#             */
/*   Updated: 2023/07/12 10:10:57 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_win new_program(int w, int h, char *str)
{
    void *mlx_ptr;

    mlx_ptr = mlx_init();
    return ((t_win){mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
}

t_img new_img(int w, int h, t_win window)
{
    t_img image;

    image.win = window;
    image.img_ptr = mlx_new_image(window.mlx_ptr, w, h);
    image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
                                   &(image.line_len), &(image.endian));
    image.w = w;
    image.h = h;
    return (image);
}

void put_pixel_img(t_img img, int x, int y, int color)
{
    char *dst;

    if (x >= 0 && y >= 0 && x < img.w && y < img.h)
    {
        dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
        *(unsigned int *)dst = color;
    }
}