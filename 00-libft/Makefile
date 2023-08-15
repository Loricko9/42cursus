NAME	=	libft.a
SRCS	=	src/
OBJS	=	lib/
CC		=	gcc
AR		=	ar -rcs
CFLAGS	+=	-Wall -Wextra -Werror
RM		=	rm -f
INCLUDE	=	include

all		:
	@make $(NAME)

$(OBJS)	:
	@mkdir	-d $(OBJS)
	$(CC) -c $(SRCS)*.c $(OBJS)

$(NAME)	:	$(OBJS)
	$(AR) $@ $<*.o

clean	:
	$(RM) $(OBJS)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all