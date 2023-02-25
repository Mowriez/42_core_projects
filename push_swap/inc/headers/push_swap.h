/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:20:24 by mtrautne          #+#    #+#             */
/*   Updated: 2023/02/20 01:23:22 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include "../libft/libft.h"

//linked list nodes for building stacks

typedef struct s_node
{
	int				index;
	struct s_node	*next;
}	t_node;

// array_list_build.c
void	build_array_single(long *arr, char *str);
void	build_array_multi(long *arr, int arg_cnt, char **arg_val);
void	index_array(long *arr, int arr_len);
void	build_list_a(long arr_len, long *ind_arr, t_node **stack_a);
void	build_stack_a(int arg_cnt, char **arg_val, t_node **stack_a);

// helper_fcts.c
int		ft_putstr_stderr(char *str);
int		count_input_args(char *str);
long	ft_atol(char *str);
void	is_stack_sorted(t_node **stack_a);

// input_check.c
void	check_input_shallow(int arg_cnt, char **arg_val);
void	error_print(void);
int		check_multi(int arg_cnt, char **arg_val);
int		check_num_array(long *arr, long arr_len);
int		check_for_duplicates(long *arr, long arr_len);

// list_manipulations.c
t_node	*make_new_node(int index);
void	add_node_start(t_node **list, t_node *new_node);
void	add_node_end(t_node **list, t_node *new_node);
long	list_len(t_node **list);
void	free_list(t_node **list);

// ps_operations_1.c
void	rotate_stack(t_node **stack_x);
void	reverse_rotate_stack(t_node **stack_x);
void	rotate_both(t_node **stack_a, t_node **stack_b);
void	reverse_rotate_both(t_node **stack_a, t_node **stack_b);
void	push_stack(t_node **stack_x, t_node **stack_y);

// ps_operations_2.c
void	swap_x(t_node **stack_x);
void	swap_both(t_node **stack_a, t_node **stack_b);
void	rotate_push(t_node **stack_a, t_node **stack_b);

// push_swap.c
void	sort_stack(t_node **stack_a, t_node **stack_b);
// // void	print_stack(char stack, t_node **stack_x);

// radix_sort.c
void	radix_sort(t_node **stack_a, t_node **stack_b);
void	sort_by_last_bit(int index, int i, t_node **stack_a, t_node **stack_b);
int		find_max_index(t_node **stack_a);
void	empty_stack_b(t_node **stack_a, t_node **stack_b);

// small_stack_sort_1.c
void	small_stack_sort(t_node **stack_a, t_node **stack_b);
void	sort_3(t_node **stack_x);
void	helper_sort_3(t_node **stack_x);
void	sort_4(t_node **stack_a, t_node **stack_b);
void	sort_5(t_node **stack_a, t_node **stack_b);

//small_stack_sort_2.c
void	reverse_sort_2(t_node **stack_b);

#endif
