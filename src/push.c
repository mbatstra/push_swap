/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatstra <mbatstra@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:02:20 by mbatstra          #+#    #+#             */
/*   Updated: 2022/05/21 17:09:18 by mbatstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*swp;

	if (*stack_b == NULL || (*stack_b)->content == NULL)
		return ;
	swp = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev = NULL;
	swp->prev = NULL;
	swp->next = *stack_a;
	(*stack_a)->prev = swp;
	*stack_a = swp;
	ft_printf("pa\n");
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*swp;

	if (*stack_a == NULL || (*stack_a)->content == NULL)
		return ;
	swp = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	swp->prev = NULL;
	swp->next = *stack_b;
	(*stack_b)->prev = swp;
	*stack_b = swp;
	ft_printf("pb\n");
}
