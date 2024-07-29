#include "libunit/assert.h"

void	assert_state_reset()
{
	t_assert_state *state = assert_state_get();

	state->label = 0;
	if (!state->head)
		return ;
	while (state->head)
	{
		state->tail = state->head->next;
		assert_state_node_free(state->head);
		state->head = state->tail;
	}
	state->fail_amount = 0;
}

t_assert_state *assert_state_init()
{
	t_assert_state *state;

	state = (t_assert_state *)calloc(1, sizeof(t_assert_state));
	if (!state)
	{
		dprintf(STDERR_FILENO, "State allocation failed\n");
		exit(1);
	}
	state->label = 0;
	state->head = NULL;
	state->tail = NULL;
	state->fail_amount = 0;
	atexit(&assert_state_free);
	return (state);
}

t_assert_state *assert_state_get()
{
	static t_assert_state *state = NULL;
	if (!state)
		state = assert_state_init();
	return (state);
}
