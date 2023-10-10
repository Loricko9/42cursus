FT 		=	ft_printf.c aff_unsigned.c aff.c

NAME	=	libftprintf.a
CC		=	gcc
AR		=	@ar -rcs
CFLAGS	+=	-W -Wall -Wextra -Werror
RM		=	rm -rf
INCLUDE	=	.

OBJS		=	$(FT:.c=.o)

all		:
	@make $(NAME)

$(NAME)	:	$(OBJS)
	$(AR) $@ $(OBJS)
	@echo 'Librairy printf created !'

clean	:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all