NAME = pipex
LIBFT = libft/libft.a
SRCS = src/count_command.c \
	   src/execute.c \
	   src/main.c \
	   src/resolve.c \
	   src/split_command.c \
	   src/split_utils.c \
	   src/utils.c
BONUS_SRCS = src/count_command.c \
			 src/error_handling.c \
			 src/execute_bonus.c \
			 src/execute.c \
			 src/handle_bonus.c \
			 src/main_bonus.c \
			 src/pipex_multi_bonus.c \
			 src/pipex_utils_bonus.c \
			 src/redirect_utils_bonus.c \
			 src/resolve.c \
			 src/split_command.c \
			 src/split_utils.c \
			 src/utils.c  \
			 src/wait_process_bonus.c

OBJS = $(SRCS:src/%.c=obj/%.o)
BONUS_OBJS = $(BONUS_SRCS:src/%.c=obj/%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -Ilibft/include 

all: obj $(NAME)

$(NAME): obj $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: obj $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

obj:
	mkdir -p obj

obj/%.o: src/%.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re bonus
