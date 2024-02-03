FILES 	=	main.c utils.c utils2.c utils3.c print.c exec.c exec_pipe.c exec_utils.c get_fd.c\
			ft_split.c change_line.c get_fd_heredoc.c utils_signal.c utils_fd.c \
			build_in.c build_in_utils.c build_in_utils_bis.c check.c cd_utils.c build_in_bis.c

NAME	=	minishell
CC		=	gcc
CFLAGS	+=	-W -Wall -Wextra -Werror -g
RM		=	rm -rf
INCLUDE	=	-I include/

SRCS_DIR	=	src/
OBJ_DIR 	=	obj/
OBJS		=	$(addprefix $(OBJ_DIR), $(FILES:.c=.o))
SRCS 		=	$(addprefix $(SRCS_DIR), $(FILES))

$(OBJ_DIR)%.o 	:	$(SRCS_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ -lreadline
	@echo "$(COLOUR_YELLOW)Compiling ... $(COLOUR_GREEN)[✔]	$<$(NO_COLOUR)"

all   : header message_all $(NAME)

make_OBJS_DIR	:
	@mkdir -p $(OBJ_DIR)

$(NAME)	:	make_OBJS_DIR $(OBJS) message_end
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $@ -lreadline

clean	:	header message_clean
	@$(RM) $(OBJ_DIR)

fclean	:	header message_fclean
	@$(RM) $(OBJ_DIR) $(NAME)

fclean_re	: header message_re
	@$(RM) $(OBJ_DIR) 
	@$(RM) $(NAME)

re		:	fclean_re $(NAME)

message_all:
	@echo "EXECUTION	: $(COLOUR_RED) [all]\n$(NO_COLOUR)"

message_clean:
	@echo "EXECUTION	: $(COLOUR_RED) [clean]\n$(NO_COLOUR)"

message_fclean:
	@echo "EXECUTION	: $(COLOUR_RED) [fclean]\n$(NO_COLOUR)"

message_re:
	@echo "EXECUTION	: $(COLOUR_RED) [re]\n$(NO_COLOUR)"

message_end:
	@echo "$(COLOUR_GREEN)\n╔═════════════════════════════╗$(NO_COLOUR)"
	@echo "$(COLOUR_GREEN)║   COMPILATION SUCCESS !!!   ║$(NO_COLOUR)"
	@echo "$(COLOUR_GREEN)╚═════════════════════════════╝$(NO_COLOUR)"

header:
	clear
	@echo "\033[32m _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____"
	@echo "|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|"
	@echo "\033[34m _ _                          _ _       ___                                       _        "
	@echo "| | | ___     ___  __ _ _   _| ( )__   ( _ )     __ _ _ __ _ __   __ _  __ _  ___( )__     "
	@echo '| | |/ _ \   / __|/ _` | | | | |/ __|  / _ \/\  / _` |  '__\|'  _ \ / _` |/ _` |/ _ \/ __|    '
	@echo '| | |  __/   \__ \ (_| | |_| | |\__ \ | (_>  < | (_| | |  | |_) | (_| | (_| |  __/\__ \    '
	@echo '|_|_|\___|___|___/\__,_|\__,_|_||___/  \___/\/  \__,_|_|  | .__/ \__,_|\__, |\___||___/    '
	@echo '        |_____|                        _         __ _ _   |_|          |___/               '
	@echo '                           /\/\   __ _| | _____ / _(_) | ___                               '
	@echo '                          /    \ / _` | |/ / _ \ |_| | |/ _ \                              '
	@echo '                         / /\/\ \ (_| |   <  __/  _| | |  __/                              '
	@echo '                         \/    \/\__,_|_|\_\___|_| |_|_|\___|                              '
	@echo "\033[32m _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ "
	@echo "|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\033[0m"
	@echo "PROGRAM		: $(NAME)\n"

# colors

COLOUR_RED		= \033[31m
COLOUR_YELLOW	= \033[33m
COLOUR_BLUE		= \033[34m
COLOUR_GREEN	= \033[32m
NO_COLOUR		= \033[0m
