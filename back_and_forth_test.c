#include <stdio.h>
#include <unistd.h>
#include "../push_swap/push_swap.h"
#include "../push_swap/libft/include/libft.h"
#include "criterion-2.4.2/include/criterion/assert.h"
#include "criterion-2.4.2/include/criterion/criterion.h"
#include "criterion-2.4.2/include/criterion/redirect.h"

t_stack	*create_node(int value);
t_stack *create_stack_five();

Test(back_and_forth_suite, test_push_swap_full_pa_pb)
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
	pb(&stk_a, &stk_b);
	cr_assert_eq(3, stack_size(stk_a), "Expected size 3.");
	cr_assert_eq(2, stack_size(stk_b), "Expected size 2.");
	cr_assert_eq(3, stk_a->value, "Expected result is 3.");
	cr_assert_eq(5, stack_last(stk_a)->value, "Expected result is 5.");
	cr_assert_eq(2, stk_b->value, "Expected result is 2.");
	cr_assert_eq(1, stack_last(stk_b)->value, "Expected result is 1.");
	pb(&stk_a, &stk_b);
	cr_assert_eq(2, stack_size(stk_a), "Expected size 2.");
	cr_assert_eq(3, stack_size(stk_b), "Expected size 3.");
	cr_assert_eq(4, stk_a->value, "Expected result is 4.");
	cr_assert_eq(5, stack_last(stk_a)->value, "Expected result is 5.");
	cr_assert_eq(3, stk_b->value, "Expected result is 3.");
	cr_assert_eq(1, stack_last(stk_b)->value, "Expected result is 1.");
	pb(&stk_a, &stk_b);
	cr_assert_eq(1, stack_size(stk_a), "Expected size 1.");
	cr_assert_eq(4, stack_size(stk_b), "Expected size 4.");
	cr_assert_eq(5, stk_a->value, "Expected result is 5.");
	cr_assert_eq(5, stack_last(stk_a)->value, "Expected result is 5.");
	cr_assert_eq(4, stk_b->value, "Expected result is 4.");
	cr_assert_eq(1, stack_last(stk_b)->value, "Expected result is 1.");
	pb(&stk_a, &stk_b);
	cr_assert_eq(0, stack_size(stk_a), "Expected size 0.");
	cr_assert_eq(5, stack_size(stk_b), "Expected size 5.");
	cr_assert_eq(5, stk_b->value, "Expected result is 5.");
	cr_assert_eq(1, stack_last(stk_b)->value, "Expected result is 1.");
	pb(&stk_a, &stk_b);
	cr_assert_eq(0, stack_size(stk_a), "Expected size 0.");
	cr_assert_eq(5, stack_size(stk_b), "Expected size 5.");
	cr_assert_eq(5, stk_b->value, "Expected result is 5.");
	cr_assert_eq(1, stack_last(stk_b)->value, "Expected result is 1.");
	pa(&stk_b, &stk_a);
	cr_assert_eq(1, stack_size(stk_a), "Expected size 1.");
	cr_assert_eq(4, stack_size(stk_b), "Expected size 4.");
	cr_assert_eq(5, stk_a->value, "Expected result is 5.");
	cr_assert_eq(5, stack_last(stk_a)->value, "Expected result is 5.");
	cr_assert_eq(4, stk_b->value, "Expected result is 4.");
	cr_assert_eq(1, stack_last(stk_b)->value, "Expected result is 1.");
	pa(&stk_b, &stk_a);
	cr_assert_eq(2, stack_size(stk_a), "Expected size 2.");
	cr_assert_eq(3, stack_size(stk_b), "Expected size 3.");
	cr_assert_eq(4, stk_a->value, "Expected result is 4.");
	cr_assert_eq(5, stack_last(stk_a)->value, "Expected result is 5.");
	cr_assert_eq(3, stk_b->value, "Expected result is 3.");
	cr_assert_eq(1, stack_last(stk_b)->value, "Expected result is 1.");
	pa(&stk_b, &stk_a);
	cr_assert_eq(3, stack_size(stk_a), "Expected size 3.");
	cr_assert_eq(2, stack_size(stk_b), "Expected size 2.");
	cr_assert_eq(3, stk_a->value, "Expected result is 3.");
	cr_assert_eq(5, stack_last(stk_a)->value, "Expected result is 5.");
	cr_assert_eq(2, stk_b->value, "Expected result is 2.");
	cr_assert_eq(1, stack_last(stk_b)->value, "Expected result is 1.");
	pa(&stk_b, &stk_a);
	cr_assert_eq(4, stack_size(stk_a), "Expected size 4.");
	cr_assert_eq(1, stack_size(stk_b), "Expected size 1.");
	cr_assert_eq(2, stk_a->value, "Expected result is 2.");
	cr_assert_eq(5, stack_last(stk_a)->value, "Expected result is 5.");
	cr_assert_eq(1, stk_b->value, "Expected result is 1.");
	cr_assert_eq(1, stack_last(stk_b)->value, "Expected result is 1.");
	pa(&stk_b, &stk_a);
	cr_assert_eq(5, stack_size(stk_a), "Expected size 5.");
	cr_assert_eq(0, stack_size(stk_b), "Expected size 0.");
	cr_assert_eq(1, stk_a->value, "Expected result is 1.");
	cr_assert_eq(5, stack_last(stk_a)->value, "Expected result is 5.");
	pa(&stk_b, &stk_a);
	cr_assert_eq(5, stack_size(stk_a), "Expected size 5.");
	cr_assert_eq(0, stack_size(stk_b), "Expected size 0.");
	cr_assert_eq(1, stk_a->value, "Expected result is 1.");
	cr_assert_eq(5, stack_last(stk_a)->value, "Expected result is 5.");
}
