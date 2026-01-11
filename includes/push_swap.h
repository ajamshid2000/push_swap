/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:43:33 by ajamshid          #+#    #+#             */
/*   Updated: 2024/06/04 15:19:37 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_count
{
	int				a;
	int				b;
}					t_count;

typedef struct s_data
{
	int				data;
	struct s_data	*next;
}					t_data;

typedef struct s_ints
{
	int				counta;
	int				countb;
	int				mova;
	int				movb;
	int				movc;
}					t_ints;

typedef struct s_stack
{
	t_data			*a;
	t_data			*b;
	t_data			*lasta;
	t_data			*lastb;
	t_data			*firsta;
	t_data			*firstb;
	t_ints			*ints;
	int				argc;
	char			**arguments;
	t_data			*largestb;
	t_data			*smallesta;
}					t_stack;

int					ft_atoi(int j, t_stack *stack);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					sa(t_stack *stack);
char				*ft_strdup(const char *s);
int					sa(t_stack *stack);
int					sb(t_stack *stack);
int					ss(t_stack *stack);
int					pa(t_stack *stack);
int					pb(t_stack *stack);
int					ra(t_stack *stack);
int					rb(t_stack *stack);
int					rr(t_stack *stack);
int					rrb(t_stack *stack);
int					rra(t_stack *stack);
int					rrr(t_stack *stack);
int					ft_str_is_numeric(char *str);
t_stack				*clean_exit(t_stack *stack);
int					checka(t_data *a);
int					checkb(t_data *b);
int					error(t_stack *stack);
int					is_duplicate(t_stack *stack);
int					sorter(t_stack *stack);
int					small_sorter(t_stack *stack);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
int					calculate_roration_in_same_direction(int posa, int posb);
int					calculate_roration_in_different_direction(int posa,
						int posb);
int					put_in_order_a(t_stack *stack);
int					calculate_number_of_moves_b_to_a(int a, int b,
						t_stack *stack);
int					move_planner_b_to_a(t_stack *stack);
int					calculate_next_move_b_to_a(t_stack *stack);
int					init(t_data **tempa, t_data **tempb, t_count *count,
						t_stack *stack);
int					calculate_number_of_moves(int a, int b, t_stack *stack);
int					move_planner(t_stack *stack);
int					calculate_next_move(t_stack *stack);
int					smallesta_finder(t_stack *stack);
int					checka_two(t_data *a, t_data *lasta);
int					reset_move_a_and_b(t_stack *stack);

#endif
