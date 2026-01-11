/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:47:35 by ajamshid          #+#    #+#             */
/*   Updated: 2024/06/02 18:20:59 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, (const void *)&s[i], 1);
		i++;
	}
}

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while ((str[i] > 47 && str[i] < 58) || (str[i] == ' ' && str[i] != '\0'))
	{
		i++;
	}
	if ((str[i] > 47 && str[i] < 58) || str[i] == ' ' || str[i] == '\0')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

char	*ft_strdup(const char *s)
{
	char	*s2;
	int		i;

	s2 = (char *)malloc(ft_strlen(s) + 1);
	if (s2 == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return ((char *)s2);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
