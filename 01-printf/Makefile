FT 		=	ft_printf.c aff_unsigned.c aff.c

FT_BONUS	= ft_printf_bonus.c aff_unsigned.c aff.c check_flags.c

NAME	=	libftprintf.a
CC		=	gcc
AR		=	@ar -rcs
CFLAGS	+=	-W -Wall -Wextra -Werror
RM		=	rm -rf
INCLUDE	=	.

OBJS		=	$(FT:.c=.o)
OBJS_BONUS	=	$(FT_BONUS:.c=.o)

all		:
	@make $(NAME)

$(NAME)	:	$(OBJS)
	$(AR) $@ $(OBJS)
	@echo 'Librairy printf created !'

bonus	:	$(OBJS_BONUS)
	$(AR) $(NAME) $(OBJS_BONUS)
	@echo 'Librairy printf with come bonus created !'

clean	:
	$(RM) $(OBJS)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all