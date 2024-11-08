/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:21:40 by npalissi          #+#    #+#             */
/*   Updated: 2024/10/13 20:38:13 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*occurence;

	if (!*lst || !del)
	{
		*lst = 0;
		return ;
	}
	occurence = *lst;
	while (occurence->next)
	{
		tmp = occurence->next;
		ft_lstdelone(occurence, *del);
		occurence = tmp;
	}
	ft_lstdelone(occurence, del);
	*lst = 0;
}
