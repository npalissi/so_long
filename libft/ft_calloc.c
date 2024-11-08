/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:02:24 by npalissi          #+#    #+#             */
/*   Updated: 2024/10/14 15:40:25 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned int	*tbl;

	if (!nmemb || !size)
		return (ft_strdup(""));
	if (nmemb * size > 2147483647 || (int)nmemb < 0 || (int)size < 0)
		return (0);
	tbl = malloc(size * nmemb);
	if (!tbl)
		return (0);
	ft_bzero(tbl, nmemb * size);
	return ((void *)tbl);
}
