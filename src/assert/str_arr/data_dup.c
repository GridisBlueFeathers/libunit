#include "libunit/assert.h"
#include "libft/libft.h"
#include <string.h>

void	assert_str_arr_equal_data_free(t_assert_str_arr_data *data)
{
	int i = 0;
	ft_free(STR_ARR, data->res);
	ft_free(STR_ARR, data->exp);
	free(data);
}

t_assert_str_arr_data	*assert_str_arr_equal_data_dup(t_assert_data *data)
{
	t_assert_str_arr_data *res;

	res = (t_assert_str_arr_data *)calloc(1, sizeof(t_assert_str_arr_data));
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
		res->exp[i] = strdup(((char **)data->exp)[i]);
		if (!res->exp[i])
			return (assert_str_arr_equal_data_free(res), NULL);
		i++;
	}
	i = 0;
	while (((char **)data->res)[i]) {
		res->res[i] = strdup(((char **)data->res)[i]);
		if (!res->res[i])
			return (assert_str_arr_equal_data_free(res), NULL);
		i++;
	}

	return (res);
}
