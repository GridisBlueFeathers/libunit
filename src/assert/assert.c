#include "libunit/assert.h"

void	assert(t_assert_type type, t_assert_data *data)
{
	switch (type) {
		case INT_EQUAL:
			assert_int_equal(data);
			break ;
		case STR_EQUAL:
			break ;
		case STR_ARR_EQUAL:
			break ;
	}
}
