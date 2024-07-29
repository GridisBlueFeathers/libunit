#include "libunit/assert.h"

void	teardown(void (*teardown_func)())
{
	if (teardown_func)
		teardown_func();
}
