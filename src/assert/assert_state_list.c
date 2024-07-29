#include "libunit/assert.h"

void	*assert_state_list_get_data(t_assert_type type, t_assert_data *data)
{
	void	*res;

	switch(type)
	{
		case INT_EQUAL:
			res = (void *)assert_int_equal_data_dup(data);
			break ;
		case STR_EQUAL:
			res = NULL;
			break ;
		case STR_ARR_EQUAL:
			res = NULL;
			break ;
	}
	return (res);
}

void assert_state_list_append(t_assert_type type, t_assert_data *data, int label)
{
	t_assert_node	*new;
	t_assert_state	*state = assert_state_get();

	new = (t_assert_node *)calloc(1, sizeof(t_assert_node));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Assert fail message allocation failed\n");
		exit(1);
	}
	new->data = assert_state_list_get_data(type, data);
	if (!new->data)
	{
		dprintf(STDERR_FILENO, "Assert data allocation failed\n");
		exit(1);
	}
	new->type = type;
	new->label = label;
	state->fail_amount++;
	if (!state->tail)
	{
		state->tail = new;
		state->head = state->tail;
		return ;
	}
	state->tail->next = new;
	state->tail = new;
	return ;
}

void	assert_state_list_print()
{
	t_assert_state	*state = assert_state_get();
	t_assert_node	*cur;
	t_assert_node	*temp;

	printf("\n");
	if (!state->head)
		return ;
	cur = state->head;
	while (cur)
	{
		temp = cur->next;
		switch (cur->type)
		{
			case INT_EQUAL:
				assert_int_equal_node_print(cur);
				break ;
			case STR_EQUAL:
				break ;
			case STR_ARR_EQUAL:
				break ;
		}
		cur = temp;
	}
}
