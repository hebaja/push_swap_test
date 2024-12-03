#include <stdio.h>
#include <unistd.h>
#include "../push_swap/push_swap.h"
#include "../push_swap/libft/libft.h"
#include "criterion-2.4.2/include/criterion/assert.h"
#include "criterion-2.4.2/include/criterion/criterion.h"
#include "criterion-2.4.2/include/criterion/redirect.h"

t_stack	*create_node(int value)
{
	return (stack_new(value));
}

t_stack *create_stack_five()
{
	t_stack	*head = create_node(1);	
	t_stack	*stk_b = create_node(2);
	t_stack	*stk_c = create_node(3);	
	t_stack	*stk_d = create_node(4);
	t_stack	*stk_e = create_node(5);
	stack_addback(&head, stk_b);
	stack_addback(&head, stk_c);
	stack_addback(&head, stk_d);
	stack_addback(&head, stk_e);
	return (head);
}

t_stack *create_stack_six()
{
	t_stack	*head = create_node(1);	
	t_stack	*stk_b = create_node(2);
	t_stack	*stk_c = create_node(3);	
	t_stack	*stk_d = create_node(4);
	t_stack	*stk_e = create_node(5);
	t_stack	*stk_f = create_node(6);
	stack_addback(&head, stk_b);
	stack_addback(&head, stk_c);
	stack_addback(&head, stk_d);
	stack_addback(&head, stk_e);
	stack_addback(&head, stk_f);
	return (head);
}

Test(push_swap_suite, test_push_swap_sa_one_nbs)
{
	t_stack *head = create_node(1);
	sa(&head);
	cr_assert_eq(1, head->value, "Expected result is 1.");
}

Test(push_swap_suite, test_push_swap_sa_2_nbs)
{
	t_stack	*head = create_node(1);	
	t_stack	*stk_b = create_node(2);
	stack_addback(&head, stk_b);
	sa(&head);
	cr_assert_eq(2, head->value, "Expected result is 2.");
	cr_assert_eq(1, head->next->value, "Expected result is 1.");
}

Test(push_swap_suite, test_push_swap_sa_5_nbs)
{
	t_stack *head = create_stack_five();
	sa(&head);
	cr_assert_eq(2, head->value, "Expected result is 2.");
	cr_assert_eq(1, head->next->value, "Expected result is 1.");
	cr_assert_eq(3, head->next->next->value, "Expected result is 3.");
}

Test(push_swap_suite, test_push_swap_sb_2_nbs)
{
	t_stack	*head = create_node(1);	
	t_stack	*stk_b = create_node(2);
	stack_addback(&head, stk_b);
	sb(&head);
	cr_assert_eq(2, head->value, "Expected result is 2.");
	cr_assert_eq(1, head->next->value, "Expected result is 1.");
}

Test(push_swap_suite, test_push_swap_sb_one_nbs)
{
	t_stack *stk = create_node(1);
	sb(&stk);
	cr_assert_eq(1, stk->value, "Expected result is 1.");
}

Test(push_swap_suite, test_push_swap_sb_5_nbs)
{
	t_stack *head = create_stack_five();
	sb(&head);
	cr_assert_eq(2, head->value, "Expected result is 2.");
	cr_assert_eq(1, head->next->value, "Expected result is 1.");
	cr_assert_eq(3, head->next->next->value, "Expected result is 3.");
}

Test(push_swap_suite, test_push_swap_ss)
{
	t_stack *stk_a = create_stack_five();
	t_stack	*stk_b = NULL;
	pb(&stk_a, &stk_b);
	pb(&stk_a, &stk_b);
	cr_assert_eq(3, stack_size(stk_a));
	cr_assert_eq(2, stack_size(stk_b));
	ss(&stk_a, &stk_b);
	cr_assert_eq(3, stack_size(stk_a));
	cr_assert_eq(2, stack_size(stk_b));
	cr_assert_eq(4, stk_a->value);
	cr_assert_eq(1, stk_b->value);
}

Test(push_swap_suite, test_push_swap_stack_len)
{
	t_stack *head = create_stack_five();
	size_t len = stack_size(head);
	cr_assert_eq(5, len, "Expected result size 5.");
}

