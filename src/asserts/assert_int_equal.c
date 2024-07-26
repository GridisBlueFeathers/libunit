#include <stdio.h>
#include "libft/color.h"

int	assert_int_equal(int lable, int res, int exp)
{
	if (res == exp)
		return (printf(CLR CLR_GREEN_FG CLR_END "[%d.ASSERT_OK]" CLR_RESET, lable), 1);
	printf(CLR CLR_RED_FG CLR_END"[%d.ASSERT_KO]\n" CLR_RESET, lable);
	printf("%d is not equal %d\n", res, exp);
	return (0);
}
