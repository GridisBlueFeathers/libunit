#include "libunit/assert.h"

void	start_up(void (*start_up_func)())
{
	assert_state_get();
	if (start_up_func)
		start_up_func();
}
