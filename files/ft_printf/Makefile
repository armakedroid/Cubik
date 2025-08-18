NAME = libftprintf.a
SRCS = ft_check_type.c ft_printf.c ft_print_nums.c ft_print_chr.c
HEADER = ft_printf.h
OBJS = $(SRCS:%.c=%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBA = ar rcs

all: $(NAME)

$(NAME) : $(OBJS)
	@$(LIBA) $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
