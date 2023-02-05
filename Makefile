NAME=minishell
SRCS=main.c\
		utils/ft_bzero.c utils/ft_strdup.c utils/ft_strlcat.c utils/ft_strlcpy.c utils/ft_strlen.c utils/ft_strncpy.c\
		evaluator/exec_inmain.c\
		tmp_func/fatal_error.c

OBJS=$(SRCS:%.c=%.o)
cc=cc
CFLAGS= -Wall -Werror -Wextra
all:$(NAME)

$(NAME):$(OBJS)
	gcc $(CFLAGS) $(OBJS) -lreadline -o $(NAME)

debug:$(OBJS)
	$(CC) $(CFLAGS) -fsanitize=address -fno-omit-frame-pointer $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all