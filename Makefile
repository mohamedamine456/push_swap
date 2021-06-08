# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/24 14:34:08 by mlachheb          #+#    #+#              #
#    Updated: 2021/06/08 18:16:48 by mlachheb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP_NAME = push_swap

CHECKER_NAME = checker

PUSH_SWAP_MAIN = push_swap.c

CHECKER_MAIN = checker.c


SRC = sort_three.c sort_five.c sort_hundred.c sort_more.c\
			 shared/check_args.c shared/fatal.c shared/fill_stack.c\
			 shared/ft_atoi.c shared/ft_split.c shared/get_next_line.c\
			 shared/helper_functions.c shared/operations.c\
			 shared/opers_functions.c shared/sort_operations.c\
			 shared/check_sort.c shared/apply_operations.c\
			 shared/copy_stack.c shared/replace_a_b.c\
			 shared/push_to_b.c shared/replace_stack.c\
			 shared/sort_top_five.c print_stack.c 

all: $(PUSH_SWAP_NAME)

$(PUSH_SWAP_NAME):
	gcc -Wall -Wextra -Werror $(SRC) $(PUSH_SWAP_MAIN) -o $(PUSH_SWAP_NAME)

clean:
	rm -rf $(PUSH_SWAP_NAME) 

fclean:
	rm -rf $(PUSH_SWAP_NAME) 

re: fclean all

debug:
	gcc -Wall -Wextra -Werror -g $(SRC) $(PUSH_SWAP_MAIN) -o $(PUSH_SWAP_NAME)

noflags:
	gcc $(SRC) $(PUSH_SWAP_MAIN) -o $(PUSH_SWAP_NAME)
