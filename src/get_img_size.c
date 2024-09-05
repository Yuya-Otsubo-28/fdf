/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:01:43 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/09/05 15:43:20 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static int	get_img_height(t_data *data)
{
	int	i;
	int	j;
	int	min;
	int	max;

	min = INT_MAX;
	max = INT_MIN;
	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j]->y < min)
				min = data->map[i][j]->y;
			if (data->map[i][j]->y > max)
				max = data->map[i][j]->y;
			j++;
		}
		i++;
	}
	if (min < 0)
		adj_point_y(data, min);
	return (max - min);
}

static int	get_img_width(t_data *data)
{
	int	i;
	int	j;
	int	min;
	int	max;

	min = INT_MAX;
	max = INT_MIN;
	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j]->x < min)
				min = data->map[i][j]->x;
			if (data->map[i][j]->x > max)
				max = data->map[i][j]->x;
			j++;
		}
		i++;
	}
	if (min < 0)
		adj_point_x(data, min);
	return (max - min);
}

static void	compress_point(t_data *data, int scale, int axis)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (axis == X)
				data->map[i][j]->x /= scale;
			else if (axis == Y)
				data->map[i][j]->y /= scale;
			j++;
		}
		i++;
	}
}

void	get_img_size(t_data *data)
{
	int	scale;

	data->img_height = get_img_height(data);
	data->img_width = get_img_width(data);
	scale = get_image_scale(data);
	if (scale > 1)
	{
		compress_point(data, scale, X);
		compress_point(data, scale, Y);
	}
}
