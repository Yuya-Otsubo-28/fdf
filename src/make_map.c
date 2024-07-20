/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:57:12 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/07/20 21:03:07 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

// [!] to do
// - return 前のfreeなどの処理

char	**free_strs(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (NULL);
}

t_list *err_return(int *fd_p, char **map_strs)
{
	if (fd_p)
		close(*fd_p);
	if (map_strs)
		free_strs(map_strs);
	return (NULL);
}

t_point	*init_point(int x, int y, int z)
{
	t_point	*point;

	point = (t_point *)malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	point->x = x;
	point->y = y;
	point->z = z;
	return (point);
}

t_list	*make_line_list(t_list *map, char *line, int x)
{
	char	**points;
	size_t	i;
	t_list	*node;
	t_point	*point;

	points = ft_split(line, ' ');
	if (!points)
		return (NULL);
	i = 0;
	while (points[i])
	{
		point = init_point(x, (int)(i + 1), ft_atoi(points[i]));
		if (!point)
			return (NULL);
		node = ft_lstnew(point);
		if (!node)
			return (NULL);
		ft_lstadd_back(&map, node);
		i++;
	}
	return (map);
}

t_list	*get_map_data(int fd)
{
	t_list	*map;
	char	*line;
	int		x;

	map = NULL;
	x = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
            break ;
		map = make_line_list(map, line, x++);
		free(line);
	}
	return (map);
}

t_list	*make_map(char *file_name)
{
    int		fd;
    t_list  *map;

    fd = open(file_name, O_RDONLY);
    if (fd < 0)
		return (err_return(NULL, NULL));
    map = get_map_data(fd);
    if (!map)
		return (err_return(&fd, NULL));
	close(fd);
	return (map);
}
//
//int	main(void)
//{
//	t_list *map;
//
//	map = make_map("t2.fdf");
//	while (map)
//	{
//		printf("(%d %d %d) ", ((t_point *)(map->content))->x, ((t_point *)(map->content))->y, ((t_point *)(map->content))->z);
//		if (map->next && ((t_point *)(map->content))->x != ((t_point *)(map->next->content))->x)
//			puts("");
//		map = map->next;
//	}
//	return (0);
//}