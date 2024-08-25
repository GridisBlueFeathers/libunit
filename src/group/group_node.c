#include "libunit/group.h"

t_group_node	*group_node_init(char *desc, void (*test)(void)) {
	t_group_node	*new_group_node = (t_group_node *)calloc(1, sizeof(t_group_node));

	if (!new_group_node) {
		dprintf(STDERR_FILENO, "Group node allocation failed");
		exit(1);
	}
	new_group_node->desc = desc;
	new_group_node->test = test;
	return (new_group_node);
}
