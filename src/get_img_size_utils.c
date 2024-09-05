/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img_size_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:21:25 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/09/05 15:43:38 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	adj_point_y(t_data *data, int min)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			data->map[i][j]->y += -min;
			j++;
		}
		i++;
	}
}

void	adj_point_x(t_data *data, int min)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			data->map[i][j]->x += -min;
			j++;
		}
		i++;
	}
}

int	get_image_scale(t_data *data)
{
	int	width_scale;
	int	height_scale;

	width_scale = data->img_width / IMG_WIDTH + 1;
	height_scale = data->img_height / IMG_HEIGHT + 1;
	if (width_scale > height_scale)
		return (width_scale);
	else
		return (height_scale);
}
