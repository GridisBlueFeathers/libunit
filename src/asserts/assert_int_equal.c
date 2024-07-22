#include <stdio.h>

int	assert_int_equal(int res, int exp)
{
	if (res == exp)
		return (printf("[ASSERT_OK]"), 1);
	printf("[ASSERT_KO]\n");
	printf("%d is not equal %d\n", res, exp);
	return (0);
}
