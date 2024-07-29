#include "libunit/assert.h"

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
			break ;
	}
	free(node);
}

void	assert_state_free()
{
	t_assert_state *state = assert_state_get();

	assert_state_reset();
	free(state);
}
