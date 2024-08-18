#include "libunit/assert.h"
#include "libft/color.h"
#include <string.h>

/**
 * Prints both string arrays of a corresponding assert
 */
void	assert_str_arr_equal_node_print(t_assert_node *node)
{
	char **exp = ((t_assert_str_arr_data *)node->data)->exp;
	char **res = ((t_assert_str_arr_data *)node->data)->res;

	printf("{");
	int i = 0;
	while (res[i + 1])
	{
		printf("\"%s\", ", res[i]);
		i++;
	}
	printf("\"%s\"} is not equal", res[i]);
	i = 0;
	while (exp[i + 1])
	{
		printf("\"%s\", ", exp[i]);
		i++;
	}
	printf("\"%s\"}\n", exp[i]);
}

/**
 * Compares every string in two string arrays, asserts ok if every string is equal
 */
void	assert_str_arr_equal(t_assert_data *data)
{
	char **res = data->res;
	char **exp = data->exp;
	t_assert_state *state = assert_state_get();
	int i = 0;
	int check = 1;

	state->label++;
	while (res[i] && exp[i]) {
		if ((!res[i] && exp[i]) || (res[i] && !exp[i]) || strcmp(res[i], exp[i])) {
			check = 0;
			break ;
		}
		i++;
	}
	if (check) {
		printf(CLR CLR_GREEN_FG CLR_END "[%d.ASSERT_OK] " CLR_RESET, state->label);
		return ;
	}
	printf(CLR CLR_RED_FG CLR_END"[%d.ASSERT_KO] " CLR_RESET, state->label);
	assert_state_list_append(STR_ARR_EQUAL, data, state->label);
}
