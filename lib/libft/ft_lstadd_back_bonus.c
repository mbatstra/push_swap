/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatstra <mbatstra@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:17:03 by mbatstra          #+#    #+#             */
/*   Updated: 2022/05/10 13:49:34 by mbatstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*link;

	if (*lst == NULL)
		*lst = new;
	else
	{
		link = *lst;
		while (link->next)
			link = link->next;
		while (new->next)
		{
			new->prev = link;
			link->next = new;
			link = link->next;
			new = new->next;
		}
		new->prev = link;
		link->next = new;
		new->next = NULL;
	}
}
