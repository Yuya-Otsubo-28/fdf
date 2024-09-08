/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:37:19 by yotsubo           #+#    #+#             */
/*   Updated: 2024/07/21 15:37:19 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

static t_point	***err_return(int *fd, char **input)
{
	if (fd)
		close(*fd);
	if (input)
		free_lines(input);
	return (NULL);
}

static char	**get_input(int fd)
{
	char	**res;
	char	*line;

	res = (char **)malloc(sizeof(char *));
	if (!res)
		return (NULL);
	res[0] = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		delete_nl(line);
		res = add_line(res, line);
		if (!res)
			return (NULL);
	}
	return (res);
}

static t_point	**line_convert_points(char *line, int x)
{
	t_point	**points;
	size_t	size;
	char	**elements;

	elements = ft_split(line, ' ');
	if (!elements)
		return (NULL);
	size = count_lines(elements);
	points = (t_point **)malloc(sizeof(t_point *) * (size + 1));
	if (!points)
	{
		free_lines(elements);
		return (NULL);
	}
	ft_bzero(points, sizeof(t_point *) * (size + 1));
	init_points(points, elements, x, size);
	free_lines(elements);
	return (points);
}

static t_point	***get_map_data(char **input)
{
	t_point	***map;
	size_t	lines_size;
	size_t	i;

	lines_size = count_lines(input);
	map = (t_point ***)malloc(sizeof(t_point **) * (lines_size + 1));
	if (!map)
		return (NULL);
	ft_bzero(map, sizeof(t_point **) * (lines_size + 1));
	i = 0;
	while (input[i])
	{
		map[i] = line_convert_points(input[i], i);
		if (!map[i])
		{
			free_map(map);
			return (NULL);
		}
		i++;
	}
	return (map);
}

t_point	***make_map(char *filename)
{
	int		fd;
	char	**input;
	t_point	***map;

	if (!is_fdf_file(filename))
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (err_return(NULL, NULL));
	input = get_input(fd);
	if (!input || !input[0])
		return (err_return(&fd, NULL));
	map = get_map_data(input);
	if (!map)
		return (err_return(&fd, input));
	free_lines(input);
	close(fd);
	return (map);
}

// int	main(void)
// {
// 	t_point ***map;
//
// 	map = make_map("test_maps/mars.fdf");
// 	for (int i = 0; map[i]; i++)
// 	{
// 		for (int j = 0; map[i][j]; j++)
// 			printf("(%d, %d, %d) ", map[i][j]->x, map[i][j]->y, map[i][j]->z);
// 		puts("");
// 	}
// 	free_map(map);
// 	return (0);
// }