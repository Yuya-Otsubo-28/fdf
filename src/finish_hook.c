/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:51:08 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/08/21 00:35:15 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "libft.h"

int finish_hook(t_data *data)
{
    free_data(data);
    exit(0);
}

int	expose_hook(t_data *data)
{
	draw(data);
	return (0);
}