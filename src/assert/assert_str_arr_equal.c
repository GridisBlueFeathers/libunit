#include "libunit/assert.h"
#include "libft/color.h"
#include "libft/libft.h"

void	assert_str_arr_equal_data_free(t_assert_data_str_arr *data)
{
	int i = 0;
	ft_free(STR_ARR, data->res);
	ft_free(STR_ARR, data->exp);
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
		return (assert_str_arr_equal_data_free(res), NULL);
	i = 0;
	while (((char **)data->exp)[i]) {
		res->exp[i] = ft_strdup(((char **)data->exp)[i]);
		if (!res->exp[i])
			return (assert_str_arr_equal_data_free(res), NULL);
		i++;
	}
	i = 0;
	while (((char **)data->res)[i]) {
		res->res[i] = ft_strdup(((char **)data->res)[i]);
		if (!res->res[i])
			return (assert_str_arr_equal_data_free(res), NULL);
		i++;
	}

	return (res);
}

void	assert_str_arr_equal_node_print(t_assert_node *node)
{
	char **exp = ((t_assert_data_str_arr *)node->data)->exp;
	char **res = ((t_assert_data_str_arr *)node->data)->res;

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
