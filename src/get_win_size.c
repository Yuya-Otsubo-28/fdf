/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_win_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:01:43 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/08/20 14:30:47 by yuotsubo         ###   ########.fr       */
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
            data->map[i][j]->y += -min;
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
            data->map[i][j]->x += -min;
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
    return (max - min + 300);
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
    return (max - min + 300);
}

static void compress_point_x(t_data *data)
{
    int divider;
    int i;
    int j;

    divider = WIN_WIDTH / data->win_width + 1;
    data->win_width = WIN_WIDTH;
    i = 0;
    while (i < data->map_height)
    {
        j = 0;
        while (j < data->map_width)
        {
            data->map[i][j]->x /= divider;
            j++;
        }
        i++;
    }
}

static void compress_point_y(t_data *data)
{
    int divider;
    int i;
    int j;

    divider = WIN_HEIGHT / data->win_height + 1;
    data->win_height = WIN_HEIGHT;
    i = 0;
    while (i < data->map_height)
    {
        j = 0;
        while (j < data->map_width)
        {
            data->map[i][j]->y /= divider;
            j++;
        }
        i++;
    }
}

void    get_win_size(t_data *data)
{
    data->win_height = get_win_height(data);
    data->win_width = get_win_width(data);
    if (data->win_height > WIN_HEIGHT - 100)
        compress_point_y(data);
    if (data->win_width > WIN_WIDTH - 100)
        compress_point_x(data);
    printf("height: %d\nwidth: %d\n", data->win_height, data->win_width); fflush(stdout);
}