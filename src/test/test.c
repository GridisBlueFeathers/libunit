#include "libunit/assert_state.h"

/**
 * Prints node data based on node type
 */
void	test_print_assert_state()
{
	t_assert_state	*state = assert_state(GET);
	t_assert_node	*cur;

	assert_state_list_print_bages(state);
	printf("\n");
	if (!state->fail_amount)
		return ;
	cur = state->head;
	if (cur->fn_failed) {
		assert_function_failed();
		return ;
	}
	while (cur)
	{
		switch (cur->type)
		{
			case INT_EQUAL:
				assert_int_equal_node_print(cur);
				break ;
			case STR_EQUAL:
				break ;
			case STR_ARR_EQUAL:
				assert_str_arr_equal_node_print(cur);
				break ;
		}
		cur = cur->next;
	}
}

void	test(void (*test_case)(void), char *desc)
{
	assert_state(GET);
	assert_state(RESET);
	printf("Testing: %s\n", desc);
	test_case();
	printf("\n");
	test_print_assert_state();
	printf("\n\n");
}
