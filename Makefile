NAME 			= push_swap

CC	 			= cc

FLAGS 			= -Wall -Wextra -Werror

RM				= rm -rf

HEADER			= push_swap.h


# MAIN
DIR_MAIN	 	= ./
SRC_MAIN	 	= push_swap.c
PATH_MAIN		= $(addprefix $(DIR_MAIN), $(SRC_MAIN))
OBJ_MAIN		= $(PATH_MAIN:.c=.o)

# BONUS
DIR_BONUS 		= bonus/
SRC_BONUS	 	= checker.c exec_checker.c helper_checker.c
PATH_BONUS		= $(addprefix $(DIR_BONUS), $(SRC_BONUS))
OBJ_BONUS		= $(PATH_BONUS:.c=.o)

# UTILS
DIR_UTILS		= utils/
SRCS_UTILS		= utils_1.c utils_2.c utils_3.c init_nodes.c execute_inst.c algos.c
PATH_UTILS		= $(addprefix $(DIR_UTILS), $(SRCS_UTILS))
OBJ_UTILS		= $(PATH_UTILS:.c=.o)

# PRINTF
DIR_UTILS_FT_PRINTF		= utils/ft_printf/
SRCS_UTILS_FT_PRINTF	= ft_printf.c ft_putaddress.c ft_putchar.c ft_puthexa.c ft_putnbr.c ft_putstr.c ft_putunsigned.c ft_strchr.c
PATH_UTILS_FT_PRINTF	= $(addprefix $(DIR_UTILS_FT_PRINTF), $(SRCS_UTILS_FT_PRINTF))
OBJ_UTILS_FT_PRINTF		= $(PATH_UTILS_FT_PRINTF:.c=.o)

# COMMANDS
%.o: %.c 	$(HEADER) Makefile
							@${CC} ${FLAGS} -c $< -o $@

$(NAME):	$(OBJ_UTILS) $(OBJ_UTILS_FT_PRINTF) $(OBJ_MAIN)
							@$(CC) $(OBJ_UTILS) $(OBJ_UTILS_FT_PRINTF) $(OBJ_MAIN) -o $(NAME)

all:		$(NAME)

bonus:		$(OBJ_UTILS) $(OBJ_UTILS_FT_PRINTF) $(OBJ_BONUS)
							@$(CC) $(OBJ_UTILS) $(OBJ_UTILS_FT_PRINTF) $(OBJ_BONUS) -o $(NAME)

clean:						
							@$(RM)	$(OBJ_MANDATORY)
							@$(RM)	$(OBJ_UTILS)
							@$(RM)	$(OBJ_UTILS_FT_PRINTF)
							@$(RM)	$(OBJ_BONUS)

fclean:		clean
							@$(RM) $(NAME)

re:							fclean all

.PHONY: 	all clean fclean bonus re
