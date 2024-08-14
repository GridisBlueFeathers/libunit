#include "libunit/assert.h"

/**
 * Allocates memory and sets initial values to state
 */
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

/**
 * If state exists already, returns it
 *
 * If state doesn't exist, initializes it and returns it
 */
t_assert_state *assert_state_get()
{
	static t_assert_state *state = NULL;
	if (!state)
		state = assert_state_init();
	return (state);
}
