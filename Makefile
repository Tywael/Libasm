NAME = Libasm
NAME_TEST = Test
NAME_TEST_BONUS = Test_Bonus

SRCS = 
SRCS_DIR = src

OBJS = $(SRCS:.c=.o)
OBJS_DIR = obj

DIRS = obj

_SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS))
_OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS))

HEADERS = includes

MAKE = make --no-print-directory
CC = gcc
DEBUG_CFLAGS = -g -fsanitize=address

NA			=	nasm
NA_FLAGS	=	-f macho64

UNAME = $(shell uname -s)

# Color
_COLOR		= \033[32m
_BOLDCOLOR	= \033[32;1m
_RESET		= \033[0m
_CLEAR		= \033[0K\r\c
_OK			= [\033[32mOK\033[0m]
_RM			= [\033[31mRM\033[0m]

ifeq ($(UNAME), Linux)
    CFLAGS = -I $(HEADERS) -Wall -Wextra -Werror 
    LFLAGS = $(CFLAGS)
    DEBUG_LFLAGS = -static-libasan
endif
ifeq ($(UNAME), Darwin)
	CFLAGS = -I $(HEADERS) -Wall -Wextra -Werror
	LFLAGS = $(CFLAGS)
	DEBUG_LFLAGS = ""
endif


all: $(NAME)

fast: CFLAGS += -Ofast
fast: $(NAME)

debug: LFLAGS += $(DEBUG_LFLAGS)
debug: CFLAGS += $(DEBUG_CFLAGS)
debug: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	@echo "$(_OK) $(NAME) \t\tcompiled"

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
	@echo "[..] $(NAME)... compiling $*.c\r\c"
	@mkdir -p $(DIRS)
	$(NA) $(NA_FLAGS) $<
	@echo "$(_CLEAR)"

test:	$(NAME)
	gcc $(FLAGS) -L. -lasm -o $(TEST) main.c
	./$(TEST) < Makefile

bonus:			$(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

test_bonus:		bonus
	gcc $(FLAGS) -L. -lasm -o $(TEST_BONUS) main_bonus.c
	./$(TEST_BONUS)

clean:
	@echo "[..] $(NAME)... removing $*.c\r\c"
	@rm -rf $(OBJS_DIR)
	@echo "$(_CLEAR)"

fclean:
	@rm -rf $(OBJS_DIR) $(NAME) $(NAME_TEST) $(NAME_TEST_BONUS)
	@echo "$(_RM) $(NAME) \t\tfull clean"

re: fclean all

.PHONY : all fast debug clean fclean re