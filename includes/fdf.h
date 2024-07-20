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
# include "mlx.h"

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	t_list	*map;
}	t_data;

typedef struct s_point {
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

void	free_data(t_data *data);

t_data	*data_init(void);

t_list	*make_map(char *file_name);

#endif