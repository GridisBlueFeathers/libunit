#include "libunit/assert.h"

void assert_state_fail_add(t_assert_type type, t_assert_data *data, int label)
{
	t_assert_node	*new;
	t_assert_state	*state = assert_state_get();

	new = (t_assert_node *)calloc(1, sizeof(t_assert_node));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Assert fail message allocation failed\n");
		exit(1);
	}
	new->data = data;
	new->type = type;
	new->label = label;
	state->fail_amount++;
	if (!state->tail)
	{
		state->tail = new;
		state->head = state->tail;
		return ;
	}
	state->tail->next = new;
	state->tail = new;
	return ;
}
