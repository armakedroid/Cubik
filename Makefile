CC = cc
SRCS = src/all.c src/all_imgs.c src/c_utils.c src/check_map.c src/copy_map.c src/find_end.c src/free_functions.c src/init.c src/main.c src/map_create.c src/map.c src/moves.c src/utils.c src/val_u.c src/validation.c gnl/get_next_line.c gnl/get_next_line_utils.c
OBJ = $(SRCS:%.c=%.o)
CFLGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -Lmlx_linux -Imlx_linux -lXext -lX11 -lm -lz -g3
LIBFT = libft/libft.a
NAME = cube3D
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@make bonus -C libft
	@make -C mlx_linux
	@$(CC) -o $(NAME) $(OBJ) $(LIBFT) $(MLXFLAGS)

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
