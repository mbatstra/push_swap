/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatstra <mbatstra@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:17:20 by mbatstra          #+#    #+#             */
/*   Updated: 2022/05/10 12:43:09 by mbatstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*current;

	if (*lst == NULL)
		return ;
	temp = *lst;
	current = temp;
	while (temp != NULL)
	{
		current = temp;
		temp = temp->next;
		del(current->content);
		free(current);
	}
	*lst = NULL;
}
