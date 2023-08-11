NAME	=	libft.a
SRCS	=	src/
OBJS	=	lib/
CC		=	gcc
AR		=	ar rcs
CFLAGS	+=	-Wall -Wextra -Werror
RM		=	rm -f

all		:
	@make $(NAME)

$(OBJS)	:
	@mkdir	-d $(OBJS)
	$(CC) $(CFLAGS) -c $(SRCS)*.c $(OBJS)

$(NAME)	:	$(OBJS)
	$(AR) 

clean	:
	$(RM) 