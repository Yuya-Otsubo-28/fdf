/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:51:08 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/09/05 14:40:31 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static int	finish_hook(t_data *data)
{
	free_data(data);
	exit(0);
}

static int	key_hook(int key_code, t_data *data)
{
	if (key_code == ESC_KEY)
	{
		free_data(data);
		exit(0);
	}
	return (0);
}

static int	expose_hook(t_data *data)
{
	draw(data);
	return (0);
}

void	hooks(t_data *data)
{
	mlx_hook(data->win_ptr, 9, 1L << 21, &expose_hook, data);
	mlx_hook(data->win_ptr, 25, 1L << 18, &expose_hook, data);
	mlx_hook(data->win_ptr, 33, 1L << 17, &finish_hook, data);
	mlx_key_hook(data->win_ptr, &key_hook, data);
}
