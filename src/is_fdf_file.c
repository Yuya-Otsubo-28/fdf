/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_fdf_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:28:27 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/09/08 15:51:38 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static char	*get_file_name(char *file_path)
{
	char	*res;
	char	*name_head;

	name_head = ft_strrchr(file_path, '/');
	if (!name_head)
		name_head = file_path;
	else
		name_head++;
	res = ft_strdup(name_head);
	if (!res)
		return (NULL);
	return (res);
}

t_bool	is_fdf_file(char *file_path)
{
	char	*filename;
	size_t	len;
	t_bool	res;

	filename = get_file_name(file_path);
	if (!filename)
		return (FALSE);
	len = ft_strlen(filename);
	if (len > 4 && !ft_strncmp(&filename[len - 4], ".fdf", 4))
		res = TRUE;
	else
		res = FALSE;
	free(filename);
	return (res);
}
