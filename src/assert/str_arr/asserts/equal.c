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

	ft_putstrarr_fd(res, STDOUT_FILENO);
	write(STDOUT_FILENO, " is not equal ", strlen(" is not equal "));
	ft_putstrarr_fd(exp, STDOUT_FILENO);
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

	state->label++;
	check = ft_strarr
	data->succeed = check;
	if (data->fn_failed)
		data->succeed = 0;
	assert_state_list_append(STR_ARR_EQUAL, data, state->label);
}
