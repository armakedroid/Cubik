CC = cc
SRCS = $(wildcard src/*.c) $(wildcard gnl/*.c) 
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
