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

#include "../includes/fdf.h"
#include "libft.h"

int	err_return(t_data *data)
{
	if (data)
		free_data(data);
	return (EXIT_FAILURE);
}

int	main(int argc, char *argv)
{
	t_data	*data;

	if (argc != 2)
		return (err_return(NULL));
	data = data_init();
	if (!data)
		return (err_return(NULL));
	data->map = make_map(argv[1]);
	if (!(data->map))
		return (err_return(data));
}