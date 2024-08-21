/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:51:08 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/08/21 15:55:05 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "libft.h"

static int finish_hook(t_data *data)
{
    free_data(data);
    exit(0);
}

static int	expose_hook(t_data *data)
{
	draw(data);
	return (0);
}

void    hooks(t_data *data)
{
    mlx_hook(data->win_ptr, 9, 1L << 21, &expose_hook, data);
	mlx_hook(data->win_ptr, 25, 1L << 18, &expose_hook, data);
	mlx_hook(data->win_ptr, 33, 1L << 17, &finish_hook, data);
}