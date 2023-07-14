NAME = libasm.a
NAME_TEST = asm_tester
NAME_TEST_BONUS = Test_Bonus

SRCS_TEST = test/main.c \
			test/test_strlen.c \
			test/test_strcmp.c \
			test/test_strcpy.c \
			test/test_write.c \
			test/test_read.c \

SRCS = ft_strlen.s \
		ft_strcmp.s \
		ft_strcpy.s \
		ft_write.s \
		ft_read.s \
		#ft_strdup.s
SRCS_DIR = src

OBJS = $(SRCS:.s=.o)
OBJS_TEST = $(SRCS_TEST:.c=.o)
OBJS_DIR = obj

DIRS = obj obj/test

_SRCS_TEST = $(addprefix $(SRCS_DIR)/, $(SRCS_TEST))
_SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS))
_OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS))
_OBJS_TEST = $(addprefix $(OBJS_DIR)/, $(OBJS_TEST))

HEADERS = inc

LIBFT = libft.a
LIBFT_DIR = libft

MAKE = make --no-print-directory
CC = gcc
DEBUG_CFLAGS = -g -fsanitize=address

NA			=	nasm
NA_FLAGS	=

UNAME = $(shell uname -s)

# Color
_COLOR		= \033[32m
_BOLDCOLOR	= \033[32;1m
_RESET		= \033[0m
_CLEAR		= \033[0K\r\c
_OK			= [\033[32mOK\033[0m]
_RM			= [\033[31mRM\033[0m]

ifeq ($(UNAME), Linux)
    CFLAGS = -I $(HEADERS) -I $(LIBFT_DIR)/inc -Wall -Wextra -Werror 
	NA_FLAGS = -felf64
    LFLAGS = $(CFLAGS) -L. -L $(LIBFT_DIR) -lasm -lft
    DEBUG_LFLAGS = -static-libasan -g
endif
ifeq ($(UNAME), Darwin)
	CFLAGS = -I $(HEADERS) -I $(LIBFT_DIR)/inc -Wall -Wextra -Werror
	NA_FLAGS = -f macho64
	LFLAGS = $(CFLAGS) -L. -lasm
	DEBUG_LFLAGS = ""
endif


all: $(NAME)

fast: CFLAGS += -Ofast
fast: $(NAME)

debug: LFLAGS += $(DEBUG_LFLAGS)
debug: CFLAGS += $(DEBUG_CFLAGS)
debug: verbose

$(NAME): $(_OBJS)
	@ar rcs $(NAME) $(_OBJS)
	@echo "$(_OK) $(NAME) \t\tcompiled"

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.s
	@echo "[..] $(NAME)... compiling $*.c\r\c"
	@mkdir -p $(DIRS)
	@$(NA) $(NA_FLAGS) $< -o $@
	@echo "$(_CLEAR)"

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
	@echo "[..] $(NAME_TEST)... compiling $*.c\r\c"
	@mkdir -p $(DIRS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(_CLEAR)"

$(LIBFT_DIR)/$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all
	@$(MAKE) -C $(LIBFT_DIR) bonus

test: $(_OBJS_TEST) $(LIBFT_DIR)/$(LIBFT)	$(NAME)
	@mkdir -p $(DIRS)
	@gcc $(LFLAGS) -o $(NAME_TEST) $(_OBJS_TEST) -lasm -lft
	@echo "$(_OK) $(NAME_TEST) \t\tcompiled"
	@./$(NAME_TEST)

verbose: $(_OBJS_TEST) $(LIBFT_DIR)/$(LIBFT) $(NAME)
	@gcc $(LFLAGS) -o $(NAME_TEST) $(_OBJS_TEST) -lasm -lft
	@echo "$(_OK) $(NAME_TEST) \t\tcompiled"
	@./$(NAME_TEST) 1

bonus:			$(OBJS) $(BONUS_OBJS)
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
	@echo "[..] $(NAME)... removing $*.c\r\c"
	@rm -rf $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(_CLEAR)"

fclean:
	@rm -rf $(OBJS_DIR) $(NAME) $(NAME_TEST) $(NAME_TEST_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(_RM) $(NAME) \t\tfull clean"

re: fclean all

.PHONY : all fast debug clean test fclean re