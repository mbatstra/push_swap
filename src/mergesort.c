/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatstra <mbatstra@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:47:57 by mbatstra          #+#    #+#             */
/*   Updated: 2022/05/21 19:48:50 by mbatstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// get nth element of list, or NULL if elemt doesn't exist
t_list	*lst_get(t_list *lst, int n)
{
	t_list	*node;

	node = lst;
	while (n > 0 && node != NULL)
	{
		node = node->next;
		n--;
	}
	return (node);
}

// split lst into sublists of len 1, return merged result
void	msort(t_list **lst, int len)
{
	t_list	**left;
	t_list	**right;
	t_list	*node;
	t_list	*init;
	int		i;

	if (ft_lstsize(*lst) <= 1)
		return (lst);
	init = NULL;
	left = &init;
	right = &init;
	node = *lst;
	i = 0;
	while (node != NULL)
	{
		if (i < len / 2)
			ft_lstadd_back(left, node);
		else
			ft_lstadd_back(right, node);
		i++;
		node = node->next;
	}
	msort(left, ft_lstsize(*left));
	msort(right, ft_lstsize(*right));
	merge(left, right);
}

void	merge(t_list **left, t_list **right)
{

}
