/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:51:52 by ajamshid          #+#    #+#             */
/*   Updated: 2024/06/04 15:21:27 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checka(t_data *a)
{
	t_data	*temp;

	temp = a;
	while (temp->next && temp->next->next)
	{
		if (temp->data > temp->next->data)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	checka_two(t_data *a, t_data *lasta)
{
	t_data	*temp;

	temp = a;
	if (temp->data > lasta->data)
	{
		while (temp->next && temp->next->next)
		{
			if (temp->data < temp->next->data)
				break ;
			temp = temp->next;
		}
	}
	while (temp->next && temp->next->next)
	{
		if (temp->data > temp->next->data)
			return (1);
		temp = temp->next;
	}
	if (temp->data > a->data)
		return (0);
	return (1);
}

int	checkb(t_data *b)
{
	t_data	*temp;

	temp = b;
	while (temp->next && temp->next->next)
	{
		if (temp->data < temp->next->data)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	is_duplicate(t_stack *stack)
{
	t_data	*temp;

	while (stack->a->next && stack->a->next->next)
	{
		temp = stack->a->next;
		while (temp->next)
		{
			if (stack->a->data == temp->data)
				error(stack);
			temp = temp->next;
		}
		stack->a = stack->a->next;
	}
	stack->a = stack->firsta;
	return (0);
}

int	small_sorter(t_stack *stack)
{
	if (stack->ints->counta == 1)
	{
		clean_exit(stack);
	}
	if (stack->ints->counta == 2 && stack->a->data > stack->a->next->data)
	{
		sa(stack);
		return (0);
	}
	if (stack->a->data > stack->a->next->data)
		sa(stack);
	if (stack->a->data < stack->a->next->data
		&& stack->a->next->data > stack->a->next->next->data)
		rra(stack);
	return (0);
}
