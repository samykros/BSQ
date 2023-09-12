FLAGS = -Wall -Wextra -Werror
NAME = bsq
SRC_NAME = main.c
SRC_FLIES = ft_files.c
SRC_MDA = ft_mda.c

main: $(SRC_NAME) $(SRC_FLIES) $(SRC_MDA)
	cc $(FLAGS) $(SRC_NAME) $(SRC_FLIES) $(SRC_MDA) -o $(NAME)

clean: $(NAME)
	rm $(NAME)

fclean: $(NAME)
	rm $(NAME)
