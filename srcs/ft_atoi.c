/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:39:59 by ajamshid          #+#    #+#             */
/*   Updated: 2024/06/02 18:24:23 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(t_stack *stack)
{
	ft_putstr_fd("Error\n", 2);
	if (stack)
		clean_exit(stack);
	exit(0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s2;
	unsigned int	i;
	unsigned int	size;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	size = ft_strlen(&s[start]);
	if (size < len)
		len = size;
	s2 = malloc(len + 1);
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		s2[i] = s[start + i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int	find_start_of_int(const char *nptr, int *sign, int i, t_stack *stack)
{
	while (nptr[i] == ' ' || (nptr[i] < 14 && nptr[i] > 8))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			*sign = *sign * -1;
		i++;
	}
	if (!(nptr[i] <= '9' && nptr[i] >= '0'))
		error(stack);
	return (i);
}

int	ft_atoi(int a, t_stack *stack)
{
	int			res;
	int			i;
	int			sign;
	const char	*nptr;
	int			j;

	j = 0;
	res = 0;
	i = 0;
	sign = 1;
	nptr = stack->arguments[a];
	i = find_start_of_int(nptr, &sign, i, stack);
	while (j <= 8 && nptr[i + j] <= '9' && nptr[i + j] >= '0')
		res = res * 10 + nptr[i + j++] - '0';
	if (j == 9 && nptr[i + j] && ((nptr[i + j] <= '7' && sign == 1) || (nptr[i
					+ j] <= '8' && sign == -1) || (res < 214748364)))
		res = res * 10 + nptr[i + j++] - '0';
	if (nptr[i + j])
		error(stack);
	return (res * sign);
	return (0);
}
