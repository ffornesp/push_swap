/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:46:10 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/24 09:59:45 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	finish_check(m_stack *stk)
{
	int		*max;
	int		*min;
	int		*n;
	t_list	*lst;

	lst = stk->stack_a;
	max = lst->content;
	min = lst->content;
	while (lst->next)
	{
		n = lst->next->content;
		if (*n > *max && *n > *min)
		{
			max = lst->next->content;
			lst = lst->next;
		}
		else
			return (0);
	}
	return (1);
}
