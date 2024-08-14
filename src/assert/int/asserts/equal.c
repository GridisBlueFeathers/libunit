#include "libunit/assert.h"
#include "libft/color.h"

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
	t_assert_state *state = assert_state_get();

	state->label++;
	if (res == exp)
	{
		printf(CLR CLR_GREEN_FG CLR_END "[%d.ASSERT_OK] " CLR_RESET, state->label);
		return ;
	}
	printf(CLR CLR_RED_FG CLR_END"[%d.ASSERT_KO] " CLR_RESET, state->label);
	assert_state_list_append(INT_EQUAL, data, state->label);
}
