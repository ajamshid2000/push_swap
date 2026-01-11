/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:51:47 by ajamshid          #+#    #+#             */
/*   Updated: 2024/06/04 15:44:50 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rb(t_stack *stack)
{
	t_data	*temp;

	temp = stack->b;
	stack->b = stack->b->next;
	stack->firstb = stack->b;
	temp->next = stack->lastb->next;
	stack->lastb->next = temp;
	stack->lastb = temp;
	ft_putstr_fd("rb\n", 1);
	return (0);
}

int	rr(t_stack *stack)
{
	t_data	*temp;

	temp = stack->a;
	stack->a = stack->a->next;
	stack->firsta = stack->a;
	temp->next = stack->lasta->next;
	stack->lasta->next = temp;
	stack->lasta = temp;
	temp = stack->b;
	stack->b = stack->b->next;
	stack->firstb = stack->b;
	temp->next = stack->lastb->next;
	stack->lastb->next = temp;
	stack->lastb = temp;
	ft_putstr_fd("rr\n", 1);
	return (0);
}

int	rra(t_stack *stack)
{
	t_data	*temp;

	temp = stack->firsta;
	while (temp->next->next->next)
		temp = temp->next;
	temp->next = stack->lasta->next;
	stack->lasta->next = stack->firsta;
	stack->firsta = stack->lasta;
	stack->a = stack->lasta;
	stack->lasta = temp;
	ft_putstr_fd("rra\n", 1);
	return (0);
}

int	rrb(t_stack *stack)
{
	t_data	*temp;

	temp = stack->firstb;
	while (temp->next->next->next)
		temp = temp->next;
	temp->next = stack->lastb->next;
	stack->lastb->next = stack->firstb;
	stack->firstb = stack->lastb;
	stack->b = stack->lastb;
	stack->lastb = temp;
	ft_putstr_fd("rrb\n", 1);
	return (0);
}

int	rrr(t_stack *stack)
{
	t_data	*temp;

	temp = stack->firsta;
	while (temp->next->next->next)
		temp = temp->next;
	temp->next = stack->lasta->next;
	stack->lasta->next = stack->firsta;
	stack->firsta = stack->lasta;
	stack->a = stack->lasta;
	stack->lasta = temp;
	temp = stack->firstb;
	while (temp->next->next->next)
		temp = temp->next;
	temp->next = stack->lastb->next;
	stack->lastb->next = stack->firstb;
	stack->firstb = stack->lastb;
	stack->b = stack->lastb;
	stack->lastb = temp;
	ft_putstr_fd("rrr\n", 1);
	return (0);
}
