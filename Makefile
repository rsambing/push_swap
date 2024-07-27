CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f 
EXEC = ./
PROGRAM = push_swap 
VERDE = \033[1;32m
VERMELHO = \033[1;31m
AZUL = \033[1;36m
RESTAURA = \033[0m
LIMPAR = clear

all:
	@ make -s -C libft
	@ ${CC} ${CFLAGS} *.c verify/*.c pilha/*.c libft/libft.a -o ${PROGRAM}
	@ echo "${VERDE}Compilado com sucesso!${RESTAURA}"
	@ clear
	@ echo "${AZUL}push_swap${RESTAURA}"
run:
	@ ./${PROGRAM}  

bonus:
	
run_bonus:	

clean:
	@ rm -f *.o
	@ make clean -s -C libft

fclean: clean
	@ ${RM} ${PROGRAM}
	@ make fclean -s -C libft
	@ echo "${VERMELHO}Apagado com sucesso${RESTAURA}"
	@ clear

re: fclean all

	

.PHONY: all clean fclean re bonus
