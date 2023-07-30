/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:29:29 by jocorrea          #+#    #+#             */
/*   Updated: 2023/07/30 14:29:36 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	max1(float a, float b)
{
	if (a < b)
		return (b);
	return (a);
}

int	mod1(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	ft_err(char *msg)
{
	ft_putstr_fd(msg, 1);
	ft_putchar_fd('\n', 1);
	return (-1);
}

void	map_free(int i, t_fdf *data)
{
	while (i > 0)
		free(data->map[--i]);
	free(data->map);
	free(data);
}

int	close_window(t_fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
	return (0);
}
