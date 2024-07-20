/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:57:12 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/07/20 17:47:09 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
// 後で消す
#include <fcntl.h>

int	**err_return(int *fd_p, char **map_strs)
{
	if (fd_p)
		close(*fd_p);
	if (map_strs)
		free_strs(map_strs);
	return (NULL);
}

t_list	*get_map_data(int fd)
{
	t_list	*map;
	char	*line;

	map = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
	}
}
// {
// 	t_list	*map;
// 	t_list	*new_node;
// 	t_list	*line_head;
// 	char	*line;

// 	map = NULL;
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		line_head = make_line_list(line);
// 		free(line);
// 		if (!line_head)
// 			return (free_lists(map));
// 		new_node = ft_lstnew(line_head);
// 		if (!new_node)
// 		{
// 			free_list(line_head);
// 			return (free_lists(map));
// 		}
// 		ft_lstadd_back(&map, new_node);
// 	}
// 	return (map);
// }

t_list	*make_map(char *file_name)
{
    int		fd;
    t_list  *map;

    fd = open(file_name, O_RDONLY);
    if (fd < 0)
        return (err_return(NULL, NULL));
    map = get_map(fd);
    if (!map)
        return (&fd, NULL);
}