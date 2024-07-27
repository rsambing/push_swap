CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f 
EXEC = ./
NAME = push_swap 
VERDE = \033[1;32m
VERMELHO = \033[1;31m
AZUL = \033[1;36m
RESTAURA = \033[0m
LIMPAR = clear

all: ${NAME}

${NAME}:
	@ make -s -C libft
	@ ${CC} ${CFLAGS} *.c verify/*.c utils/*.c pilha/*.c libft/libft.a -o ${NAME}
	@ echo "${VERDE}Compilado com sucesso!${RESTAURA}"
	@ clear
	@ echo "${AZUL}push_swap${RESTAURA}"
run:
	@ ./${NAME}  

bonus:
	
run_bonus:	

clean:
	@ rm -f *.o
	@ make clean -s -C libft

fclean: clean
	@ ${RM} ${NAME}
	@ make fclean -s -C libft
	@ echo "${VERMELHO}Apagado com sucesso${RESTAURA}"
	@ clear

re: fclean all

.PHONY: all clean fclean re bonus
