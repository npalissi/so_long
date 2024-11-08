/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:00:33 by npalissi          #+#    #+#             */
/*   Updated: 2024/10/09 21:05:25 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t size)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;

	if (!destination && !source)
		return (0);
	tmp_dest = (unsigned char *)destination;
	tmp_src = (unsigned char *)source;
	if (source > destination)
		return (ft_memcpy(destination, source, size));
	while (size--)
		tmp_dest[size] = tmp_src[size];
	return (tmp_dest);
}
