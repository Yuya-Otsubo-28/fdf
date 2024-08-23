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

static int	update_p(int p, int *j, int small_d, int big_d)
{
	int	add_j;

	if (p < 0)
		p = p + 2 * ft_abs(small_d);
	else
	{
		if (small_d > 0)
			add_j = 1;
		else
			add_j = -1;
		p = p + 2 * ft_abs(small_d) - 2 * ft_abs(big_d);
		*j += add_j;
	}
	return (p);
}

static void	sloop_less_than_one(t_data *data, t_point *a, t_point *b)
{
	int	p;
	int	i;
	int	j;
	int	dx;
	int	dy;

	dx = b->x - a->x;
	dy = b->y - a->y;
	p = 2 * ft_abs(dy) - ft_abs(dx);
	i = 0;
	j = 0;
	my_mlx_pixel_put(data, a->x, a->y, a->color);
	while ((unsigned int)i < ft_abs(dx))
	{
		p = update_p(p, &j, dy, dx);
		i++;
		if (dx > 0)
			my_mlx_pixel_put(data, a->x + i, a->y + j, a->color);
		else
			my_mlx_pixel_put(data, a->x - i, a->y + j, a->color);
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
	p = 2 * ft_abs(dx) - ft_abs(dy);
	i = 0;
	j = 0;
	my_mlx_pixel_put(data, a->x, a->y, a->color);
	while ((unsigned int)i < ft_abs(dy))
	{
		p = update_p(p, &j, dx, dy);
		i++;
		if (dy > 0)
			my_mlx_pixel_put(data, a->x + j, a->y + i, a->color);
		else
			my_mlx_pixel_put(data, a->x + j, a->y - i, a->color);
	}
}

static void	draw_line(t_data *data, t_point *a, t_point *b)
{
	int	dx;
	int	dy;

	dx = b->x - a->x;
	dy = b->y - a->y;
	if (ft_abs(dx) < ft_abs(dy))
		sloop_more_than_one(data, a, b);
	else
		sloop_less_than_one(data, a, b);
}

t_bool	draw(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			my_mlx_pixel_put(data, data->map[i][j]->x, data->map[i][j]->y, \
								data->map[i][j]->color);
			if (i != data->map_height - 1)
				draw_line(data, data->map[i][j], data->map[i + 1][j]);
			if (j != data->map_width - 1)
				draw_line(data, data->map[i][j], data->map[i][j + 1]);
			j++;
		}
		i++;
	}
	return (TRUE);
}
