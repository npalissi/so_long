/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:18:04 by npalissi          #+#    #+#             */
/*   Updated: 2024/10/13 23:17:24 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*tbl;

	tbl = (char *)s;
	while (n)
	{
		if (*tbl == (char)c)
			return ((void *)tbl);
		--n;
		++tbl;
	}
	return (0);
}
