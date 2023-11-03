SRCS 	=	check_map.c check_map2.c display_utils.c display.c utils_lst.c \
			get_map.c get_next_line_utils.c get_next_line.c main.c aff.c\
			edit_map.c ini_img.c display_utils2.c ft_printf.c edit_map2.c

OBJS	=	$(SRCS:.c=.o)
NAME	=	so_long
CC		=	cc
CFLAGS	+=	-W -Wall -Wextra -Werror
RM		=	rm -rf
INCLUDE	=	.
LIB		=	-Lminilibx-linux -lmlx_Linux -lX11 -lXext

all		:
	@make $(NAME)

$(NAME)	:	$(OBJS)
	$(CC) -o $@ -I. $(OBJS) $(LIB) 
	@echo 'Compilation Success !!'

clean	:
	$(RM) $(OBJS)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all