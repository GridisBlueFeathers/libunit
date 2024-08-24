#ifndef GROUP_H
# define GROUP_H

typedef struct s_group_node {
	char				*desc;
	struct s_group_node *next;
	void				(*test)(void);
} t_group_node;

typedef struct s_group {
	char			*group_name;
	t_group_node	*head;
	t_group_node	*tail;
	struct s_group	*next;
} t_group;

typedef struct s_groups_state {
	t_group	*head;
	t_group	*tail;
} t_groups_state;

void	group_add_test(char *group_name, char *desc, void (*test)(void));

#endif // !GROUP_H
