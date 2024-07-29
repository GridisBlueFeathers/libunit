#include "libunit/assert.h"

void	test(void (*test_case)(void), char *desc)
{
	assert_state_reset();
	printf("%s\n", desc);
	test_case();
	assert_state_list_print();
}
