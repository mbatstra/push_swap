NAME = push_swap
TEST_NAME = test/unit_test

SRC_DIR = src/
BUILD_DIR = build/

UNPREFIXED_SRC = main.c \
swap.c \
rotate.c \
push.c \
mergesort.c

TEST_SRC = test/test.c

OBJ = $(addprefix $(BUILD_DIR), $(UNPREFIXED_SRC:.c=.o))
SRC = $(addprefix $(SRC_DIR), $(UNPREFIXED_SRC))

INC = inc/
TEST_INC = test/criterion--git/include

FLAGS = -Wall -Wextra -Werror

LIB = lib/
LIBFT = lib/libft/libft.a
FT_PRINTF = lib/ft_printf/libftprintf.a
CRITERION = test/criterion--git/libcriterion.dylib

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIB)libft

$(FT_PRINTF):
	$(MAKE) -C $(LIB)ft_printf

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT) $(FT_PRINTF) -I$(INC) -o $(NAME)

$(BUILD_DIR)%.o: $(SRC_DIR)%.c | $(BUILD_DIR)
	$(CC) $(FLAGS) -I$(INC) -c $< -o $@

unit_test: $(LIBFT) $(FT_PRINTF) $(TEST_SRC) $(filter-out main.c, $(SRC))
	$(CC) $(TEST_SRC) $(LIBFT) $(FT_PRINTF) $(filter-out src/main.c, $(SRC)) $(CRITERION) -o $(TEST_NAME) -I$(INC) -I$(TEST_INC)

$(BUILD_DIR):
	mkdir $@

clean:
	rm -f $(OBJ)
	rm -f $(LIB)libft/*.o
	rm -f $(LIB)ft_printf/build/*

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f $(FT_PRINTF)

re: fclean all

.PHONY:
	all clean fclean re unit_test
