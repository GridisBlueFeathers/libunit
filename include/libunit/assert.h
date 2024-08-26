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

typedef struct s_assert_int_data
{
	int		exp;
	int		res;
}	t_assert_int_data;

typedef struct s_assert_str_arr_data
{
	char	**exp;
	char	**res;
}	t_assert_str_arr_data;

typedef struct s_assert_node
{

	int						label;
	int						succeed;
	int						fn_failed;
	void					*data;
	t_assert_type			type;
	struct s_assert_node	*next;
}	t_assert_node;

typedef struct s_assert_state
{
	int label;
	int	fail_amount;
	t_assert_node *head;
	t_assert_node *tail;
}	t_assert_state;

void	assert(t_assert_type type, t_assert_data *data);
void	assert_not_supported();
void	assert_function_failed();

t_assert_state	*assert_state_get();

void	assert_state_list_append(t_assert_type type, t_assert_data *data, int label);
void	assert_state_list_print_bages(t_assert_state *state);

void	assert_state_free();
void	assert_state_reset();
void	assert_state_node_free(t_assert_node *node);

t_assert_int_data	*assert_int_data_dup(t_assert_data *data);
void				assert_int_equal(t_assert_data *data);
void				assert_int_equal_node_print(t_assert_node *node);

void					assert_str_arr_equal(t_assert_data *data);
void					assert_str_arr_equal_node_print(t_assert_node *node);
t_assert_str_arr_data	*assert_str_arr_data_dup(t_assert_data *data);
void					assert_str_arr_data_free(t_assert_str_arr_data *data);

#endif
