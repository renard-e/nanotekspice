##
## Makefile for tekspice in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/C++/cpp_nanotekspice/lib
## 
## Made by Rodrigue René
## Login   <rodrigue.rene@epitech.eu>
## 
## Started on  Mon Jan 23 04:31:07 2017 Rodrigue René
## Last update Sun Mar  5 19:07:19 2017 Gregoire Renard
##


CC	= g++

NAME    = libnanotekspice.a

SRCS    = Parser/Parser.cpp \
	  Parser/Setfct.cpp \
	  Parser/Chipsets.cpp \
	  Parser/Links.cpp \
	  Parser/Getfct.cpp \
	  Parser/Checkfct.cpp \
	  Parser/Commande.cpp \
	  Parser/Searchfct.cpp \
	  component/4081.cpp \
	  component/Computer.cpp \
	  component/Processor.cpp \
	  component/chipsets/input.cpp \
	  component/chipsets/output.cpp \
	  component/chipsets/trueFalseClock.cpp \
	  component/chipsets/4001.cpp \
	  component/chipsets/4008.cpp \
	  component/chipsets/4011.cpp \
	  component/chipsets/4013.cpp \
	  component/chipsets/4017.cpp \
	  component/chipsets/4030.cpp \
	  component/chipsets/4040.cpp \
	  component/chipsets/4069.cpp \
	  component/chipsets/4071.cpp \
	  component/chipsets/4094.cpp \
	  component/chipsets/4503.cpp \
	  component/chipsets/4514.cpp

OBJS	= $(SRCS:.cpp=.o)

RM	= rm -f

CXXFLAGS= -W -std=c++11 -Wall -Werror -I../includes/

all:    $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)
	cp -r libnanotekspice.a ../
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) ../libnanotekspice.a

re: fclean all

.PHONY: all re clean fclean
