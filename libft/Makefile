SRCS	= ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_calloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memcmp.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strnstr.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strncpy.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putstr_len.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_nbrlen.c \
		ft_strsub.c \
		ft_strnew.c \
		ft_strdel.c


OBJS	= $(SRCS:.c=.o)

NAME	= libft.a

HEADS	= libft.h

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			@ar rc $(NAME) $(OBJS)
			@ranlib $(NAME)

all:		$(NAME)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		clean fclean all re
