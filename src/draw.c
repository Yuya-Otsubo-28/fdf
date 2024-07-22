/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:54:12 by yotsubo           #+#    #+#             */
/*   Updated: 2024/07/21 16:54:12 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

t_bool	draw(t_data *data)
{
	size_t	i;
	size_t	j;
	int		color;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j]->color)
				color = data->map[i][j]->color;
			else if (data->map[i][j]->z)
				color = 0xE80C0C;
			else
				color = 0x00FFFFFF;
			my_mlx_pixel_put(data, j * 5 + 10, i * 5 + 10, color);
			j++;
		}
		i++;
	}
	return (TRUE);
}