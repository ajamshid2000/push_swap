/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:16:26 by ajamshid          #+#    #+#             */
/*   Updated: 2024/06/04 15:43:09 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack *stack)
{
	t_data	*temp;

	if (!stack->a->next || !stack->a->next->next)
		return (0);
	temp = stack->a;
	stack->a = stack->a->next;
	temp->next = stack->a->next;
	stack->a->next = temp;
	stack->firsta = stack->a;
	if (!stack->a->next->next->next)
		stack->lasta = stack->a->next;
	ft_putstr_fd("sa\n", 1);
	return (0);
}

int	sb(t_stack *stack)
{
	t_data	*temp;

	if (!stack->b->next || !stack->b->next->next)
		return (0);
	temp = stack->b;
	stack->b = stack->b->next;
	temp->next = stack->b->next;
	stack->b->next = temp;
	stack->firstb = stack->b;
	if (!stack->b->next->next->next)
		stack->lastb = stack->b->next;
	ft_putstr_fd("sb\n", 1);
	return (0);
}

int	ss(t_stack *stack)
{
	t_data	*temp;

	if (!stack->a->data || !stack->a->next->data)
		return (0);
	if (!stack->b->data || !stack->b->next->data)
		return (0);
	temp = stack->a;
	stack->a = stack->a->next;
	temp->next = stack->a->next;
	stack->a->next = temp;
	stack->firsta = stack->a;
	if (!stack->a->next->next->next)
		stack->lasta = stack->a->next;
	temp = stack->b;
	stack->b = stack->b->next;
	temp->next = stack->b->next;
	stack->b->next = temp;
	stack->firstb = stack->b;
	if (!stack->b->next->next->next)
		stack->lastb = stack->b->next;
	ft_putstr_fd("ss\n", 1);
	return (0);
}

int	pa(t_stack *stack)
{
	t_data	*temp;

	temp = stack->b;
	stack->b = stack->b->next;
	stack->firstb = stack->b;
	temp->next = stack->a;
	stack->a = temp;
	stack->firsta = stack->a;
	if (stack->firsta->data < stack->smallesta->data)
		stack->smallesta = stack->firsta;
	if (!stack->a->next->next)
		stack->lasta = temp;
	if (!stack->b->next)
		stack->lastb = stack->b;
	stack->ints->counta++;
	stack->ints->countb--;
	ft_putstr_fd("pa\n", 1);
	return (0);
}

int	pb(t_stack *stack)
{
	t_data	*temp;

	temp = stack->a;
	stack->a = stack->a->next;
	stack->firsta = stack->a;
	temp->next = stack->b;
	stack->b = temp;
	stack->firstb = stack->b;
	if (stack->smallesta == stack->firstb)
		smallesta_finder(stack);
	if (!stack->largestb || stack->largestb->data < stack->firstb->data)
		stack->largestb = stack->firstb;
	if (!stack->b->next->next)
		stack->lastb = temp;
	if (!stack->a->next)
		stack->lasta = stack->a;
	stack->ints->counta--;
	stack->ints->countb++;
	ft_putstr_fd("pb\n", 1);
	return (0);
}
