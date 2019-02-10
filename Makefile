# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/09 17:11:55 by mmonahan          #+#    #+#              #
#    Updated: 2019/02/10 10:59:13 by mmonahan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CHECK = check_and_read_tetrimin

SOLUT = solution

all: $(NAME)

$(NAME):
		#мэйк библиотеки
		@make -C libft/ fclean && make -C libft/
		#добавляем в библиотеку $(CHECK)
		@clang -Wall -Wextra -Werror -I libft/includes -o $(CHECK).o -c $(CHECK).c
		#добавляем в библиотеку $(SOLUT)
		@clang -Wall -Wextra -Werror -I libft/includes -o $(SOLUT).o -c $(SOLUT).c
		#добавляем в библиотеку main
		@clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
		#компилируем $(NAME)
		@clang -o $(NAME) main.o $(CHECK).o $(SOLUT).o -I libft/includes -L libft/ -lft
		#запускаем $(NAME)
		@./$(NAME)

clean:
		#удаляем файлы компиляции .gch
		@rm -f *.o
		@make -C libft/ clean

fclean: clean
		#удаляем main (убрать перед проверкой)
		@rm -f $(NAME)
		@make -C libft/ fclean

re: fclean all
