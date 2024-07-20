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

void	free_list_all(t_list *list)
{
	t_list	*next;

	if (!list)
		return ;
	while (list)
	{
		next = list->next;
		free(list);
		list = next;
	}
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
		free_list_all(data->map);
	free(data);
	return ;
}