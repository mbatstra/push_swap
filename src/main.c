/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatstra <mbatstra@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:40:04 by mbatstra          #+#    #+#             */
/*   Updated: 2022/05/22 18:17:06 by mbatstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

static int	str_isdigit(char *str)
{
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

//doesn't yet check for duplicates
static void	validate_input(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
	{
		ft_printf("Usage: ./push_swap [int array]\n");
		exit(EXIT_FAILURE);
	}
	while (i < argc)
	{
		if (!str_isdigit(argv[i]))
		{
			ft_printf("Not an int: %s\n", argv[i]);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

//load input into linked list
static void	parse(t_list **list, int argc, char **argv)
{
	t_value	*arg;
	int		i;

	i = 1;
	*list = NULL;
	while (i < argc)
	{
		arg = (t_value *)malloc(sizeof(t_value));
		if (arg == NULL)
		{
			ft_lstclear(list, &free);
			exit(EXIT_FAILURE);
		}
		arg->val = ft_atoi(argv[i]);
		arg->i_old = i - 1;
		ft_lstadd_back(list, ft_lstnew((void *)arg));
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	validate_input(argc, argv);
	parse(&stack_a, argc, argv);
	parse(&stack_b, argc, argv);
	push_b(&stack_a, &stack_b);
	// push_a(&stack_a, &stack_b);
	while (stack_a != NULL)
	{
		ft_printf("%d\n", ((t_value *)stack_a->content)->val);
		stack_a = stack_a->next;
	}
	while (stack_b != NULL)
	{
		ft_printf("%d\n", ((t_value *)stack_b->content)->val);
		stack_b = stack_b->next;
	}
	// ft_lstclear(&stack_a, &free);
	return (0);
}
