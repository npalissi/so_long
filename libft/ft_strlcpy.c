/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:11:41 by npalissi          #+#    #+#             */
/*   Updated: 2024/10/09 21:05:55 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	h;

	i = 0;
	h = 0;
	while (src[i])
	{
		if (size && (i < (size - 1)))
		{
			dst[h] = src[h];
			h++;
		}
		i++;
	}
	if (size != h)
		dst[h] = '\0';
	return (i);
}
