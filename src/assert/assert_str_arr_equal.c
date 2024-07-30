#include "libunit/assert.h"
#include "libft/color.h"
#include "libft/libft.h"

void	assert_str_err_equal_data_free(t_assert_data_str_arr *data)
{
	int i = 0;
	while (data->exp[i]) {
		free(data->exp[i]);
		i++;
	}
	i = 0;
	while (data->res[i]) {
		free(data->res[i]);
		i++;
	}
	free(data->exp);
	free(data->res);
	free(data);
}

t_assert_data_str_arr	*assert_str_arr_equal_data_dup(t_assert_data *data)
{
	t_assert_data_str_arr *res;

	res = (t_assert_data_str_arr *)calloc(1, sizeof(t_assert_data_str_arr));
	if (!res)
		return (NULL);
	int exp_arr_len = 0;
	int i = 0;
	while (((char **)data->exp)[i])
		i++;
	i++;
	int res_arr_len = 0;
	i = 0;
	while (((char **)data->res)[i])
		i++;
	i++;
	res->exp = (char **)calloc(exp_arr_len, sizeof(char *));
	res->res = (char **)calloc(res_arr_len, sizeof(char *));
	if (!res->exp || !res->res)
		return (NULL);
	i = 0;
	while (((char **)data->exp)[i]) {
		res->exp[i] = ft_strdup(((char **)data->exp)[i]);
		if (!res->exp[i])
			return (NULL);
		i++;
	}
	i = 0;
	while (((char **)data->res)[i]) {
		res->res[i] = ft_strdup(((char **)data->res)[i]);
		if (!res->res[i])
			return (NULL);
		i++;
	}

	return (res);
}

void	assert_int_equal_node_print(t_assert_node *node)
{
	int exp = ((t_assert_data_int *)node->data)->exp;
	int res = ((t_assert_data_int *)node->data)->res;

	printf("%d. %d is not equal %d\n", node->label, res, exp);
}

void	assert_str_arr_equal_node_print(t_assert_node *node)
{
	char **exp = ((t_assert_data_str_arr *)node->data)->exp;
}

void	assert_str_arr_equal(t_assert_data *data)
{
	char **res = data->res;
	char **exp = data->exp;
	t_assert_state *state = assert_state_get();
	int i = 0;
	int check = 1;

	state->label++;
	while (res[i] && exp[i]) {
		if ((!res[i] && exp[i]) || (res[i] && !exp[i]) || ft_strcmp(res[i], exp[i])) {
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
