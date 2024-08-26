#include "libunit/assert.h"

/**
 * Based on type of data that is stored in the node, frees the data and then frees the node
 */
void	assert_state_node_free(t_assert_node *node)
{
	switch (node->type)
	{
		case INT_EQUAL:
			free(node->data);
			break ;
		case STR_EQUAL:
			break ;
		case STR_ARR_EQUAL:
			assert_str_arr_data_free(node->data);
			break ;
	}
	free(node);
}

/**
 * Frees all the nodes in state list, sets state fail amount to 0, but doesn't free the state itself
 */
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

/**
 * Frees all the nodes in state list and frees the state
 */
void	assert_state_free()
{
	t_assert_state *state = assert_state_get();

	assert_state_reset();
	free(state);
}
