#include "libunit/assert.h"
#include "libunit/group.h"

void	teardown(void (*teardown_func)())
{
	groups_execute();
	if (teardown_func)
		teardown_func();
}
