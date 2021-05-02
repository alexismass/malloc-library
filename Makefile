##
## EPITECH PROJECT, 2019
## makefile
## File description:
## desc
##

BIN 	=	exe

LIB_BIN		=	libmy_malloc.so
LIB_SRC		=	malloc.c \
				calloc.c

OBJS		=	$(LIB_SRC:.c=.o)

FLAGS	= -W -Wall -Wextra

all:	$(BIN)

$(BIN):
	gcc -fPIC -shared -c $(LIB_SRC) -I./includes
	gcc -shared -o $(LIB_BIN) $(OBJS) -fPIC

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(BIN)
	rm -rf $(LIB_BIN)

re:
	make fclean 
	make clean
	make all

main:
	make re
	gcc -g3 -fPIC -no-pie -Wall -Wextra main.c -o $(BIN) -L./ -lmy_malloc
