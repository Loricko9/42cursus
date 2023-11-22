FILES 	=	ft_split.c get_next_line.c get_next_line_utils.c \
			Pipex.c Pipex_utils.c Pipex_utils2.c Pipex_here_doc.c

NAME	=	pipex
CC		=	cc
CFLAGS	+=	-W -Wall -Wextra -Werror
RM		=	rm -rf
INCLUDE	=	-I include/

SRCS_DIR	=	src/
OBJ_DIR 	=	obj/
OBJS		=	$(addprefix $(OBJ_DIR), $(FILES:.c=.o))
SRCS 		=	$(addprefix $(SRCS_DIR), $(FILES))

$(OBJ_DIR)%.o 	:	$(SRCS_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all		:	$(NAME)

make_OBJS_DIR	:
	mkdir -p $(OBJ_DIR)

$(NAME)	:	make_OBJS_DIR $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $@
	@echo 'Compilation success !'

clean	:
	$(RM) $(OBJ_DIR)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all