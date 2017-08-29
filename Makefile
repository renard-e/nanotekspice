##
## Makefile for tekSpice in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/C++/cpp_nanotekspice
## 
## Made by Rodrigue René
## Login   <rodrigue.rene@epitech.eu>
## 
## Started on  Mon Jan 23 04:19:36 2017 Rodrigue René
## Last update Thu Mar  2 11:52:45 2017 Gregoire Renard
##

CC	=	g++

RM	=	rm -fr

OBJS	=	$(SRCS:.cpp=.o)

SRCS	=	main.cpp \

NAME	=	nanotekspice

CXXFLAGS=	-Wall -Werror -W -std=c++11 -I./includes/

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		make -C lib/
		$(CC) -o $(NAME) $(OBJS) -L./ -lnanotekspice

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)
		make fclean -C lib/

re	:	fclean all

.phony	:	all re clean fclean
