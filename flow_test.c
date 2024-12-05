#include <stdio.h>
#include <unistd.h>
#include "../push_swap/push_swap.h"
#include "../push_swap/libft/include/libft.h"
#include "criterion-2.4.2/include/criterion/assert.h"
#include "criterion-2.4.2/include/criterion/criterion.h"
#include "criterion-2.4.2/include/criterion/redirect.h"

t_stack	*create_node(int value);

t_stack *create_stack_ten()
{
	t_stack	*head = create_node(1);	
	t_stack	*stk_b = create_node(2);
	t_stack	*stk_c = create_node(3);	
	t_stack	*stk_d = create_node(4);
	t_stack	*stk_e = create_node(5);
	t_stack	*stk_f = create_node(6);
	t_stack	*stk_g = create_node(7);
	t_stack	*stk_h = create_node(8);
	t_stack	*stk_i = create_node(9);
	t_stack	*stk_j = create_node(10);
	stack_addback(&head, stk_b);
	stack_addback(&head, stk_c);
	stack_addback(&head, stk_d);
	stack_addback(&head, stk_e);
	stack_addback(&head, stk_f);
	stack_addback(&head, stk_g);
	stack_addback(&head, stk_h);
	stack_addback(&head, stk_i);
	stack_addback(&head, stk_j);
	return (head);
}

Test(flow_test, test_push_swap_flow_example)
{
	t_stack *stk_a = create_stack_ten();
	t_stack *stk_b = NULL;
	cr_assert_eq(10, stack_size(stk_a), "Expected size 10.");
	cr_assert_eq(10, stack_size(stk_a), "Expected size 10.");
	pb(&stk_a, &stk_b);
	pb(&stk_a, &stk_b);
	pb(&stk_a, &stk_b);
	pb(&stk_a, &stk_b);
	pb(&stk_a, &stk_b);
	cr_assert_eq(5, stack_size(stk_a), "Expected size 5.");
	cr_assert_eq(5, stack_size(stk_b), "Expected size 5.");
	cr_assert_eq(6, stk_a->value, "Expected result 6.");
	cr_assert_eq(10, stack_last(stk_a)->value, "Expected result 10.");
	cr_assert_eq(5, stk_b->value, "Expected result 5.");
	cr_assert_eq(1, stack_last(stk_b)->value, "Expected result 1.");
	rr(&stk_a, &stk_b);
	rr(&stk_a, &stk_b);
	cr_assert_eq(8, stk_a->value, "Expected result 8.");
	cr_assert_eq(7, stack_last(stk_a)->value, "Expected result 7.");
	cr_assert_eq(3, stk_b->value, "Expected result 3.");
	cr_assert_eq(4, stack_last(stk_b)->value, "Expected result 4.");
	rra(&stk_a);
	rb(&stk_b);
	cr_assert_eq(7, stk_a->value, "Expected result 7.");
	cr_assert_eq(6, stack_last(stk_a)->value, "Expected result 6.");
	cr_assert_eq(2, stk_b->value, "Expected result 2.");
	cr_assert_eq(3, stack_last(stk_b)->value, "Expected result 3.");
	pb(&stk_a, &stk_b);
	pb(&stk_a, &stk_b);
	cr_assert_eq(3, stack_size(stk_a), "Expected size 3.");
	cr_assert_eq(7, stack_size(stk_b), "Expected size 7.");
	cr_assert_eq(9, stk_a->value, "Expected result 9.");
	cr_assert_eq(6, stack_last(stk_a)->value, "Expected result 6.");
	cr_assert_eq(8, stk_b->value, "Expected result 8.");
	cr_assert_eq(3, stack_last(stk_b)->value, "Expected result 3.");
	rrr(&stk_a, &stk_b);
	cr_assert_eq(6, stk_a->value, "Expected result 6.");
	cr_assert_eq(10, stack_last(stk_a)->value, "Expected result 10.");
	cr_assert_eq(3, stk_b->value, "Expected result 3.");
	cr_assert_eq(4, stack_last(stk_b)->value, "Expected result 4.");
	pa(&stk_b, &stk_a);
	pa(&stk_b, &stk_a);
	cr_assert_eq(5, stack_size(stk_a), "Expected size 5.");
	cr_assert_eq(5, stack_size(stk_b), "Expected size 5.");
	cr_assert_eq(8, stk_a->value, "Expected result 8.");
	cr_assert_eq(10, stack_last(stk_a)->value, "Expected result 10.");
	cr_assert_eq(7, stk_b->value, "Expected result 7.");
	cr_assert_eq(4, stack_last(stk_b)->value, "Expected result 4.");
}
