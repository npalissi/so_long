/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:01:57 by npalissi          #+#    #+#             */
/*   Updated: 2024/10/14 15:42:25 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(char c, char const *set)
{
	while (*set && c != *set)
		set++;
	return (*set);
}

static int	ft_get_size_trim(char *s1, char const *set)
{
	char	*last_chr;
	int		i;

	if (!*s1)
		return (1);
	i = 0;
	last_chr = 0;
	while (*s1)
	{
		if (!ft_is_set(*s1, set))
			last_chr = s1;
		if (last_chr)
			i++;
		s1++;
	}
	if ((i - (int)(s1 - last_chr - 2)) < 0)
		return (1);
	return ((i - (int)(s1 - last_chr - 2)));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		size;
	char	*tbl;
	char	*save_tbl;

	size = ft_get_size_trim((char *)s1, set);
	tbl = malloc(size);
	if (!tbl)
		return (0);
	save_tbl = tbl;
	while (*s1 && size)
	{
		if ((!ft_is_set(*s1, set) || tbl != save_tbl) && --size)
			*tbl++ = *s1;
		s1++;
	}
	*tbl = '\0';
	return (save_tbl);
}
