/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 23:07:22 by yotsubo           #+#    #+#             */
/*   Updated: 2024/07/12 23:07:22 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static int	err_return(t_data *data)
{
	ft_printf("ERROR\n");
	if (data)
		free_data(data);
	return (EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc != 2)
		return (err_return(NULL));
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (err_return(NULL));
	ft_bzero(data, sizeof(t_data));
	data->map = make_map(argv[1]);
	if (!(data->map))
		return (err_return(data));
	data = set_data(data);
	if (!data)
		return(err_return(data));
	isometric(data);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	mlx_loop(data->mlx_ptr);
}