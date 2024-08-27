#include "libunit/assert_state.h"

void	assert_int_equal_node_print(t_assert_node *node)
{
	int exp = ((t_assert_int_data *)node->data)->exp;
	int res = ((t_assert_int_data *)node->data)->res;

	printf("%d. %d is not equal %d\n", node->label, res, exp);
}

void	assert_int_equal(t_assert_data *data)
{
	int res = *((int *)data->res);
	int exp = *((int *)data->exp);
	t_assert_state *state = assert_state(GET);

	state->label++;
	if (res == exp)
		data->succeed = 1;
	else
		data->succeed = 0;
	if (data->fn_failed)
		data->succeed = 0;
	assert_state_list_append(INT_EQUAL, data, state->label);
}
