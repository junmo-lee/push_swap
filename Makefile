.DEFAULT_GOAL := all

NAME	= push_swap
NAME_B	= checker

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
CDEF	= -MMD -MP

LIBFT = ./libft/libft.a
LIBFT_DIR = libft/

INC		= push_swap.h
INC_B	= push_swap_bonus.h

SRCS	= ./gnl/get_next_line.c ./gnl/get_next_line_utils.c \
			main.c 
		
SRCS_B	= ./gnl_bonus/get_next_line_bonus.c ./gnl_bonus/get_next_line_utils_bonus.c \
			./node/lstclear_bonus.c ./node/push_back_bonus.c \
			./parsing/parsing_bonus.c ./parsing/ps_atoll_bonus.c \
			./node/node_swap_bonus.c ./node/node_push_bonus.c \
			./node/node_rotate_bonus.c ./node/node_reverse_rotate_bonus.c \
			main_bonus.c

OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)

DEBUG_O = $(filter-out main.o, $(OBJS)) debug.o
DEBUG_B_O = $(filter-out main_bonus.o, $(OBJS_B)) debug_bonus.o

DEF		= $(SRCS:.c=.d) 
DEF_B	= $(SRCS_B:.c=.d)
-include $(DEP) $(DEF_B)

ifdef IGNORE_ERROR
    CFLAGS :=  # IGNORE_ERROR가 설정되었을 때, CFLAGS를 빈 값으로 덮어쓰기, 해당 명령에서만 사용됨
endif

ifdef DEBUG_FLAG
	CFLAGS += -g3 -fsanitize=address
endif

all: $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(CC) $(CFLAGS) $(CDEF) $^ -o $(NAME) -I $(INC)

bonus: $(LIBFT) $(OBJS_B)
	cp $(LIBFT) $(NAME)
	$(CC) $(CFLAGS) $(CDEF) $^ -o $(NAME_B) -I $(INC_B)

clean :
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(OBJS_B) $(DEF) $(DEF_B)

fclean :
	make -C $(LIBFT_DIR) fclean
	rm -f $(OBJS) $(OBJS_B) $(DEF) $(DEF_B) $(NAME) $(NAME_B)
	find . -type f -name 'debug*' ! -name 'debug.c' ! -name 'debug_bonus.c' -exec rm {} +

re :
	make fclean
	make all


debug : $(DEBUG_O)
	$(CC) $(CFLAGS) $^ -o debug.out -I $(INC)
	
debug_bonus : $(DEBUG_B_O)
	$(CC) $(CFLAGS) $^ -o debug_bonus.out -I $(INC_B)

$(LIBFT) :
	make -C $(LIBFT_DIR) all

$(NAME) :
	make all

$(NAME_B) :
	make bonus

%.o : %.c
	$(CC) $(CFLAGS) $(CDEF) -c $< -o $@

.PHONY : all bonus clean fclean re