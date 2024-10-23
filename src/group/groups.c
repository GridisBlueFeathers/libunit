#include "libunit/group.h"

void	groups_execute() {
	t_groups_state	*state = groups_state_get();
	t_group			*group_cur;
	t_group_test	*group_test_cur;

	group_cur = state->head;
	while (group_cur) {
		printf("Testing group: %s\n", group_cur->name);
		group_test_cur = group_cur->head;
		while (group_test_cur) {
			group_test_cur->test();
			group_test_cur->test_state = assert_state(DETACH);
			if (group_test_cur->test_state->fail_amount)
				group_cur->has_fails = 1;
			assert_state_list_print_bages(group_test_cur->test_state);
			group_test_cur = group_test_cur->next;
		}
		printf("\n");
		if (!group_cur->has_fails) {
			group_cur = group_cur->next;
			continue ;
		}
		printf("Errors:\n");
		group_test_cur = group_cur->head;
		while (group_test_cur) {
			if (!group_test_cur->test_state->fail_amount) {
				group_test_cur = group_test_cur->next;
				continue ;
			}
			printf("In %s:\n", group_test_cur->desc);
			assert_state_list_print_errors(group_test_cur->test_state);
			group_test_cur = group_test_cur->next;
		}
		group_cur = group_cur->next;
	}
}
