FT 	=		ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			ft_strdup.c  ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
			ft_bzero.c ft_toupper.c ft_tolower.c ft_atoi.c ft_calloc.c ft_striteri.c \
			ft_strjoin.c ft_split.c ft_substr.c ft_strmapi.c ft_itoa.c ft_strtrim.c\
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
			ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c

FT_BONUS	=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

NAME	=	libft.a
CC		=	gcc
AR		=	@ar -rcs
CFLAGS	+=	-W -Wall -Wextra -Werror
RM		=	rm -rf
INCLUDE	=	.

SRCS_DIR	=	src/
OBJ_DIR 	=	obj/
OBJS		=	$(addprefix $(OBJ_DIR), $(FT:.c=.o))
SRCS 		=	$(addprefix $(SRCS_DIR), $(FT))
OBJS_BONUS	=	$(addprefix $(OBJ_DIR), $(FT_BONUS:.c=.o))
SRCS_BONUS	=	$(addprefix $(SRCS_DIR), $(FT_BONUS))

$(OBJ_DIR)%.o 	:	$(SRCS_DIR)%.c
	$(CC) -I$(INCLUDE) -c $< -o $@

all		:
	@make $(NAME)

make_OBJS_DIR	:
	mkdir -p $(OBJ_DIR)

$(NAME)	:	make_OBJS_DIR $(OBJS)
	$(AR) $@ $(OBJS)
	@echo 'Librairy created !'

bonus	:	make_OBJS_DIR $(OBJS_BONUS) $(OBJS)
	$(AR) $(NAME) $(OBJS) $(OBJS_BONUS)
	@echo 'Librairy with bonus created !'

clean	:
	$(RM) $(OBJ_DIR)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all