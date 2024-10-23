#include "libunit/assert_state.h"
#include "libft/color.h"

/**
 * Adds new node to the state list and puts it to the end
 */
void assert_state_list_append(t_assert_type type, t_assert_data *data, int label)
{
	t_assert_node	*new = assert_node_new(type, data, label);
	t_assert_state	*state = assert_state(GET);

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
}

void	assert_state_list_print_errors(t_assert_state *state) {
	t_assert_node	*cur = state->head;

	while (cur) {
		if (cur->succeed) {
			cur = cur->next;
			continue ;
		}
		switch (cur->type)
		{
			case INT_EQUAL:
				assert_int_equal_node_print(cur);
				break ;
			case STR_EQUAL:
				break ;
			case STR_ARR_EQUAL:
				assert_str_arr_equal_node_print(cur);
				break ;
		}
		cur = cur->next;
	}
}
