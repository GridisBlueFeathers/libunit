#include "libunit/group.h"

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


void	group_add_test(char *group_name, char *desc, void (*test)(void))
{
	t_group	*group = group_get(group_name);

	if (!group) {
		group = group_add(group_name);
		group->head = group_test_init(desc, test);
		group->tail = group->head;
		return ;
	}
	group->tail->next = group_test_init(desc, test);
	group->tail = group->tail->next;
}
