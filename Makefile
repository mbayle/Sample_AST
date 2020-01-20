NAME		:=	BTreeTest

CC			:=	gcc -g
LINKER		:=	gcc -o

DEBUG		:=	0

LIBFT		:=	libft/libft.a

INCLUDES	:=	./includes

#libft
INCLUDES	:=	$(INCLUDES) -I$(dir $(LIBFT))includes
LDFLAGS		:=	-L$(dir $(LIBFT)) -lft

CFLAGS		:=	-Wall -Wextra -Werror -g3 -I$(INCLUDES)

ifeq ($(DEBUG), 1)
	CFLAGS	:=	$(CFLAGS) -fsanitize=address
endif

SRC_PATH	:=	./src/
OBJ_PATH	:=	./obj/

SRC		:=	main.c \
			lexer/lexer.c \
			lexer/list_utils.c \
			lexer/utils.c \
			lexer/type_token.c \
			lexer/print_debug.c \
			ast/ast.c \
			ast/process_ast.c \
			ast/print_ast.c \
			ast/ast_utils.c

OBJ		:=	$(addprefix $(OBJ_PATH), $(SRC:.c=.o))
SRC		:=	$(addprefix $(SRC_PATH), $(SRC))

$(NAME):  $(LIBFT) $(OBJ)
	@$(LINKER) $(NAME) $(CFLAGS) $(LDFLAGS) $(OBJ)
	@echo ""
	@echo "\033[0;32m BTreeTest build done \033[0m"
	@echo ""

all: $(NAME)

$(LIBFT):	$(dir $(LIBFT))Makefile
	@make -C $(dir $(LIBFT))

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INCS)
	@echo "\033[0;32m [OK] \033[0m       \033[0;33m [B_TREE] Compiling : \033[0m" $<
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ_PATH)
	@echo "\033[0;32m [OK] \033[0m       \033[0;33m [B_TREE] Deleted all .o\033[0m"

fclean:
	@make -C libft/ fclean
	@rm -f $(NAME)
	@rm -rf $(OBJ_PATH)
	@echo "\033[0;32m [OK] \033[0m       \033[0;33m [B_TREE] Deleted all .o\033[0m"
	@echo "\033[0;32m [OK] \033[0m       \033[0;33m [B_TREE] Deleted BTreeTest\033[0m"

re: fclean all

.PHONY:	all clean fclean re
