NAME = libftprintf.a

BUILD_DIR = build/

VPATH = util/

TEST = tester

TEST_SRC = main.c

SRC = ft_printf.c \
ft_pt_chr.c \
ft_pt_dec.c \
ft_pt_udec.c \
ft_pt_ptr.c \
ft_pt_str.c \
ft_pt_lo_hex.c \
ft_pt_up_hex.c \
ft_numdig_sign.c \
ft_numdig_usign.c \
ft_numdig_ptr.c

FLAGS = -Wall -Wextra -Werror

OBJ = $(addprefix $(BUILD_DIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) -ru $(NAME) $(OBJ)

$(BUILD_DIR)%.o: %.c | $(BUILD_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir $@

test: $(TEST)

$(TEST): $(NAME) $(TEST_SRC)
	$(CC) $(FLAGS) $(TEST_SRC) $(NAME) -o $(TEST)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(TEST)

re: fclean all

.PHONY:
	all clean fclean re test