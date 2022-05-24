/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatstra <mbatstra@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:45:44 by mbatstra          #+#    #+#             */
/*   Updated: 2022/05/24 20:24:39 by mbatstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.c"

void	mov2b(t_list **stack_a, t_list **stack_b, t_list *node)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = *stack_a;
	while (temp != node)
	{
		temp = temp->next;
		i++;
	}

}

void	rsort(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;
	int		radix;

	radix = 0;
	node = *stack_a;
	while (!is_sorted(*stack_a))
	{
		while (node != NULL)
		{
			if (((t_value *)node->content)->i_new >> radix & 1)
				// push to b
				// reset node
			else
				node = node->next;
		}
		// push all to a
		radix++;
	}
}
