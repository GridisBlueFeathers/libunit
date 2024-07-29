#include "libunit/assert.h"

void	test(void (*test_case)(void), char *desc)
{
	assert_state_reset();
	printf("Testing: %s\n", desc);
	test_case();
	printf("\n");
	if (assert_state_get()->head)
		assert_state_list_print();
	printf("\n\n");
}
