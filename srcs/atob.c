/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:04:52 by ajamshid          #+#    #+#             */
/*   Updated: 2024/06/04 15:20:21 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	planner_positive(t_stack *stack)
{
	while (stack->ints->mova < 0 && stack->ints->movb < 0)
	{
		rrr(stack);
		stack->ints->mova++;
		stack->ints->movb++;
	}
	while (stack->ints->mova > 0 && stack->ints->movb > 0)
	{
		rr(stack);
		stack->ints->mova--;
		stack->ints->movb--;
	}
	while (stack->ints->mova < 0)
	{
		rra(stack);
		stack->ints->mova++;
	}
	while (stack->ints->movb < 0)
	{
		rrb(stack);
		stack->ints->movb++;
	}
	return (0);
}

int	move_planner(t_stack *stack)
{
	planner_positive(stack);
	while (stack->ints->movb > 0)
	{
		rb(stack);
		stack->ints->movb--;
	}
	while (stack->ints->mova > 0)
	{
		if (stack->ints->mova == 1
			&& stack->firstb->data == stack->largestb->data
			&& stack->firsta->data > stack->firsta->next->data)
			sa(stack);
		else if (stack->ints->mova == 1
			&& stack->firstb->data != stack->largestb->data
			&& stack->firsta->data < stack->firstb->next->data
			&& stack->firsta->data > stack->lastb->data)
			sa(stack);
		else
			ra(stack);
		stack->ints->mova--;
	}
	reset_move_a_and_b(stack);
	return (pb(stack));
}

int	b_is_z(t_count *count, t_data *tempa, t_data *tempb, t_stack *stack)
{
	int	a;
	int	b;

	a = count->a;
	b = count->b;
	if (b == 0 && tempb->data == stack->largestb->data
		&& (tempa->data > tempb->data || tempa->data < stack->lastb->data))
	{
		calculate_number_of_moves(a, b, stack);
		return (0);
	}
	if (b == 0 && tempb->data != stack->largestb->data
		&& tempa->data > tempb->data && tempa->data < stack->lastb->data)
	{
		calculate_number_of_moves(a, b, stack);
		return (0);
	}
	return (1);
}

int	b_is_p(t_count *count, t_data *tempa, t_data *tempb, t_stack *stack)
{
	int	a;
	int	b;

	a = count->a;
	b = count->b;
	if (tempb->next->next && tempb->data > tempb->next->data
		&& tempa->data < tempb->data && tempa->data > tempb->next->data)
	{
		calculate_number_of_moves(a, b, stack);
		return (0);
	}
	if (tempb->next->next && tempb->data < tempb->next->data
		&& (tempa->data < tempb->data || tempa->data > tempb->next->data))
	{
		calculate_number_of_moves(a, b, stack);
		return (0);
	}
	return (1);
}

int	calculate_next_move(t_stack *stack)
{
	t_data	*tempa;
	t_data	*tempb;
	t_count	*count;

	count = (t_count *)malloc(sizeof(t_count));
	init(&tempa, &tempb, count, stack);
	while (tempa->next)
	{
		count->b = 0;
		tempb = stack->firstb;
		while (tempb->next && tempb->next->next)
		{
			if (!b_is_z(count, tempa, tempb, stack))
				break ;
			count->b++;
			if (!b_is_p(count, tempa, tempb, stack))
				break ;
			tempb = tempb->next;
		}
		tempa = tempa->next;
		count->a++;
	}
	free(count);
	return (0);
}
