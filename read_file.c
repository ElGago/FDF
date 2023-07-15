/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:29:03 by jocorrea          #+#    #+#             */
/*   Updated: 2023/07/12 11:50:01 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int get_heigth(char *file_name)
{
    int     fd;
    int     height;
    char    *line;

    fd = open(file_name, O_RDONLY, 0);
    if (!fd)
        return (-1);
    height = 0;
	line = get_next_line(fd);
    while (line != NULL)
    {
        height++;
        free(line);
		line = get_next_line(fd);
    }
    close(fd);
    return (height);
}

int get_width(char *file_name)
{
    int     fd;
    int     width;
    char    *line;
    char    **col;

    fd = open(file_name, O_RDONLY, 0);
    if (!fd)
        return (-1);
    width = 0;
    line = get_next_line(fd);
    col = ft_split(line, ' ');
	
    while(col[width] != 0)
	{	
		free(col[width]);
        width++;
	}
	close(fd);
	free(col);
    free(line);
    return (width);
}

void    fill_matrix(int *z_line, char *line)
{
    char	**nums;
	int		i;

	i = 0;
	nums = ft_split(line, ' ');
	while (nums[i] != 0)
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void    read_file(char *file_name, fdf *data)
{
    int     fd;
    int     i;
    char    *line;
	
    data->height = get_heigth(file_name);
    data->width = get_width(file_name);
    data->matriz = (int **)malloc(sizeof(int *) * (data->height + 1));
    i = 0;
    while (i < data->height)
        data->matriz[i++] = (int *)malloc(sizeof(int) * (data->width +1));
    fd = open(file_name, O_RDONLY, 0);
	i = 0;
	line = get_next_line(fd);
    while (line != NULL)
    {
		fill_matrix(data->matriz[i], line);
		i++;
		//free(line);
		//line = NULL;
		line = get_next_line(fd);
    }
	
	data->matriz[i] = NULL;
	close(fd);
}