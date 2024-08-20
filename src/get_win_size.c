/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_win_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:01:43 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/08/20 13:04:28 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "libft.h"

static int  get_win_height(t_data *data)
{

}

static int get_win_width(t_data *data)
{
    
}

void    get_win_size(t_data *data)
{
    data->win_height = get_win_height(data);
    data->win_width = get_win_width(data);
}