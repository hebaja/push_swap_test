#include <stdio.h>
#include <unistd.h>
#include "../push_swap/push_swap.h"
#include "../push_swap/libft/libft.h"
#include "criterion-2.4.2/include/criterion/assert.h"
#include "criterion-2.4.2/include/criterion/criterion.h"
#include "criterion-2.4.2/include/criterion/redirect.h"

t_stack	*create_node(int value);

Test(stack_suite, test_stack_build)
{
	t_stack	*head = create_node(2);	
	t_stack	*node_b = create_node(11);
	t_stack	*node_c = create_node(21);	
	t_stack	*node_d = create_node(31);
	t_stack	*node_e = create_node(41);
	stack_addback(&head, node_b);
	stack_addback(&head, node_c);
	stack_addback(&head, node_d);
	stack_addback(&head, node_e);
	cr_assert_eq(2, head->value, "Expected result 0");
	cr_assert_eq(41, stack_last(head)->value, "Expected result 41");
	size_t size = stack_size(head);
	cr_assert_eq(5, size, "Expected size 5");
	stack_del_head(&head);
	cr_assert_eq(11, head->value, "Expected result 11");
	cr_assert_eq(41, stack_last(head)->value, "Expected result 41");
	size = stack_size(head);
	cr_assert_eq(4, size, "Expected size 4");
}
