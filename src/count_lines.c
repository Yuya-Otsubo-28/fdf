/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:55:10 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/09/08 17:55:56 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

size_t	count_lines(char **lines)
{
	size_t	size;

	if (!lines)
		return (0);
	size = 0;
	while (lines[size])
		size++;
	return (size);
}
