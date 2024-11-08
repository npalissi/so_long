/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:26:30 by npalissi          #+#    #+#             */
/*   Updated: 2024/10/14 15:44:08 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_abs(int i)
{
	if (i < 0)
		i *= -1;
	return ((unsigned int)i);
}

static int	nblen(int nb)
{
	int	i;

	if (nb == 0)
		return (1);
	i = 0;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static void	ft_is_negative(int *is_negative, int nb)
{
	*is_negative = nb < 0;
}

char	*ft_itoa(int nb)
{
	unsigned int	n;
	int				is_negative;
	char			*tab;

	ft_is_negative(&is_negative, nb);
	tab = malloc((nblen(nb) + is_negative + 1) * sizeof(char));
	if (!tab)
		return (0);
	tab[nblen(nb) + is_negative] = '\0';
	n = ft_abs(nb);
	nb = nblen(nb) + is_negative - 1;
	if (!n)
		tab[nb] = '0';
	else
	{
		while (n != 0)
		{
			tab[nb--] = (n % 10) + '0';
			n /= 10;
		}
	}
	if (is_negative)
		tab[0] = '-';
	return (tab);
}
