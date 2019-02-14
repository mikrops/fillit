# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/09 17:11:55 by mmonahan          #+#    #+#              #
#    Updated: 2019/02/10 14:21:38 by mmonahan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CHECK = validation

SOLUT = solution

INIT = initialisation

INST = instruments

all: $(NAME)

$(NAME):
		@echo "Make of library."
		@make -C libft/ fclean && make -C libft/
		@echo "Add in library $(CHECK)"
		@clang -Wall -Wextra -Werror -I libft/includes -o $(CHECK).o -c $(CHECK).c
		@echo "Add in library $(INIT)"
		@clang -Wall -Wextra -Werror -I libft/includes -o $(INIT).o -c $(INIT).c
		@echo "Add in library $(SOLUT)"
		@clang -Wall -Wextra -Werror -I libft/includes -o $(SOLUT).o -c $(SOLUT).c
		@echo "Add in library $(INST)"
		@clang -Wall -Wextra -Werror -I libft/includes -o $(INST).o -c $(INST).c
		@echo "Add in library main"
		@clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
		@echo "Сompilation $(NAME)"
		@clang -o $(NAME) main.o $(CHECK).o $(INIT).o $(SOLUT).o $(INST).o -I libft/includes -L libft/ -lft

clean:
		@echo "Delete files of compilation"
		@rm -f *.o
		@make -C libft/ clean

fclean: clean
		@echo "Delete $(NAME)"
		@rm -f $(NAME)
		@make -C libft/ fclean

re: fclean all
