/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:33:13 by npalissi          #+#    #+#             */
/*   Updated: 2024/11/03 16:48:13 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len, int free_s)
{
	char	*tbl;
	size_t	len_s;
	size_t	i;

	len_s = ft_strlen(s);
	if (len_s < len + start)
		len = (len_s - start);
	if (len_s < start)
		len = 0;
	if (!len)
		return (ft_strdup(""));
	tbl = malloc(len + 1);
	if (!tbl)
		return (0);
	i = 0;
	while (s[i] && i < start + len)
	{
		if (i >= start)
			tbl[i - start] = s[i];
		i++;
	}
	tbl[i - start] = '\0';
	if (free_s)
		free(s);
	return (tbl);
}
