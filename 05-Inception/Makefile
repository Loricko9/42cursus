NAME=Inception

PATH_VOLUME_DB=C:\Users\Lorick\Documents\42cursus\05-Inception\db_data
PATH_VOLUME_WP=C:\Users\Lorick\Documents\42cursus\05-Inception\wp_data

all   : compose

compose	: header message_compose
	mkdir -p $(PATH_VOLUME_WP)
	mkdir -p $(PATH_VOLUME_DB)
	docker compose -f ./srcs/docker-compose.yml up -d

down	:	header message_down
	docker compose -f ./srcs/docker-compose.yml down

prune	:	header message_prune down
	docker system prune -a -f
	rm -rf $(PATH_VOLUME_WP)
	rm -rf $(PATH_VOLUME_DB)
	docker volume rm wp_volume db_volume

stop	: header message_stop
	docker compose -f ./srcs/docker-compose.yml stop

start	:	header message_start
	docker compose -f ./srcs/docker-compose.yml start

message_compose:
	@echo "EXECUTION	: $(COLOUR_RED) [compose]\n$(NO_COLOUR)"

message_down:
	@echo "EXECUTION	: $(COLOUR_RED) [down]\n$(NO_COLOUR)"

message_prune:
	@echo "EXECUTION	: $(COLOUR_RED) [prune]\n$(NO_COLOUR)"

message_stop:
	@echo "EXECUTION	: $(COLOUR_RED) [stop]\n$(NO_COLOUR)"

message_start:
	@echo "EXECUTION	: $(COLOUR_RED) [start]\n$(NO_COLOUR)"

header:
	@echo "\033[32m  _______   _______   _______   _______   _______   _______   _______   _______   _______ "
	@echo " /\\______\\ /\\______\\ /\\______\\ /\\______\\ /\\______\\ /\\______\\ /\\______\\ /\\______\\ /\\______\\"
	@echo " \\/______/ \\/______/ \\/______/ \\/______/ \\/______/ \\/______/ \\/______/ \\/______/ \\/______/"
	@echo "\033[34m ___       ___                                                   ___       __             "
	@echo "/\\_ \\     /\\_ \\                                                 /\\_ \\     /\\ \\            "
	@echo "\\//\\ \\    \\//\\ \\       __              ____     __      __  __  \\//\\ \\    \\ \\/      ____  "
	@echo "  \\ \\ \\     \\ \\ \\    /'__'\\  _______  /',__\\  /'__'\\   /\\ \\/\\ \\   \\ \\ \\    \\/      /',__\\ "
	@echo "   \\_\\ \\_    \\_\\ \\_ /\\  __/ /\\______\\/\\__, '\\/\\ \\L\\.\\_ \\ \\ \\_\\ \\   \\_\\ \\_         /\\__, '\\"
	@echo "   /\\____\\   /\\____\\\\\\_\\___\\ \\\\/______/\\/\\____/\\ \\__/.\\_\\ \\ \\____/   /\\____\\        \\/\\____/"
	@echo "   \\/____/   \\/____/ \\/____/          \\/___/  \\/__/\\/_/  \\/___/    \\/____/         \\/___/ "
	@echo "                       __                   ___          ___                             "
	@echo " /'\\_/'\\              /\\ \\                /'___\\  __    /\\_ \\                            "
	@echo "/\\      \\      __     \\ \\ \\/'\\      __   /\\ \\__/ /\\_\\   \\//\\ \\       __                  "
	@echo "\\ \\ \\__\\ \\   /'__'\\    \\ \\ , <    /'__'\\ \\ \\,__\ \\\/\\ \\    \\ \\ \\    /'__'\\                "
	@echo " \\ \\ \\_/\\ \\ /\\ \\L\\.\\_   \\ \\ \\\\\\'\\ /\\  __/  \\ \\ \\_/ \\ \\ \\    \\_\\ \\_ /\\  __/                "
	@echo "  \\ \\_\\\\  \\_\\\\\\ \\__/.\\_\\   \\ \\_\\ \\_\\\\ \\____\\  \\ \\_\\   \\ \\_\\   /\\____\\\\  \\____\\               "
	@echo "   \\/_/ \\/_/ \\/__/\\/_/    \\/_/\\/_/\\/____/   \\/_/    \\/_/   \\/____/ \\/____/               "
	@echo "\033[32m  _______   _______   _______   _______   _______   _______   _______   _______   _______ "
	@echo " /\\______\\ /\\______\\ /\\______\\ /\\______\\ /\\______\\ /\\______\\ /\\______\\ /\\______\\ /\\______\\"
	@echo " \\/______/ \\/______/ \\/______/ \\/______/ \\/______/ \\/______/ \\/______/ \\/______/ \\/______/ \033[0m \n"
	@echo "PROGRAM		: $(NAME)\n"

# colors

COLOUR_RED		= \033[31m
COLOUR_YELLOW	= \033[33m
COLOUR_BLUE		= \033[34m
COLOUR_GREEN	= \033[32m
NO_COLOUR		= \033[0m