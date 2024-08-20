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
	int	dx;
	int	dy;
	int	ax = a->x;
	int	ay = a->y;

	dx = b->x - a->x;
	dy = b->y - a->y;
	p = 2 * ft_abs(dy) - ft_abs(dx);
	i = 0;
	my_mlx_pixel_put(data, a->x, a->y, a->color);
	while ((unsigned int)i < ft_abs(dx))
	{
		if (dx > 0)
			ax++;
		else
			ax--;
		if (p < 0)
			p = p + 2 * ft_abs(dy);
		else
		{
			if (dy > 0)
				ay++;
			else
				ay--;
			p = p + 2 * ft_abs(dy) - 2 * ft_abs(dx);
		}
		i++;
		my_mlx_pixel_put(data, ax, ay, a->color);
	}
}

static void	sloop_more_than_one(t_data *data, t_point *a, t_point *b)
{
	int	p;
	int	i;
	int	dx;
	int	dy;
	int	ax = a->x;
	int	ay = a->y;

	dx = b->x - a->x;
	dy = b->y - a->y;
	p = 2 * ft_abs(dx) - ft_abs(dy);
	i = 0;
	my_mlx_pixel_put(data, a->x, a->y, a->color);
	while ((unsigned int)i < ft_abs(dy))
	{
		if (dy > 0)
			ay++;
		else
			ay--;
		if (p < 0)
			p = p + 2 * ft_abs(dx);
		else
		{
			if (dx > 0)
				ax++;
			else
				ax--;
			p = p + 2 * ft_abs(dx) - 2 * ft_abs(dy);
		}
		i++;
		my_mlx_pixel_put(data, ax, ay, a->color);
	}
}

static void	draw_line(t_data *data, t_point *a, t_point *b)
{
	int dx;
	int dy;

	dx = b->x - a->x;
	dy = b->y - a->y;
	if (ft_abs(dx) < ft_abs(dy))
		sloop_more_than_one(data, a, b);
	else
		sloop_less_than_one(data, a, b);
}

// static void	draw_line2(t_data *data, t_point *a, t_point *b)
// {
// 	int dx;
// 	int dy;

// 	dx = b->x - a->x;
// 	dy = b->y - a->y;
// 	if (ft_abs(dx) > ft_abs(dy))
// 		sloop_less_than_one(data, a, b);
// }

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
			my_mlx_pixel_put(data, data->map[i][j]->x, data->map[i][j]->y, data->map[i][j]->color);
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