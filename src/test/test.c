#include "libunit/assert_state.h"

/**
 * Prints node data based on node type
 */
void	test_print_assert_state()
{
	t_assert_state	*state = assert_state(GET);
	t_assert_node	*cur;
	t_assert_node	*temp;

	assert_state_list_print_bages(state);
	if (!state->fail_amount)
		return ;
	cur = state->head;
	while (cur)
	{
		temp = cur->next;
		if (cur->fn_failed)
			assert_function_failed();
		else
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
		}
		cur = temp;
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
