#ifndef GROUP_H
# define GROUP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "libunit/assert_state.h"

typedef struct s_group_test {
	char				*desc;
	struct s_group_test *next;
	void				(*test)(void);
	t_assert_state		*test_state;

} t_group_test;

typedef struct s_group {
	char			*name;
	int				has_fails;
	t_group_test	*head;
	t_group_test	*tail;
	struct s_group	*next;
} t_group;

typedef struct s_groups_state {
	t_group	*head;
	t_group	*tail;
} t_groups_state;

void	group_add_test(char *group_name, char *desc, void (*test)(void));

t_groups_state	*groups_state_init();
t_groups_state	*groups_state_get();

void	groups_execute();

t_group_test	*group_test_init(char *desc, void (*test)(void));
void			group_free(t_group *group);

#endif // !GROUP_H
