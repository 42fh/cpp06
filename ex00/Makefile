#CXX is short for CPP Compiler
CXX:=c++
NAME:=prg
SRCS:=main.cpp ScalarConverter.cpp
OBJS:= ${SRCS:.cpp=.o} 
CPPFLAGS:=-Wall -Wextra -Werror -std=c++98 

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

go: 
	make all
	./$(NAME)

ergo: 
	make re
	./$(NAME)

tests:
	./prg 0
	./prg 1
	./prg 0.0
	./prg 0.1
	./prg 123
	./prg -987
	./prg 123.456
	./prg -987.654
	./prg 123.456f
	./prg -987.654f
	./prg a
	./prg '*'
	./prg ' '
	./prg '%'

badtests:
	./prg 1a
	./prg a1
	./prg 1.0g
	./prg a1.0g
	./prg a1.0
	./prg aa

	

.PHONY: all clean fclean re go ergo
