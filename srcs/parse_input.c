/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:53:23 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/19 10:53:34 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_contents(t_list *stack)
{
	t_list	*aux;
	int		*i;

	aux = stack;
	ft_printf(YELLOW"\tSTACK A:\n"WHITE);
	while (aux)
	{
		i = aux->content;
		ft_printf("%d\n", *i);
		aux = aux->next;
	}
}

static char	*join_input(char **input)
{
	char	*out;
	char	*aux;
	int		i;

	i = 2;
	out = input[1];
	aux = NULL;
	while (input[i])
	{
		if (aux)
			free(aux);
		input[i] = check_zeros(input[i]);
		out = ft_strjoin(out, " ");
		aux = out;
		out = ft_strjoin(out, input[i]);
		free(aux);
		aux = out;
		i++;
	}
	return (out);
}

static t_list	*convert_to_tlist(char **input)
{
	int		i;
	int		n;
	int		*k;
	t_list	*stack;

	i = 0;
	while (input[i])
	{
		input[i] = check_zeros(input[i]);
		k = malloc(sizeof(int *));
		n = ft_atoi(input[i]);
		*k = n;
		if (n || input[i][0] == '0')
			ft_lstadd_back(&stack, ft_lstnew(k));
		else
		{
			while (input[i])
				free(input[i++]);
			ft_lstclear(&stack, (void *)ft_delete);
			exit(1);
		}
		free(input[i]);
		i++;
	}
	return (stack);
}

t_list	*parse(char **str)
{
	char	**out;
	char	*input;
	t_list	*stack;

	input = join_input(str);
	if (check_digits(input) < 1)
		return (NULL);
	out = ft_split(input, ' ');
	if (!out)
		return (NULL);
	free(input);
	stack = convert_to_tlist(out);
	free(out);
	if (check_duplicates(stack) < 1)
		return (NULL);
	check_contents(stack);
	return (stack);
}
