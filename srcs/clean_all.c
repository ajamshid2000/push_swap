/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:23:10 by ajamshid          #+#    #+#             */
/*   Updated: 2024/06/04 15:42:16 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	clean_chain(t_data *data)
{
	t_data	*temp;

	if (data)
	{
		temp = data;
		if (temp->next)
			clean_chain(temp->next);
		free((void *)temp);
	}
	return (0);
}

int	clean_args(char **arguments)
{
	int	i;

	i = 0;
	while (arguments[i])
	{
		free(arguments[i]);
		i++;
	}
	free(arguments);
	return (0);
}

t_stack	*clean_exit(t_stack *stack)
{
	t_stack	*s;

	s = stack;
	if (stack->firsta)
		clean_chain(stack->firsta);
	if (stack->firstb)
		clean_chain(stack->firstb);
	if (stack->ints)
		free(stack->ints);
	if (stack->arguments && (stack->argc <= 2))
		clean_args(stack->arguments);
	free(stack);
	exit(0);
	return (s);
}

int	ra(t_stack *stack)
{
	t_data	*temp;

	temp = stack->a;
	stack->a = stack->a->next;
	stack->firsta = stack->a;
	temp->next = stack->lasta->next;
	stack->lasta->next = temp;
	stack->lasta = temp;
	ft_putstr_fd("ra\n", 1);
	return (0);
}
