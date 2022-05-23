/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatstra <mbatstra@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:40:04 by mbatstra          #+#    #+#             */
/*   Updated: 2022/05/23 19:38:02 by mbatstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	*node;
	t_list	*init;

	init = NULL;
	stack_a = &init;
	validate_input(argc, argv);
	parse(stack_a, argc, argv);
	msort(stack_a, 'v');
	new_index(stack_a);
	node = *stack_a;
	ft_lstclear(stack_a, &free);
	system("leaks push_swap");
	return (0);
}
