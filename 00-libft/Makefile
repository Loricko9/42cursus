FT 	=	ft_strdup.c ft_strlen.c

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