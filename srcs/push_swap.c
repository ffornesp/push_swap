/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:33:07 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/14 10:16:02 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_swap(char	*str)
{
	t_list	*stack_a;

	stack_a = (struct t_list*)malloc(sizeof(struct t_list));
	if (!stack_a)
		return ;
	parse(str, &stack_a);
	return ;
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		push_swap(argv[1]);
	return (0);
}
