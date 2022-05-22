#include <criterion/criterion.h>
#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

void	init_lst(t_list **lst)
{
	t_value	*j;
	
	for (int i = 0; i < 10; i++) {
		j = malloc(sizeof(t_value));
		if (j == NULL)
			exit(EXIT_FAILURE);
		j->val = i;
		ft_lstadd_back(lst, ft_lstnew((void *)j));
	}
}

void	init_random(t_list **lst)
{
	t_value	*j;
	
	for (int i = 0; i < 10; i++) {
		j = malloc(sizeof(t_value));
		if (j == NULL)
			exit(EXIT_FAILURE);
		j->val = rand();
		ft_lstadd_back(lst, ft_lstnew((void *)j));
	}
}

int	is_sorted(t_list *lst)
{
	if (ft_lstlen(&lst) < 1)
		return (1);
	while (lst != NULL)
	{
		if (*(t_value *)lst->content->val > *(t_value *)lst->next->content->val)
			return (0);
		lst = lst->next;	
	}
	return (1);
}

Test(swap, swap_1) {
	t_list	**lst;
	t_list	*init;
   
	init = NULL;
	lst = &init;
	init_lst(lst);
	cr_expect(*((t_value *)(*lst)->content->val) == 0);
	cr_expect(*((t_value *)(*lst)->next->content->val) == 1);
	cr_expect(*((t_value *)(*lst)->next->next->content->val) == 2);
	swap(lst, 0);
	cr_expect(*((t_value *)(*lst)->content->val) == 1);
	cr_expect(*((t_value *)(*lst)->next->content->val) == 0);
	cr_expect(*((t_value *)(*lst)->next->next->content->val) == 2);
	ft_lstclear(lst, &free);
}

Test(rotate, rotate_1) {
	t_list	**lst;
	t_list	*node;
	t_list	*init;
   
	init = NULL;
	lst = &init;
	init_lst(lst);
	rot(lst, 0);
	node = *lst;
	for (int i = 0; i < 10; i++) {
		if (*((t_value *)node->content->val) != 0)
			cr_expect(*((t_value *)node->content->val) == i + 1);
		else {
			cr_expect(node->next == NULL);
			break ;
		}
		node = node->next;
	}
	for (int i = 9; i >= 0; i--) {
		if (*((t_value *)node->content->val) != 0)
			cr_expect(*((t_value *)node->content->val) == i + 1);
		node = node->prev;
	}
	ft_lstclear(lst, &free);
}

Test(rotate, revrot_1) {
	t_list	**lst;
	t_list	*init;
	t_list	*node;

	init = NULL;
	lst = &init;
	init_lst(lst);
	rev_rot(lst, 0);
	node = *lst;
	for (int i = 0; i < 10; i++) {
		if (*(t_value *)node->content->val != 9)
			cr_expect(*(t_value *)node->content->val == i - 1);
		else
			cr_expect(node->prev == NULL);
		node = node->next;
	}
}

// manual test works fine, this doesn't for some reason
Test(push, push_1) {
	t_list	**stack_a;
	t_list	**stack_b;
	t_list	*init;

	init = NULL;
	stack_a = &init;
	stack_b = &init;
	init_lst(stack_a);
	init_lst(stack_b);
	push_b(stack_a, stack_b);
	cr_expect(*(t_value *)(*stack_a)->content->val == 1);
	cr_expect(*(t_value *)(*stack_b)->content->val == 0);
	cr_expect(*(t_value *)(*stack_b)->next->content->val == 0);
}

// Test(sort, presort) {
// 	t_list	**lst;
// 	t_list	*init;
// 
// 	init = NULL;
// 	lst = &init;
// 	init_random(lst);
// 	mergesort(lst);
// 	cr_expect(is_sorted(*lst));
// }
