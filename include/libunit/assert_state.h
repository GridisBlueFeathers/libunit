#ifndef ASSERT_STATE_H
# define ASSERT_STATE_H

#include "libunit/assert.h"
#include <string.h>

typedef enum e_state_action
{
	DETACH,
	GET,
	RESET,
	NULLIFY,
}	t_state_action;

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
	t_assert_data			*data;
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

t_assert_state	*assert_state(t_state_action action);

void	assert_state_list_append(t_assert_type type, t_assert_data *data, int label);
void	assert_state_list_print_bages(t_assert_state *state);
void	assert_state_list_print_errors(t_assert_state *state);

void	assert_state_free();
void	assert_state_reset(t_assert_state *state);
void	assert_state_node_free(t_assert_node *node);

t_assert_int_data	*assert_int_data_dup(t_assert_data *data);
void				assert_int_equal(t_assert_data *data);
void				assert_int_equal_node_print(t_assert_node *node);

void					assert_str_arr_equal(t_assert_data *data);
void					assert_str_arr_equal_node_print(t_assert_node *node);
t_assert_str_arr_data	*assert_str_arr_data_dup(t_assert_data *data);
void					assert_str_arr_data_free(t_assert_str_arr_data *data);

t_assert_node	*assert_node_new(t_assert_type type, t_assert_data *data, int label);

void	assert_not_supported();
void	assert_function_failed();

#endif
