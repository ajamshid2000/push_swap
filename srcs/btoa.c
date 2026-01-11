/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:11:03 by ajamshid          #+#    #+#             */
/*   Updated: 2024/06/04 15:20:57 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_moves(int b, t_stack *stack)
{
	if (b < 0)
	{
		while (b)
		{
			rra(stack);
			b++;
		}
	}
	if (b > 0)
	{
		while (b)
		{
			ra(stack);
			b--;
		}
	}
	return (0);
}

int	put_in_order_a(t_stack *stack)
{
	t_data	*temp;
	int		b;

	temp = stack->firsta;
	b = 0;
	while (temp != stack->smallesta)
	{
		temp = temp->next;
		b++;
	}
	if (b > (stack->ints->counta / 2))
		b = b - stack->ints->counta;
	make_moves(b, stack);
	return (0);
}

int	calculate_number_of_moves_b_to_a(int a, int b, t_stack *stack)
{
	int	moves;
	int	posa;
	int	posb;

	posa = a;
	posb = b;
	moves = 0;
	if (a > (stack->ints->countb / 2))
		posa = a - stack->ints->countb;
	if (b > (stack->ints->counta / 2))
		posb = b - stack->ints->counta;
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

int	init(t_data **tempa, t_data **tempb, t_count *count, t_stack *stack)
{
	*tempa = stack->firsta;
	*tempb = stack->firstb;
	count->a = 0;
	count->b = 0;
	return (0);
}

int	reset_move_a_and_b(t_stack *stack)
{
	stack->ints->mova = 101;
	stack->ints->movb = 101;
	stack->ints->movc = 2147483647;
	return (0);
}
