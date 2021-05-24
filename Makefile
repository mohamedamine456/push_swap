# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/24 14:34:08 by mlachheb          #+#    #+#              #
#    Updated: 2021/05/24 19:05:09 by mlachheb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP_NAME = push_swap

CHECKER_NAME = checker

PUSH_SWAP_MAIN = push_swap.c

CHECKER_MAIN = checker.c

PUSH_SWAP_SRC = check_ps_sort.c sort_three.c sort_five.c\
				sort_hundred.c sort_more.c

CHECKER_SRC = read_operations.c

SHARED_SRC = shared/check_args.c shared/fatal.c shared/fill_stack.c\
			 shared/ft_atoi.c shared/ft_split.c shared/get_next_line.c\
			 shared/helper_functions.c shared/operations.c\
			 shared/opers_functions.c shared/sort_operations.c\
			 shared/check_sort.c shared/apply_operations.c\
			 shared/copy_stack.c shared/replace_a_b.c

PUSH_SWAP_OBJ = check_ps_sort.o sort_three.o sort_five.o\
				sort_hundred.o sort_more.o

CHECKER_OBJ = read_operations.o

SHARED_OBJ = check_args.o fatal.o fill_stack.o ft_atoi.o ft_split.o\
			 get_next_line.o helper_functions.o operations.o\
			 opers_functions.o sort_operations.o check_sort.o\
			 apply_operations.o copy_stack.o replace_a_b.o


all: $(CHECKER_NAME)

$(CHECKER_NAME):
	gcc -Wall -Wextra -Werror -c $(SHARED_SRC)
	gcc -Wall -Wextra -Werror -c $(CHECKER_SRC)
	gcc -Wall -Wextra -Werror -c $(PUSH_SWAP_SRC)
	gcc -Wall -Wextra -Werror $(PUSH_SWAP_MAIN) $(PUSH_SWAP_OBJ) $(SHARED_OBJ) -o $(PUSH_SWAP_NAME)
	gcc -Wall -Wextra -Werror $(CHECKER_MAIN) $(CHECKER_OBJ) $(SHARED_OBJ) -o $(CHECKER_NAME)

clean:
	rm -rf $(PUSH_SWAP_OBJ) $(SHARED_OBJ) $(CHECKER_OBJ)

fclean:
	rm -rf $(PUSH_SWAP_NAME) $(CHECKER_NAME)

re: fclean all

debug:
	gcc -Wall -Wextra -Werror -g -c $(SHARED_SRC)
	gcc -Wall -Wextra -Werror -g -c $(CHECKER_SRC)
	gcc -Wall -Wextra -Werror -g -c $(PUSH_SWAP_SRC)
	gcc -Wall -Wextra -Werror -g $(PUSH_SWAP_MAIN) $(PUSH_SWAP_OBJ) $(SHARED_OBJ) -o $(PUSH_SWAP_NAME)
	gcc -Wall -Wextra -Werror -g $(CHECKER_MAIN) $(CHECKER_OBJ) $(SHARED_OBJ) -o $(CHECKER_NAME)


noflags:
	gcc -c $(SHARED_SRC)
	gcc -c $(CHECKER_SRC)
	gcc -c $(PUSH_SWAP_SRC)
	gcc $(PUSH_SWAP_MAIN) $(PUSH_SWAP_OBJ) $(SHARED_OBJ) -o $(PUSH_SWAP_NAME)
	gcc $(CHECKER_MAIN) $(CHECKER_OBJ) $(SHARED_OBJ) -o $(CHECKER_NAME)
