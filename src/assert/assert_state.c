#include "libunit/assert_state.h"
#include "libft/libft.h"

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
 * Frees all the nodes in state list, sets state fail amount to 0, but doesn't free the state itself
 */
void	assert_state_reset(t_assert_state *state)
{
	state->label = 0;
	state->fail_amount = 0;
	if (!state->head)
		return ;
	while (state->head)
	{
		state->tail = state->head->next;
		assert_state_node_free(state->head);
		state->head = state->tail;
	}
}

/**
 * Frees all the nodes in state list and frees the state
 */
void	assert_state_free()
{
	assert_state(RESET);
	assert_state(NULLIFY);
}

/**
 * If state exists already, returns it
 *
 * If state doesn't exist, initializes it and returns it
 */
t_assert_state *assert_state(t_state_action action)
{
	static t_assert_state *state = NULL;
	t_assert_state	*temp;

	switch (action) {
		case (GET): {
				if (!state)
					state = assert_state_init();
				return (state);
			}
		case (DETACH): {
				temp = state;
				state = NULL;
				return (temp);
			}
		case (RESET): {
				assert_state_reset(state);
				return (state);
			}
		case (NULLIFY): {
				ft_free(STRUCT, &state);
				return (NULL);
			}
	}
}
