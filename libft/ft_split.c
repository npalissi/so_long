/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 04:36:24 by npalissi          #+#    #+#             */
/*   Updated: 2024/10/14 15:44:59 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c, int *j)
{
	int	i;
	int	count;

	if (s == 0)
		return (0);
	*j = 0;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (i != 0 && s[i] == c && s[i - 1] != c)
			count++;
		i++;
	}
	if (i != 0 && s[i - 1] != c && i > 0)
		count++;
	return (count);
}

static int	ft_free_all(char **s, int size)
{
	while (size--)
		free(s[size]);
	free(s);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tbl;
	int		i;
	int		n_str;

	tbl = malloc(sizeof(char *) * (ft_count_words(s, c, &i) + 1));
	if (!tbl)
		return (0);
	while (s && *s)
	{
		while (*s == c)
			s++;
		n_str = 0;
		while (s[n_str] && s[n_str] != c)
			n_str++;
		if (n_str > 0)
		{
			tbl[i] = malloc(n_str + 1);
			if (!tbl[i] && ft_free_all(tbl, i))
				return (0);
			ft_strlcpy(tbl[i++], s, n_str + 1);
		}
		s += n_str;
	}
	tbl[i] = 0;
	return (tbl);
}
