/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatstra <mbatstra@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:47:57 by mbatstra          #+#    #+#             */
/*   Updated: 2022/05/23 19:23:53 by mbatstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

// split into left and right
// left points to head
// right one past middle point
static void	split_lst(t_list *head, t_list **left, t_list **right)
{
	t_list	*mid;
	int		i;

	i = 1;
	mid = head;
	while (i < ft_lstsize(head) / 2)
	{
		mid = mid->next;
		i++;
	}
	*left = head;
	*right = mid->next;
	mid->next = NULL;
}

// sort by old index, new index, or value
// other than sorting factor each block here is the same
static int	compare(t_list *left, t_list *right, char mode)
{
	if (mode == 'o')
	{
		if (((t_value *)(left->content))->i_old <= \
		((t_value *)(right->content))->i_old)
			return (1);
		return (0);
	}
	else if (mode == 'n')
	{
		if (((t_value *)(left->content))->i_new <= \
		((t_value *)(right->content))->i_new)
			return (1);
		return (0);
	}
	else
	{
		if (((t_value *)(left->content))->val <= \
		((t_value *)(right->content))->val)
			return (1);
		return (0);
	}
}

// recur through left and right to merge into new
static t_list	*merge(t_list *left, t_list *right, char mode)
{
	t_list	*new;

	if (left == NULL)
		return (right);
	else if (right == NULL)
		return (left);
	if (compare(left, right, mode))
	{
		new = left;
		new->next = merge(left->next, right, mode);
	}
	else
	{
		new = right;
		new->next = merge(left, right->next, mode);
	}
	return (new);
}

// split lst into sublists of len 1, return merged result
void	msort(t_list **lst, char mode)
{
	t_list	*head;
	t_list	*left;
	t_list	*right;

	if (ft_lstsize(*lst) <= 1)
		return ;
	head = *lst;
	split_lst(head, &left, &right);
	msort(&left, mode);
	msort(&right, mode);
	*lst = merge(left, right, mode);
}
