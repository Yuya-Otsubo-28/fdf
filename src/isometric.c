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

#define RAD 0.523599

static t_bool	err_return(t_data *data)
{
	if (data)
		free_data(data);
	return (FALSE);
}

t_bool	isometric(t_data *data)
{
	int		i;
	int		j;
	int		prev_x;
	t_point *point;

	if (!get_map_size(data))
		return (err_return(data));
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