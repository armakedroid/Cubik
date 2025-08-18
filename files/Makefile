CC = cc
SRCS = src/so_long.c src/check_map_inside.c src/check_map_utils.c src/map.c src/up_down.c src/check_map.c src/steps.c gnl/get_next_line.c gnl/get_next_line_utils.c ft_printf/ft_printf.c ft_printf/ft_check_type.c ft_printf/ft_print_chr.c ft_printf/ft_print_nums.c
SRCS_BONUS = src_bonus/so_long_bonus.c src_bonus/check_map_inside_bonus.c src_bonus/check_map_utils_bonus.c src_bonus/map_bonus.c src_bonus/up_down_bonus.c src_bonus/check_map_bonus.c src_bonus/steps_bonus.c gnl/get_next_line.c gnl/get_next_line_utils.c ft_printf/ft_printf.c ft_printf/ft_check_type.c ft_printf/ft_print_chr.c ft_printf/ft_print_nums.c
OBJ = $(SRCS:%.c=%.o)
OBJ_BONUS = $(SRCS_BONUS:%.c=%.o)
CFLGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -Lmlx -Imlx -lXext -lX11 -lm -lz -g3
LIBFT = libft/libft.a
NAME = so_long
NAME_BONUS = so_long_bonus
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@make bonus -C libft
	@make all -C ft_printf
	@$(CC) -o $(NAME) $(OBJ) $(LIBFT) $(MLXFLAGS)

bonus: $(OBJ_BONUS)
	@make bonus -C libft
	@make all -C ft_printf
	@$(CC) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBFT) $(MLXFLAGS)

%.o: %.c
	@$(CC) $(CFLGS) -c $< -o $@

clean:
	@make clean -C libft
	@make clean -C ft_printf
	@$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	@make fclean -C libft
	@make fclean -C ft_printf
	@$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
