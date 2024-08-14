#include "libunit/assert.h"

t_assert_int_data	*assert_int_data_dup(t_assert_data *data)
{
	t_assert_int_data *res;

	res = (t_assert_int_data *)calloc(1, sizeof(t_assert_int_data));
	if (!res)
		return (NULL);
	res->exp = *((int *)data->exp);
	res->res = *((int *)data->res);
	return (res);
}
