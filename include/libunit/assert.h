#ifndef ASSERT_H
# define ASSERT_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef enum e_assert_type
{
	INT_EQUAL,
	STR_EQUAL,
	STR_ARR_EQUAL,
} t_assert_type;

typedef struct s_assert_data
{
	void	*exp;
	void	*res;
	int		fn_failed;
	int		succeed;
}	t_assert_data;

void	assert(t_assert_type type, t_assert_data *data);

#endif
