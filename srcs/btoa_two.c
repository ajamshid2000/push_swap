/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btoa_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 19:38:37 by ajamshid          #+#    #+#             */
/*   Updated: 2024/06/04 15:22:03 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	planner_b_to_a_one(t_stack *stack)
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
		rrb(stack);
		stack->ints->mova++;
	}
	while (stack->ints->movb < 0)
	{
		rra(stack);
		stack->ints->movb++;
	}
	return (0);
}

int	move_planner_b_to_a(t_stack *stack)
{
	planner_b_to_a_one(stack);
	while (stack->ints->movb > 0)
	{
		ra(stack);
		stack->ints->movb--;
	}
	while (stack->ints->mova > 0)
	{
		if (stack->ints->mova == 1
			&& stack->firsta->data == stack->smallesta->data
			&& stack->firstb->data < stack->firstb->next->data)
			sb(stack);
		else if (stack->ints->mova == 1
			&& stack->firsta->data != stack->smallesta->data
			&& stack->firstb->data > stack->firstb->next->data
			&& stack->firstb->data < stack->lasta->data)
			sb(stack);
		else
			rb(stack);
		stack->ints->mova--;
	}
	reset_move_a_and_b(stack);
	return (pa(stack));
}

int	b_is_zero(t_count *count, t_data *tempa, t_data *tempb, t_stack *stack)
{
	int	a;
	int	b;

	a = count->a;
	b = count->b;
	if (b == 0 && tempb->data == stack->smallesta->data
		&& (tempa->data < tempb->data || tempa->data > stack->lasta->data))
	{
		calculate_number_of_moves_b_to_a(a, b, stack);
		return (0);
	}
	if (b == 0 && tempb->data != stack->smallesta->data
		&& tempa->data < tempb->data && tempa->data > stack->lasta->data)
	{
		calculate_number_of_moves_b_to_a(a, b, stack);
		return (0);
	}
	return (1);
}

int	b_is_positive(t_count *count, t_data *tempa, t_data *tempb, t_stack *stack)
{
	int	a;
	int	b;

	a = count->a;
	b = count->b;
	if (tempb->next->next && tempb->data < tempb->next->data
		&& tempa->data > tempb->data && tempa->data < tempb->next->data)
	{
		calculate_number_of_moves_b_to_a(a, b, stack);
		return (0);
	}
	if (tempb->next->next && tempb->data > tempb->next->data
		&& (tempa->data > tempb->data || tempa->data < tempb->next->data))
	{
		calculate_number_of_moves_b_to_a(a, b, stack);
		return (0);
	}
	return (1);
}

int	calculate_next_move_b_to_a(t_stack *stack)
{
	t_data	*tempa;
	t_data	*tempb;
	t_count	*count;

	count = (t_count *)malloc(sizeof(t_count));
	init(&tempb, &tempa, count, stack);
	while (tempa->next)
	{
		count->b = 0;
		tempb = stack->firsta;
		while (tempb->next->next)
		{
			if (!b_is_zero(count, tempa, tempb, stack))
				break ;
			count->b++;
			if (!b_is_positive(count, tempa, tempb, stack))
				break ;
			tempb = tempb->next;
		}
		tempa = tempa->next;
		count->a++;
	}
	free(count);
	return (0);
}
