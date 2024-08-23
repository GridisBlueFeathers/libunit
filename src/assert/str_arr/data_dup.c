#include "libunit/assert.h"
#include "libft/libft.h"
#include <string.h>

/**
 * Frees duplicated data of string arrays
 */
void	assert_str_arr_equal_data_free(t_assert_str_arr_data *data)
{
	ft_free(STR_ARR, data->res);
	ft_free(STR_ARR, data->exp);
	free(data);
}

/**
 * Duplicates data of string arrays to use later in outputting differences
 */
t_assert_str_arr_data	*assert_str_arr_equal_data_dup(t_assert_data *data)
{
	t_assert_str_arr_data *res;

	res = (t_assert_str_arr_data *)calloc(1, sizeof(t_assert_str_arr_data));
	if (!res)
		return (NULL);
	res->exp = ft_strarrdup((char **)data->exp);
	res->res = ft_strarrdup((char **)data->res);
	if (!res->exp || !res->res)
	{
		assert_str_arr_equal_data_free(res);
		res = NULL;
		return (NULL);
	}
	return (res);
}
