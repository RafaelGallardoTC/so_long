SRC		=		main \
				winUtils \
				renderUtils \
				colorUtils \
				key_hooks \
				tools \
				config \
				validate \
				extra_tools \
				exit \
				texture_loader \
				gnl \

FIL 		= 	$(addsuffix .c, $(addprefix files/, $(SRC)))
OBJS		=	$(FIL:.c=.o)

NAME		=	so_long
CFLAGS		=	-Wall -Werror -Wextra -g
MLX			=	-Lmlx -lmlx -framework OpenGL -framework AppKit -lm
RM			=	rm -f
CC			=	gcc
LIBFT		=	./libft
HEADS		=	so_long.h

all: $(NAME)

${NAME}: ${OBJS}
	@echo [so_long] Compiling mlx...
	@$(MAKE) -C ./mlx
	@echo [so_long] Compiling Libft...
	@$(MAKE) -C ./libft
	@mv mlx/libmlx.dylib .
	@${CC} ${OBJS} ${CFLAGS} ${MLX} ./libft/libft.a libmlx.dylib -o ${NAME}
	@echo [so_long] so_long successfully compiled. Run ./so_long \*.ber to read from a map.

clean:
	@$(MAKE) -C mlx clean
	@$(MAKE) -C libft fclean
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}
	@${RM} libmlx.dylib

bonus: all

re: fclean all

.PHONY: clean fclean re all bonus
