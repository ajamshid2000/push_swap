NAME = push_swap
BONUS = bonus
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes
SRCS = srcs/ft_atoi.c srcs/ft_split.c srcs/main.c srcs/rules.c srcs/ft.c srcs/clean_all.c srcs/checker.c srcs/sorter.c srcs/btoa.c srcs/btoa_two.c srcs/rules_two.c srcs/atob.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	cc $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
