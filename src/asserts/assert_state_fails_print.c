#include "libunit/assert.h"

void	assert_state_fails_print()
{
	t_assert_state	*state = assert_state_get();
	if (!state->head)
	{
		return ;
	}



}
