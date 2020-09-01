/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:40:54 by trponess          #+#    #+#             */
/*   Updated: 2019/10/21 15:19:00 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/includes/libft.h"

# define NULL_VALUE (2147483647L + 1)
# define STACK_A_ID (2147483647L + 2)
# define STACK_B_ID (2147483647L + 3)

char	**clean_av(int ac, char **av);
int		swap(long **stack);
int		rotate(long **stack);
int		rev_rotate(long **stack);
int		pass_to(long **src, long **dest);
int		sswap(long **stack);
int		rrotate(long **stack);
int		rrev_rotate(long **stack);
int		ppass_to(long **src, long **dest);
int		program_2nb(long **stack_a);
int		program_3nb(long **stack_a);
int		program_4nb(long **stack_a, long **stack_b);
int		program_5nb(long **stack_a, long **stack_b);
int		program_over_5nb(long **stack_a, long **stack_b);
void	ft_exit(char *msg);
int		error_msg(int r, char *msg);
int		count(int len);
long	*init_stack(int ac, char **av, char opt);
void	display_stack(long *stack, char which);
int		is_sorted(long *stack);
int		size_stack(long *stack);
int		indexof_min_val(long *stack);
int		indexof_max_val(long *stack);
int		quick_rotate_to_top(long **stack, long nb);
void	clean_stack(long **stack, int len);
long	get_stack_id(long *stack);
void	checker(long *stack_a, long *stack_b);
int		push_swap(long **stack_a, long **stack_b);
long	*init_stack(int ac, char **av, char opt);
long	get_stack_id(long *stack);
void	display_stack(long *stack, char which);
int		is_sorted(long *stack);
int		size_stack(long *stack);
void	find_posa(long **stack_a, long *pos_a, int chunk[2]);
void	find_posb(long **stack_a, long pos_a, long *pos_b, int chunk[2]);
char	**check_args(int ac, char **av);
void	increase_chunk(int jump, int *c1, int *c2);
void	pass_b_sort_to_a(long **stack_b, long **stack_a, int *nb_moves);
int		action(long pos_a, long pos_b, long **stack_a, long **stack_b);
int		init_chunk(int *chunk1, int *chuck2, long **stack_a);
int		decale_right(long **stack);
int		decale_left(long **stack);
void	ft_dmemdel(char ***arrptr);
int		is_ope(char *line);

#endif
