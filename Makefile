CC = cc
SRCS = $(wildcard src/*.c) $(wildcard gnl/*.c) 
SRCS_BONUS = src_bonus/so_long_bonus.c src_bonus/check_map_inside_bonus.c src_bonus/check_map_utils_bonus.c src_bonus/map_bonus.c src_bonus/up_down_bonus.c src_bonus/check_map_bonus.c src_bonus/steps_bonus.c gnl/get_next_line.c gnl/get_next_line_utils.c ft_printf/ft_printf.c ft_printf/ft_check_type.c ft_printf/ft_print_chr.c ft_printf/ft_print_nums.c
OBJ = $(SRCS:%.c=%.o)
OBJ_BONUS = $(SRCS_BONUS:%.c=%.o)
CFLGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -Lmlx -Imlx -lXext -lX11 -lm -lz -g3
LIBFT = libft/libft.a
NAME = cube3D
NAME_BONUS = so_long_bonus
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@make bonus -C libft
	@$(CC) -o $(NAME) $(OBJ) $(LIBFT)

%.o: %.c
	@$(CC) $(CFLGS) -c $< -o $@

clean:
	@make clean -C libft
	@$(RM) $(OBJ)

fclean: clean
	@make fclean -C libft
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
