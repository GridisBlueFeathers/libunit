#include "libunit/assert_state.h"
#include "libft/libft.h"

/**
 * Based on type of data that is stored in the node, frees the data and then frees the node
 */
void	assert_state_node_free(t_assert_node *node)
{
	switch (node->type)
	{
		case INT_EQUAL:
			free(node->data);
			break ;
		case STR_EQUAL:
			break ;
		case STR_ARR_EQUAL:
			assert_str_arr_data_free((t_assert_str_arr_data *)node->data);
			break ;
	}
	free(node);
}

/**
 * Duplicates data to display it later
 */
t_assert_data	*assert_node_data_dup(t_assert_type type, t_assert_data *data)
{
	t_assert_data	*res;

	switch(type) {
		case INT_EQUAL:
			res = (t_assert_data *)assert_int_data_dup(data);
			break ;
		case STR_ARR_EQUAL:
			res = (t_assert_data *)assert_str_arr_data_dup(data);
			break ;
		case STR_EQUAL:
			res = NULL;
			break ;
	}
	return (res);
}

t_assert_node	*assert_node_new(t_assert_type type, t_assert_data *data, int label)
{
	t_assert_node	*new = (t_assert_node *)calloc(1, sizeof(t_assert_node));

	if (!new) {
		dprintf(STDERR_FILENO, "Assert node allocation failed\n");
		exit(1);
	}
	if (!data->fn_failed)
		new->data = assert_node_data_dup(type, data);
	if (!new->data && !data->fn_failed) {
		dprintf(STDERR_FILENO, "Assert data duplication failed\n");
		ft_free(STRUCT, &new);
		exit(1);
	}
	new->type = type;
	new->label = label;
	new->fn_failed = data->fn_failed;
	new->succeed = data->succeed;
	return (new);
}
