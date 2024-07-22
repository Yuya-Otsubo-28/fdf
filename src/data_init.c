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

t_data	*data_init(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(data));
	if (!data)
		return (err_return(NULL));
	ft_bzero(data, sizeof(data));
	data->mlx_ptr = mlx_init();
	if (!(data->mlx_ptr))
		return (err_return(data));
	data->win_ptr = mlx_new_window(data->mlx_ptr, 860, 510, "fdf");
	if (!(data->win_ptr))
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

//cc  -L./libft -L./libmlx -I./includes -I./libft -I./libmlx src/data_init.c src/free_utils.c -lft -lmlx -lX11 -lXext