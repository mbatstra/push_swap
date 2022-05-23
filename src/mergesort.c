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

static t_list	**merge(t_list **left, t_list **right)
{
	t_list	**new;
	t_list	*init;
	t_list	*head_l;
	t_list	*head_r;

	init = NULL;
	new = &init;
	head_l = *left;
	head_r = *right;
	while (head_l != NULL && head_r != NULL)
	{
		if (head_l != NULL)
		{
			if (((t_list *)(head_l->content))->val < ((t_list *)(head_r->content))->val)
			{
				ft_lstadd_back(new, head_l);
				head_l = head_l->next;
			}
		}
		else if (head_r != NULL)
		{
			if (((t_list *)(head_l->content))->val >= ((t_list *)(head_r->content))->val)
			{
				ft_lstadd_back(new, head_r);
				head_r = head_r->next;
			}
		}
	}
	return (new);
}

// split lst into sublists of len 1, return merged result
t_list	**msort(t_list **lst)
{
	t_list	**lst1;
	t_list	**lst2;
	t_list	*init;
	t_list	*node;
	int		i;

	if (ft_lstsize(*lst) <= 1)
		return (lst);
	init = NULL;
	lst1 = &init;
	lst2 = &init;
	node = *lst;
	i = 0;
	while (node != NULL)
	{
		if (i < ft_lstsize(*lst) / 2)
			ft_lstadd_back(lst1, node);
		else
			ft_lstadd_back(lst2, node);
		node = node->next;
		i++;
	}
	msort(lst1);
	msort(lst2);
	return (merge(lst1, lst2));
}
