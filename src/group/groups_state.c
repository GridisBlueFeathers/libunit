#include "libunit/group.h"


void	groups_state_free() {
	t_groups_state	*state = groups_state_get();
	t_group			*group_cur;
	t_group			*group_tmp;

	if (!state->head) {
		free(state);
		return ;
	}
	group_cur = state->head;
	while (group_cur) {
		group_tmp = group_cur->next;
		group_free(group_cur);
		group_cur = group_tmp;
	}
	free(state);
}

t_groups_state	*groups_state_init() {
	t_groups_state *state = (t_groups_state *)calloc(1, sizeof(t_groups_state));

	if (!state) {
		dprintf(STDERR_FILENO, "Groups state allocation failed");
		exit(1);
	}
	atexit(&groups_state_free);
	return (state);
}


t_groups_state	*groups_state_get() {
	static t_groups_state	*groups_state;

	if (!groups_state)
		groups_state = groups_state_init();
	return (groups_state);
}
