/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:41:01 by ajamshid          #+#    #+#             */
/*   Updated: 2024/06/04 14:42:55 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	initialize_values(t_stack *stack)
{
	stack->a->data = 0;
	stack->b->data = 0;
	stack->a->next = 0;
	stack->b->next = 0;
	stack->arguments = 0;
	stack->firsta = stack->a;
	stack->firstb = stack->b;
	stack->lasta = stack->a;
	stack->lastb = stack->b;
	stack->ints->counta = 0;
	stack->ints->countb = 0;
	stack->ints->mova = 101;
	stack->ints->movb = 101;
	stack->ints->movc = 2147483647;
	stack->smallesta = 0;
	stack->largestb = 0;
	return (0);
}

t_stack	*initializer(int argc)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		error(stack);
	stack->a = (t_data *)malloc(sizeof(t_data));
	stack->b = (t_data *)malloc(sizeof(t_data));
	stack->ints = (t_ints *)malloc(sizeof(t_ints));
	if (!stack || !stack->a || !stack->b || !stack->ints)
		error(stack);
	stack->argc = argc;
	initialize_values(stack);
	return (stack);
}

int	assign_arguments(t_stack *stack, char **argv)
{
	int	i;

	if (stack->argc == 2)
		stack->arguments = ft_split(argv[1], ' ');
	else
		stack->arguments = &argv[1];
	if (stack->arguments == 0)
		error(stack);
	i = 0;
	while (stack->arguments[i])
	{
		stack->a->data = ft_atoi(i, stack);
		stack->a->next = (t_data *)malloc(sizeof(t_data));
		stack->a->next->data = 0;
		stack->a->next->next = 0;
		i++;
		if (!stack->arguments[i])
			stack->lasta = stack->a;
		stack->a = stack->a->next;
	}
	stack->ints->counta = i;
	stack->a = stack->firsta;
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	i = 1;
	if (argc == 1)
		return (0);
	stack = initializer(argc);
	assign_arguments(stack, argv);
	is_duplicate(stack);
	smallesta_finder(stack);
	if (!checka(stack->firsta))
		clean_exit(stack);
	else
	{
		while (i)
			i = sorter(stack);
	}
	clean_exit(stack);
	return (0);
}
