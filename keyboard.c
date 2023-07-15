/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:13:45 by jocorrea          #+#    #+#             */
/*   Updated: 2023/07/12 10:14:10 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int exit_tutorial(t_win *window)
{
    if (window)
        mlx_destroy_window(window->mlx_ptr, window->win_ptr);
    exit(EXIT_SUCCESS);
}