FT 	=		ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			ft_strdup.c  ft_memset.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
			ft_toupper.c ft_tolower.c ft_atoi.c ft_calloc.c \
			ft_strjoin.c \
			ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c

NAME	=	libft.a
CC		=	gcc
AR		=	ar -rcs
CFLAGS	+=	-Wall -Wextra -Werror
RM		=	rm -rf
INCLUDE	=	include/

SRCS_DIR	=	src/
OBJ_DIR 	=	obj/
OBJS	=	$(addprefix $(OBJ_DIR), $(FT:.c=.o))
SRCS 	=	$(addprefix $(SRCS_DIR), $(FT))

$(OBJ_DIR)%.o 	:	$(SRCS_DIR)%.c
	$(CC) -I $(INCLUDE) -c $< -o $@

all		:
	@make $(NAME)

make_OBJS_DIR	:
	mkdir -p $(OBJ_DIR)

$(NAME)	:	make_OBJS_DIR $(OBJS)
	$(AR) $@ $(OBJS)

clean	:
	$(RM) $(OBJ_DIR)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all