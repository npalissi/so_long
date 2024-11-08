/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:47:12 by npalissi          #+#    #+#             */
/*   Updated: 2024/11/07 10:49:10 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2, int free_s1, int free_s2)
{
	char	*tbl;
	char	*save_tbl;
	char	*save_s1;
	char	*save_s2;

	save_s1 = s1;
	save_s2 = s2;
	tbl = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!tbl)
		return (0);
	save_tbl = tbl;
	while (*s1)
		*tbl++ = *s1++;
	while (*s2)
		*tbl++ = *s2++;
	*tbl = '\0';
	if (free_s1 && s1)
		free(save_s1);
	if (free_s2)
		free(save_s2);
	return (save_tbl);
}
