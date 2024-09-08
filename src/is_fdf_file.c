/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_fdf_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:28:27 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/09/08 15:36:21 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

t_bool  is_fdf_file(char *filename)
{
    size_t  tail;

    tail = ft_strlen(filename);
    if (tail < 5)
        return (FALSE);
    return (!ft_strncmp(&filename[tail - 4], ".fdf", 4));
}
