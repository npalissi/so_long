/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 03:07:38 by npalissi          #+#    #+#             */
/*   Updated: 2024/10/14 15:42:56 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	char	*save_str;

	str = malloc(ft_strlen(s) + 1);
	if (!str)
		return (0);
	save_str = str;
	while (*s)
	{
		*str = f(str - save_str, *s++);
		str++;
	}
	*str = '\0';
	return (save_str);
}
