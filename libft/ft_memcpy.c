/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:06:27 by npalissi          #+#    #+#             */
/*   Updated: 2024/10/09 15:51:06 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*tmp;

	if (!dest && !src)
		return (dest);
	tmp = dest;
	while (n--)
		*(unsigned char *)dest++ = *(unsigned char *)src++;
	return (tmp);
}
