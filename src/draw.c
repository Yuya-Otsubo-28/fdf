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

static void	sloop_less_than_one(t_data *data, t_point *a, t_point *b)
{
	int	p;
	int	i;
	int	j;
	int	dx;
	int	dy;

	dx = b->x - a->x;
	dy = b->y - a->y;
	p = 2 * dy - dx;
	i = 0;
	j = 0;
	printf("ax: %d, ay: %d, bx: %d, by: %d\n", a->x, a->y, b->x, b->y);
	my_mlx_pixel_put(data, a->x, a->y, a->color);
	while (i < dx)
	{
		if (p < 0)
			p = p + 2 * dy;
		else
		{
			j++;
			p = p + 2 * dy - dx;
		}
		printf("%d\n", a->y);
		i++;
		my_mlx_pixel_put(data, a->x + i, a->y + j, a->color);
	}
}

static void	sloop_more_than_one(t_data *data, t_point *a, t_point *b)
{
	int	p;
	int	i;
	int	j;
	int	dx;
	int	dy;

	dx = b->x - a->x;
	dy = b->y - a->y;
	p = 2 * dx - dy;
	i = 0;
	j = 0;
	printf("> ax: %d, ay: %d, bx: %d, by: %d\n", a->x, a->y, b->x, b->y);
	my_mlx_pixel_put(data, a->x, a->y, a->color);
	while (i < dy)
	{
		if (p < 0)
			p = p + 2 * dx;
		else
		{
			j++;
			p = p + 2 * dx - dy;
		}
		i++;
		my_mlx_pixel_put(data, a->x + j, a->y + i, a->color);
	}
}

static void	draw_line(t_data *data, t_point *a, t_point *b)
{
	int dx;
	int dy;

	dx = b->x - a->x;
	dy = b->y - a->y;
	if (ft_abs(dx) > ft_abs(dy))
		sloop_less_than_one(data, a, b);
	else
		sloop_more_than_one(data, a, b);
}

t_bool	draw(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			my_mlx_pixel_put(data, data->map[i][j]->x, data->map[i][j]->y, data->map[i][j]->color);
			if (data->map[i + 1])
				draw_line(data, data->map[i][j], data->map[i + 1][j]);
			if (data->map[i][j + 1])
				draw_line(data, data->map[i][j], data->map[i][j + 1]);
			j++;
		}
		i++;
	}
	return (TRUE);
}