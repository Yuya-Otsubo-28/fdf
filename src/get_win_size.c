/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_win_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:01:43 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/08/20 13:26:24 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "libft.h"

static void adj_point_y(t_data *data, int min)
{
    int i;
    int j;

    i = 0;
    while (i < data->map_height)
    {
        j = 0;
        while (j < data->map_width)
        {
            data->map[i][j]->y += min;
            j++;
        }
        i++;
    }
}

static void adj_point_x(t_data *data, int min)
{
    int i;
    int j;

    i = 0;
    while (i < data->map_height)
    {
        j = 0;
        while (j < data->map_width)
        {
            data->map[i][j]->x += min;
            j++;
        }
        i++;
    }
}

static int  get_win_height(t_data *data)
{
    int i;
    int j;
    int min;
    int max;

    min = INT_MAX;
    max = INT_MIN;
    i = 0;
    while (i < data->map_height)
    {
        j = 0;
        while (j < data->map_width)
        {
            if (data->map[i][j]->y < min)
                min = data->map[i][j]->y;
            if (data->map[i][j]->y > max)
                max = data->map[i][j]->y;
            j++;
        }
        i++;
    }
    if (min < 0)
        adj_point_y(data, min);
    printf("win_height\nmax: %d\nmin: %d\n", max, min); fflush(stdout);
    return (max - min + 100);
}

static int get_win_width(t_data *data)
{
    int i;
    int j;
    int min;
    int max;

    min = INT_MAX;
    max = INT_MIN;
    i = 0;
    while (i < data->map_height)
    {
        j = 0;
        while (j < data->map_width)
        {
            if (data->map[i][j]->x < min)
                min = data->map[i][j]->x;
            if (data->map[i][j]->x > max)
                max = data->map[i][j]->x;
            j++;
        }
        i++;
    }
    if (min < 0)
        adj_point_x(data, min);
    printf("win_width\nmax: %d\nmin: %d\n", max, min); fflush(stdout);
    return (max - min + 100);
}

void    get_win_size(t_data *data)
{
    data->win_height = get_win_height(data);
    data->win_width = get_win_width(data);
    printf("height: %d\nwidth: %d\n", data->win_height, data->win_width); fflush(stdout);
}