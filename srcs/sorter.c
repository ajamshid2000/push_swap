/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:32:24 by ajamshid          #+#    #+#             */
/*   Updated: 2024/06/04 14:34:00 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_roration_in_same_direction(int posa, int posb)
{
	int	moves;
	int	sign;

	sign = 1;
	if (posa < 0 && posb < 0)
		sign = -1;
	posa = posa * sign;
	posb = posb * sign;
	if (posa == posb)
		moves = posa + 1;
	if (posa < posb && posb != 0)
		moves = posb + 1;
	else
		moves = posa + 1;
	if (posb < posa && posa != 0)
		moves = posa + 1;
	else
		moves = posb + 1;
	posa = posa * sign;
	posb = posb * sign;
	return (moves);
}

int	calculate_roration_in_different_direction(int posa, int posb)
{
	int	moves;
	int	sign;

	sign = 1;
	if (posa < 0)
	{
		posa = posa * -1;
		moves = posa + posb + 1;
		posa = posa * -1;
	}
	if (posb < 0)
	{
		posb = posb * -1;
		moves = posa + posb + 1;
		posb = posb * -1;
	}
	return (moves);
}

int	calculate_number_of_moves(int a, int b, t_stack *stack)
{
	int	moves;
	int	posa;
	int	posb;

	posa = a;
	posb = b;
	moves = 0;
	if (a > (stack->ints->counta / 2))
		posa = a - stack->ints->counta;
	if (b > (stack->ints->countb / 2))
		posb = b - stack->ints->countb;
	if ((posa < 0 && posb < 0) || (posa >= 0 && posb >= 0))
		moves = calculate_roration_in_same_direction(posa, posb);
	if ((posa >= 0 && posb < 0) || (posa < 0 && posb >= 0))
		moves = calculate_roration_in_different_direction(posa, posb);
	if (moves < stack->ints->movc)
	{
		stack->ints->movc = moves;
		stack->ints->mova = posa;
		stack->ints->movb = posb;
	}
	return (0);
}

int	smallesta_finder(t_stack *stack)
{
	t_data	*temp;

	temp = stack->firsta;
	stack->smallesta = temp;
	while (temp->next)
	{
		if (stack->smallesta->data > temp->data)
			stack->smallesta = temp;
		temp = temp->next;
	}
	return (0);
}

int	sorter(t_stack *stack)
{
	if (stack->ints->counta < 4)
		while (checka(stack->firsta))
			small_sorter(stack);
	if (!checka_two(stack->firsta, stack->lasta) && !stack->b->next)
		return (put_in_order_a(stack));
	if (!checka_two(stack->firsta, stack->lasta) && stack->b->next)
	{
		if (!stack->smallesta)
			smallesta_finder(stack);
		while (stack->firstb->next)
		{
			calculate_next_move_b_to_a(stack);
			if (stack->ints->movc != 2147483647)
				move_planner_b_to_a(stack);
		}
		return (put_in_order_a(stack));
	}
	calculate_next_move(stack);
	if (stack->ints->movc != 2147483647)
		move_planner(stack);
	if (checka_two(stack->firsta, stack->lasta) && stack->ints->countb < 2)
		pb(stack);
	return (1);
}
