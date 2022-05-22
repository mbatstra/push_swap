/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatstra <mbatstra@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:52:07 by mbatstra          #+#    #+#             */
/*   Updated: 2022/05/17 10:39:22 by mbatstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	rot(t_list **stack, char mode)
{
	t_list	*head;
	t_list	*tail;

	head = *stack;
	tail = *stack;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = head;
	head->prev = tail;
	*stack = (*stack)->next;
	head->next = NULL;
	if (mode != 0)
		ft_printf("r%c\n", mode);
}

void	rot_r(t_list **stack_a, t_list **stack_b)
{
	rot(stack_a, 0);
	rot(stack_b, 0);
	ft_printf("rr\n");
}

void	rev_rot(t_list **stack, char mode)
{
	t_list	*head;
	t_list	*tail;

	head = *stack;
	tail = *stack;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = head;
	head->prev = tail;
	*stack = (*stack)->prev;
	(*stack)->prev = NULL;
	if (mode != 0)
		ft_printf("rr%c\n", mode);
}

void	rev_rot_r(t_list **stack_a, t_list **stack_b)
{
	rev_rot(stack_a, 0);
	rev_rot(stack_b, 0);
	ft_printf("rrr\n");
}
