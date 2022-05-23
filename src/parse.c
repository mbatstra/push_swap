/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatstra <mbatstra@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:31:16 by mbatstra          #+#    #+#             */
/*   Updated: 2022/05/23 19:37:19 by mbatstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

static int	str_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9') && (str[i] != '-' && i == 0))
			return (0);
		i++;
	}
	return (1);
}

// sort and check for neighboring duplicates
static void	check_dup(int argc, char **argv)
{
	t_list	**dup;
	t_list	*node;
	t_list	*init;
	int		i1;
	int		i2;

	init = NULL;
	dup = &init;
	parse(dup, argc, argv);
	msort(dup, 'v');
	node = *dup;
	while (node->next != NULL)
	{
		i1 = ((t_value *)(node->content))->val;
		i2 = ((t_value *)(node->next->content))->val;
		if (i1 == i2)
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		node = node->next;
	}
	ft_lstclear(dup, &free);
}

// check for valid nr of args, invalid chars and duplicates
void	validate_input(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	while (i < argc)
	{
		if (!str_isdigit(argv[i]))
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	check_dup(argc, argv);
}

void	new_index(t_list **lst)
{
	t_list	*node;
	int		i;

	node = *lst;
	i = 0;
	while (node != NULL)
	{
		((t_value *)node->content)->i_new = i;
		node = node->next;
		i++;
	}
}

//load input into linked list
void	parse(t_list **list, int argc, char **argv)
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
