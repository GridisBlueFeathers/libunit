#include <stdio.h>
#include "libft/color.h"

int	assert_int_equal(int res, int exp)
{
	if (res == exp)
		return (printf("[ASSERT_OK]"), 1);
	printf(CLR CLR_RED_FG CLR_END"[ASSERT_KO]\n" CLR_RESET);
	printf("%d is not equal %d\n", res, exp);
	return (0);
}
