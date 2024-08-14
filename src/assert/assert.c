#include "libunit/assert.h"

/**
 * Main function to create an assert
 * @param type assert type
 * @param data pointer to a struct with data which is checked for assertion
 * Currently availible types are int and char**
 */
void	assert(t_assert_type type, t_assert_data *data)
{
	switch (type) {
		case INT_EQUAL:
			assert_int_equal(data);
			break ;
		case STR_ARR_EQUAL:
			break ;
		case STR_EQUAL:
			break ;
	}
}
