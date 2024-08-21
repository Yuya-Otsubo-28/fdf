/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:53:48 by yotsubo           #+#    #+#             */
/*   Updated: 2024/07/24 12:53:48 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "libft.h"

// [[cos(RAS), -cos(RAD)], [sin(RAD), sin(RAD)]][x, y] = [x', y']
// RAD = pie / 6

#define RAD 0.523599

t_bool	isometric(t_data *data)
{
	int		i;
	int		j;
	int		prev_x;
	t_point *point;

	if (!get_map_size(data))
		return (FALSE);
	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			point = data->map[i][j];
			prev_x = point->x;
			point->x = (prev_x - point->y) * cos(RAD) + 200;
			point->y = (prev_x + point->y) * sin(RAD) - point->z;
			j++;
		}
		i++;
	}
	return (TRUE);
}
