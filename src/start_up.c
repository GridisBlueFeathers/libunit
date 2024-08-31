#include "libunit/assert_state.h"
#include "libunit/group.h"

void	start_up(void (*start_up_func)())
{
	assert_state(GET);
	groups_state_get();
	if (start_up_func)
		start_up_func();
}
