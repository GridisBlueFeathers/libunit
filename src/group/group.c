#include "libunit/group.h"

void	group_test_state_free(t_assert_state *state)
{
	t_assert_node	*node_cur;
	t_assert_node	*node_tmp;

	if (!state)
		return ;
	node_cur = state->head;
	while (node_cur)
	{
		node_tmp = node_cur->next;
		assert_state_node_free(node_cur);
		node_cur = node_tmp;
	}
	free(state);
}

/**
 * Frees all the memory allocated for group
 */
void	group_free(t_group *group) {
	t_group_test *test_cur;
	t_group_test *test_tmp;

	if (!group->head) {
		free(group);
		return ;
	}
	test_cur = group->head;
	while (test_cur) {
		test_tmp = test_cur->next;
		group_test_state_free(test_cur->test_state);
		free(test_cur);
		test_cur = test_tmp;
	}
	free(group);
}

t_group	*group_get(char *group_name) {
	t_group	*cur = groups_state_get()->head;

	while (cur) {
		if (!strcmp(cur->name, group_name))
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
	new_group->name = group_name;
	new_group->next = NULL;
	if (!groups_state_get()->tail) {
		groups_state_get()->head = new_group;
	} else {
		groups_state_get()->tail->next = new_group;
	}
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
