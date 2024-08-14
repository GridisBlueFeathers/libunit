#include "libunit/assert.h"

t_assert_data_int	*assert_int_data_dup(t_assert_data *data)
{
	t_assert_data_int *res;

	res = (t_assert_data_int *)calloc(1, sizeof(t_assert_data_int));
	if (!res)
		return (NULL);
	res->exp = *((int *)data->exp);
	res->res = *((int *)data->res);
	return (res);
}
