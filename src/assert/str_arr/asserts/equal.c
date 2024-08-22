#include "libunit/assert.h"
#include "libft/color.h"
#include "libft/libft.h"
#include <string.h>

/**
 * Prints both string arrays of a corresponding assert
 */
void	assert_str_arr_equal_node_print(t_assert_node *node)
{
	char **exp = ((t_assert_str_arr_data *)node->data)->exp;
	char **res = ((t_assert_str_arr_data *)node->data)->res;

	int i = 0;
	if (res)
	{
		printf("{");
		while (res[i])
		{
			printf("\"%s\", ", res[i]);
			i++;
		}
		printf("\"%s\"} is not equal ", res[i]);
	}
	else
		printf("NULL is not equal ");
	i = 0;
	if (exp)
	{
		printf("{");
		while (exp[i])
		{
			printf("\"%s\", ", exp[i]);
			i++;
		}
		printf("\"%s\"}\n", exp[i]);
	}
	else
		printf("NULL\n");
}

/**
 * Compares every string in two string arrays, asserts ok if every string is equal
 */
void	assert_str_arr_equal(t_assert_data *data)
{
	char **res = (char **)data->res;
	char **exp = (char **)data->exp;
	t_assert_state *state = assert_state_get();
	int i = 0;
	int check = 1;

	state->label++;
	while (res && exp && res[i] && exp[i]) {
		if ((!res[i] && exp[i]) || (res[i] && !exp[i]) || strcmp(res[i], exp[i])) {
			check = 0;
			break ;
		}
		i++;
	}
	if ((!res && exp) || (res && !exp))
		check = 0;
	if (check) {
		printf(CLR CLR_GREEN_FG CLR_END "[%d.ASSERT_OK] " CLR_RESET, state->label);
		return ;
	}
	printf(CLR CLR_RED_FG CLR_END"[%d.ASSERT_KO] " CLR_RESET, state->label);
	assert_state_list_append(STR_ARR_EQUAL, data, state->label);
}
