#include "libunit/assert_state.h"

void	start_up(void (*start_up_func)())
{
	assert_state(GET);
	if (start_up_func)
		start_up_func();
}
