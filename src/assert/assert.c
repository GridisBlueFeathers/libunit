#include "libunit/assert.h"

void	assert_not_supported()
{
	printf("This type of assert is not supported yet\n");
}

void	assert_function_failed()
{
	printf("Original function failed\n");
}

/**
 * Main function to create an assert
 *
 * Currently availible types are int and char**
 */
void	assert(t_assert_type type, t_assert_data *data)
{
	switch (type) {
		case INT_EQUAL:
			assert_int_equal(data);
			break ;
		case STR_ARR_EQUAL:
			assert_str_arr_equal(data);
			break ;
		case STR_EQUAL:
			assert_not_supported();
			break ;
	}
}
