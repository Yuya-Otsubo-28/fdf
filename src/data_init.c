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

#include "../includes/fdf.h"
#include "libft.h"

static t_data	*err_return(t_data *data)
{
	if (data)
		free_data(data);
	return (NULL);
}

t_data	*data_init(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (err_return(NULL));
	ft_bzero(data, sizeof(data));
	data->mlx_ptr = mlx_init();
	if (!(data->mlx_ptr))
		return (err_return(data));
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "fdf");
	if (!(data->win_ptr))
		return (err_return(data));
	data->img = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!(data->img))
		return (err_return(data));
	data->img_addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len, &data->endian);
	if (!(data->img_addr))
		return (err_return(data));
	// my_mlx_pixel_put(data, 5, 5, 0x00FF0000);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
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

//cc  -L./libft -L./libmlx -I./includes -I./libft -I./libmlx src/data_init.c src/free_utils.c -lft -lmlx -lX11 -lXext