/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatstra <mbatstra@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:56:11 by mbatstra          #+#    #+#             */
/*   Updated: 2022/05/10 15:52:21 by mbatstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	swap(t_list **stack, char mode)
{
	t_list	*swp;

	if (ft_lstsize(*stack) < 2)
		return ;
	swp = *stack;
	*stack = (*stack)->next;
	swp->next = (*stack)->next;
	(*stack)->next = swp;
	if (mode != 0)
		ft_printf("s%c\n", mode);
}

void	swap_s(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a, 0);
	swap(stack_b, 0);
	ft_printf("ss\n");
}
