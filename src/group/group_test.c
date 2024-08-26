#include "libunit/group.h"

t_group_test	*group_test_init(char *desc, void (*test)(void)) {
	t_group_test	*new_group_test = (t_group_test *)calloc(1, sizeof(t_group_test));

	if (!new_group_test) {
		dprintf(STDERR_FILENO, "Group test allocation failed");
		exit(1);
	}
	new_group_test->desc = desc;
	new_group_test->test = test;
	return (new_group_test);
}
