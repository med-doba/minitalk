NAME = server

CC= cc

CFLAGS= -Wall -Wextra -Werror

SRC = server.c client.c

SRC_BONUS = client_bonus.c server_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

INC = minitalk.h

INC_BONUS = minitalk_bonus.h

LIB = libft/libft.a

PRINT = printf/libftprintf.a


$(NAME) : $(LIB) $(PRINT) $(OBJ) $(INC)
	@$(CC) $(CFLAGS) $(LIB) $(PRINT) server.c -o server
	@$(CC) $(CFLAGS) $(LIB) $(PRINT) client.c -o client

$(LIB) :
	@make -C libft

$(PRINT) :
	@make -C printf

all: $(NAME)

bonus: $(LIB) $(PRINT) $(OBJ_BONUS) $(INC_BONUS)
	@$(CC) $(CFLAGS) $(LIB) $(PRINT) server_bonus.c -o server_bonus
	@$(CC) $(CFLAGS) $(LIB) $(PRINT) client_bonus.c -o client_bonus

clean: 
	@rm -rf server.o client.o client_bonus.o server_bonus.o
	@make clean -C libft
	@make clean -C printf

fclean: clean
	@rm -rf server client server_bonus client_bonus
	@make fclean -C libft
	@make fclean -C printf

re: fclean all