SRCS 	=	Push_swap.c aff.c ft_printf.c list_utils.c \
			Sort.c Sort2.c check_av.c Sort3.c

OBJS	=	$(SRCS:.c=.o)
NAME	=	push_swap
CC		=	cc
CFLAGS	+=	-W -Wall -Wextra -Werror
RM		=	rm -rf
INCLUDE	=	.

all		:
	@make $(NAME)

$(NAME)	:	$(OBJS)
	$(CC) -o $@ -I. $(OBJS)
	@echo 'Compilation Success !!'

clean	:
	$(RM) $(OBJS)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all