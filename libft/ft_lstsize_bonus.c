/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:13:14 by npalissi          #+#    #+#             */
/*   Updated: 2024/10/13 20:41:32 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*occurent;

	if (!lst)
		return (0);
	occurent = lst;
	i = 1;
	while (occurent->next)
	{
		occurent = occurent->next;
		i++;
	}
	return (i);
}
