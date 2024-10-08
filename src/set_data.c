/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 23:16:54 by yotsubo           #+#    #+#             */
/*   Updated: 2024/07/12 23:16:54 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static t_data	*err_return(t_data *data)
{
	if (data)
		free_data(data);
	return (NULL);
}

t_data	*set_data(t_data *data)
{
	get_img_size(data);
	data->mlx_ptr = mlx_init();
	if (!(data->mlx_ptr))
		return (err_return(data));
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "fdf");
	if (!(data->win_ptr))
		return (err_return(data));
	data->img = mlx_new_image(data->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	if (!(data->img))
		return (err_return(data));
	data->img_addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len, \
										&data->endian);
	if (!(data->img_addr))
		return (err_return(data));
	return (data);
}

//int	main(void)
//{
//	t_data *data;
//
//	data = data_init();
//	(void)data;
//	return (0);
//}