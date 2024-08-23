/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:58:37 by yotsubo           #+#    #+#             */
/*   Updated: 2024/07/22 16:58:37 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static int	get_map_width(t_point **line)
{
	int	width;

	width = 0;
	while (line[width])
		width++;
	return (width);
}

static t_bool	check_map_width(t_data *data)
{
	int	i;
	int	current_width;

	i = 1;
	while (data->map[i])
	{
		current_width = get_map_width(data->map[i]);
		if (current_width != data->map_width)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	get_map_height(t_point ***map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

t_bool	get_map_size(t_data *data)
{
	data->map_width = get_map_width(data->map[0]);
	if (!check_map_width(data))
		return (FALSE);
	data->map_height = get_map_height(data->map);
	return (TRUE);
}