Test(push_swap_suite, test_push_swap_pa)
{
	t_stack *stk_b = create_stack_five();
	t_stack *stk_a = NULL;
	cr_assert_eq(5, stack_size(stk_b), "Expected size 5.");
	cr_assert_eq(0, stack_size(stk_a), "Expected size 0.");
	cr_assert_eq(1, stk_b->value, "Expected result is 1.");
	cr_assert_eq(5, stack_last(stk_b)->value, "Expected result is 5.");
	pa(&stk_b, &stk_a);
	cr_assert_eq(4, stack_size(stk_b), "Expected size 4.");
	cr_assert_eq(1, stack_size(stk_a), "Expected size 1.");
	cr_assert_eq(2, stk_b->value, "Expected result is 2.");
	cr_assert_eq(5, stack_last(stk_b)->value, "Expected result is 5.");
	cr_assert_eq(1, stk_a->value, "Expected result is 1.");
}

Test(push_swap_suite, test_push_swap_pa_empty)
{
	t_stack *stk_b = NULL;
	t_stack *stk_a = NULL;
	cr_assert_eq(0, stack_size(stk_b), "Expected size 0.");
	cr_assert_eq(0, stack_size(stk_a), "Expected size 0.");
	pa(&stk_b, &stk_a);
	cr_assert_eq(0, stack_size(stk_b), "Expected size 0.");
	cr_assert_eq(0, stack_size(stk_a), "Expected size 0.");
}

Test(push_swap_suite, test_push_swap_pb)
{
	t_stack *stk_a = create_stack_five();
	t_stack *stk_b = NULL;
	cr_assert_eq(5, stack_size(stk_a), "Expected size 5.");
	cr_assert_eq(0, stack_size(stk_b), "Expected size 0.");
	cr_assert_eq(1, stk_a->value, "Expected result is 1.");
	cr_assert_eq(5, stack_last(stk_a)->value, "Expected result is 5.");
	pb(&stk_a, &stk_b);
	cr_assert_eq(4, stack_size(stk_a), "Expected size 4.");
	cr_assert_eq(1, stack_size(stk_b), "Expected size 1.");
	cr_assert_eq(2, stk_a->value, "Expected result is 2.");
	cr_assert_eq(5, stack_last(stk_a)->value, "Expected result is 5.");
	cr_assert_eq(1, stk_b->value, "Expected result is 1.");
}

Test(push_swap_suite, test_push_swap_pb_empty)
{
	t_stack *stk_a = NULL;
	t_stack *stk_b = NULL;
	cr_assert_eq(0, stack_size(stk_a), "Expected size 0.");
	cr_assert_eq(0, stack_size(stk_b), "Expected size 0.");
	pb(&stk_a, &stk_b);
	cr_assert_eq(0, stack_size(stk_a), "Expected size 0.");
	cr_assert_eq(0, stack_size(stk_b), "Expected size 0.");
}

Test(push_swap_suite, test_push_swap_ra)
{
	t_stack *head = create_stack_five();
	ra(&head);
	cr_assert_eq(5, stack_size(head));
	cr_assert_eq(2, head->value, "Expected result 2.");
	cr_assert_eq(1, stack_last(head)->value, "Expected result 1.");
}

Test(push_swap_suite, test_push_swap_rb)
{
	t_stack *head = create_stack_five();
	rb(&head);
	cr_assert_eq(5, stack_size(head));
	cr_assert_eq(2, head->value, "Expected result 2.");
	cr_assert_eq(1, stack_last(head)->value, "Expected result 1.");
}

Test(push_swap_suite, test_push_swap_rr)
{
	t_stack *stk_a = create_stack_six();
	t_stack	*stk_b = NULL;
	pb(&stk_a, &stk_b);
	pb(&stk_a, &stk_b);
	pb(&stk_a, &stk_b);
	cr_assert_eq(3, stack_size(stk_a));
	cr_assert_eq(3, stack_size(stk_b));
	rr(&stk_a, &stk_b);
	cr_assert_eq(3, stack_size(stk_a));
	cr_assert_eq(3, stack_size(stk_b));
	cr_assert_eq(5, stk_a->value, "Expected result 5.");
	cr_assert_eq(4, stack_last(stk_a)->value, "Expected result 4.");
	cr_assert_eq(2, stk_b->value);
	cr_assert_eq(3, stack_last(stk_b)->value);
}
