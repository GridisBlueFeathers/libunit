#include "libunit/assert.h"
#include "libft/color.h"

/**
 * Duplicates data to display it later
 */
void	*assert_state_list_get_data(t_assert_type type, t_assert_data *data)
{
	void	*res;

	switch(type)
	{
		case INT_EQUAL:
			res = (void *)assert_int_data_dup(data);
			break ;
		case STR_ARR_EQUAL:
			res = (void *)assert_str_arr_data_dup(data);
			break ;
		case STR_EQUAL:
			res = NULL;
			break ;
	}
	return (res);
}

/**
 * Adds new node to the state list and puts it to the end
 */
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
	if (!data->fn_failed)
		new->data = assert_state_list_get_data(type, data);
	if (!new->data && data->fn_failed)
	{
		dprintf(STDERR_FILENO, "Assert data allocation failed\n");
		free(new);
		exit(1);
	}
	new->type = type;
	new->label = label;
	new->fn_failed = data->fn_failed;
	new->succeed = data->succeed;
	if (!new->succeed || new->fn_failed)
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

/**
 * Prints [ASSERT_OK] and other bages
 */
void	assert_state_list_print_bages(t_assert_state *state)
{
	t_assert_node *cur = state->head;

	while (cur)
	{
		if (cur->succeed)
			printf(CLR CLR_GREEN_FG CLR_END "[%d.ASSERT_OK] " CLR_RESET, cur->label);
		else if (cur->fn_failed)
			printf(CLR CLR_RED_FG CLR_END "[%d.ASSERT_FAIL] " CLR_RESET, cur->label);
		else
			printf(CLR CLR_RED_FG CLR_END "[%d.ASSERT_KO] " CLR_RESET, cur->label);
		cur = cur->next;
	}
	printf("\n");
}

