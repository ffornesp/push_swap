/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:24:47 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/20 20:09:08 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_printf.h"
# include <limits.h>

#ifndef GREEN
# define GREEN	"\x1B[32m"
#endif
#ifndef YELLOW
# define YELLOW "\x1B[33m"
#endif
#ifndef RED
# define RED	"\x1B[31m"
#endif
#ifndef WHITE
#define WHITE	"\x1B[37m"
#endif

typedef struct	lst_stack
{
	t_list	*stack_a;
	t_list	*stack_b;
}	m_stack;

typedef struct	s_action
{
	int		*amount;
	char	*moves;
}	c_action;

void	push_swap(char **str);

t_list	*parse(char **str);

int		check_digits(char *str);
int		check_duplicates(t_list *stack);
char	*check_zeros(char *input);
int		finish_check(m_stack *stk);

void	swap_a(m_stack *stk);
void	swap_b(m_stack *stk);
void	swap_s(m_stack *stk);

void	push_a(m_stack *stk);
void	push_b(m_stack *stk);

void	rotate_a(m_stack *stk);
void	rotate_b(m_stack *stk);
void	rotate_r(m_stack *stk);

void	reverse_rotate_a(m_stack *stk);
void	reverse_rotate_b(m_stack *stk);
void	reverse_rotate_r(m_stack *stk);

void	sort_3(m_stack *stk);

void	init_sort(m_stack *stk);
c_action	*calculate_moves(m_stack *stk, int *max_b, int *min_b);
c_action	*calc_rotation(t_list *lst, int *value, int stack, c_action *acts);

void		merge_rot_check(c_action *actions);
void	parse_move(m_stack *stk, char **moves);

void	add_to_moves(c_action *actions, int times, char *act);
void	stk_limits(t_list *lst, int *max, int *min);
void	check_contents(t_list *stack);

#endif
