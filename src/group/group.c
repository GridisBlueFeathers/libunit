#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "libunit/group.h"

t_groups_state	*groups_state_init() {
	t_groups_state *state = (t_groups_state *)calloc(1, sizeof(t_groups_state));
	if (!state)
	{
		dprintf(STDERR_FILENO, "Groups state allocation failed");
		exit(1);
	}
	return (state);
}

t_groups_state	*groups_state_get() {
	static t_groups_state	*groups_state;

	if (!groups_state)
		groups_state = groups_state_init();
	return (groups_state);
}

t_group	*group_get(char *group_name) {
	t_group	*cur = groups_state_get()->head;
	while (cur) {
		if (strcmp(cur->group_name, group_name))
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

t_group	*group_add(char *group_name) {
	t_group *new_group = (t_group *)calloc(1, sizeof(t_group));

	if (!new_group) {
		dprintf(STDERR_FILENO, "Group allocation failied");
		exit(1);
	}
	groups_state_get()->tail->next = new_group;
	groups_state_get()->tail = new_group;
	return (new_group);
}

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

void	group_add_test(char *group_name, char *desc, void (*test)(void))
{
	t_group	*group = group_get(group_name);

	if (!group) {
		group = group_add(group_name);
		group->head = group_node_init(desc, test);
		group->tail = group->head;
		return ;
	}
	group->tail->next = group_node_init(desc, test);
	group->tail = group->tail->next;
}
