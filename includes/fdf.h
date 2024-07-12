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

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

void	free_data(t_data *data);

#endif