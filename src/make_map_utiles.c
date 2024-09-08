/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_utiles.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:25:13 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/09/08 17:55:36 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"


char	**add_line(char **prev, char *line)
{
	size_t	prev_size;
	size_t	i;
	char	**res;

	prev_size = count_lines(prev);
	res = (char **)malloc(sizeof(char *) * (prev_size + 2));
	if (!res)
	{
		free_lines(prev);
		free(line);
		return (NULL);
	}
	i = 0;
	while (prev[i])
	{
		res[i] = prev[i];
		i++;
	}
	res[i++] = line;
	res[i] = NULL;
	free(prev);
	return (res);
}

void	delete_nl(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			line[i] = '\0';
		i++;
	}
}

t_point	*init_point(int y, int x, int z)
{
	t_point	*point;

	point = (t_point *)malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	point->x = x * 20 + 300;
	point->y = y * 20 + 200;
	point->z = z * 20;
	if (!z)
		point->color = 0x00FFFFFF;
	else
		point->color = 0x00FF0000;
	return (point);
}

t_point	**init_points(t_point **points, char **elements, \
							int x, size_t	size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (is_number(elements[i]))
			points[i] = init_point(x, (int)i, ft_atoi(elements[i]));
		else
			points[i] = NULL;
		if (!points[i])
		{
			free_points(points);
			free_lines(elements);
			return (NULL);
		}
		i++;
	}
	return (points);
}
