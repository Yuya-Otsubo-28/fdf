/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 23:29:02 by yotsubo           #+#    #+#             */
/*   Updated: 2024/07/12 23:29:02 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "libft.h"

void	free_lines(char **lines)
{
	size_t	i;

	if (!lines)
		return ;
	i = 0;
	while (lines[i])
		free(lines[i++]);
	free(lines);
}

void	free_points(t_point **points)
{
	size_t	i;

	if (!points)
		return ;
	i = 0;
	while (points[i])
		free(points[i++]);
	free(points);
}

void	free_map(t_point ***map)
{
	size_t	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
		free_points(map[i++]);
	free(map);
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	if (data->map)
		free_map(data->map);
	free(data);
	return ;
}