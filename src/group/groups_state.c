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
