/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 23:10:03 by yotsubo           #+#    #+#             */
/*   Updated: 2024/07/12 23:10:03 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <strings.h>
# include <limits.h>
# include <stdarg.h>
# include <math.h>
# include "mlx.h"

# define TRUE 1
# define FALSE 0

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1040

typedef int	t_bool;

typedef struct s_point {
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_data {
	t_point	***map;
	int		map_width;
	int		map_height;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*img_addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		win_width;
	int		win_height;
}	t_data;

void	free_lines(char **lines);

void	free_points(t_point **points);

void	free_map(t_point ***map);

void	free_data(t_data *data);

t_data	*set_data(t_data *data);

t_point	***make_map(char *filename);

t_bool	get_map_size(t_data *data);

t_bool	isometric(t_data *data);

t_bool	draw(t_data *data);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void    get_win_size(t_data *data);

int		finish_hook(t_data *data);

#endif