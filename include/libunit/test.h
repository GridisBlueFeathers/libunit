#ifndef TEST_H
# define TEST_H

void	test(void (*test_case)(void), char *desc);
void	teardown(void (*teardown_func)());

#endif // !TEST_H
