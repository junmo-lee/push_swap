.DEFAULT_GOAL := all

NAME	= push_swap
NAME_B	= checker

DEBUG_NAME = debug.out
DEBUG_NAME_B = debug_bonus.out

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
CDEF	= -MMD -MP

LIBFT = ./libft/libft.a
LIBFT_DIR = libft/

INC		= push_swap.h
INC_B	= push_swap_bonus.h

SRCS	= ./gnl/get_next_line.c ./gnl/get_next_line_utils.c \
			lstclear.c push_back.c \
			node_swap.c node_push.c \
			node_rotate.c node_reverse_rotate.c \
			parsing.c ps_atoll.c\
			stack_to_int_array.c 3_sort.c 4_sort.c \
			ps_quick_sort.c split_3.c lis.c \
			greedy_main.c greedy_do_oper.c greedy_utils.c greedy_cal_a_pre_pa.c\
			final_stage.c \
			main.c
		
SRCS_B	= ./gnl/get_next_line_bonus.c ./gnl/get_next_line_utils_bonus.c \
			lstclear_bonus.c push_back_bonus.c \
			node_swap_bonus.c node_push_bonus.c \
			node_rotate_bonus.c node_reverse_rotate_bonus.c \
			parsing_bonus.c ps_atoll_bonus.c \
			input_oper_bonus.c \
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

$(LIBFT) :
	make -C $(LIBFT_DIR) all

%.o : %.c
	$(CC) $(CFLAGS) $(CDEF) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(CC) $(CFLAGS) $(CDEF) $^ -o $(NAME) -I $(INC) -L ./libft -lft

$(NAME_B): $(LIBFT) $(OBJS_B)
	cp $(LIBFT) $(NAME)
	$(CC) $(CFLAGS) $(CDEF) $^ -o $(NAME_B) -I $(INC_B) -L ./libft -lft

$(DEBUG_NAME): $(LIBFT) $(DEBUG_O)
	cp $(LIBFT) $(NAME)
	$(CC) $(CFLAGS) $(CDEF) $^ -o $(DEBUG_NAME) -I $(INC) -L ./libft -lft

$(DEBUG_NAME_B): $(LIBFT) $(DEBUG_B_O)
	cp $(LIBFT) $(NAME)
	$(CC) $(CFLAGS) $(CDEF) $^ -o $(DEBUG_NAME_B) -I $(INC_B) -L ./libft -lft


all : $(NAME)

bonus : $(NAME_B)

debug : $(DEBUG_NAME)
	
debug_bonus : $(DEBUG_NAME_B)

clean :
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(OBJS_B) $(DEF) $(DEF_B)
	rm -f $(DEBUG_O) $(DEBUG_B_O)

fclean :
	make -C $(LIBFT_DIR) fclean
	rm -f $(OBJS) $(OBJS_B) $(DEF) $(DEF_B) $(NAME) $(NAME_B)
	rm -f $(DEBUG_O) $(DEBUG_B_O) $(DEBUG_NAME) $(DEBUG_NAME_B)

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re debug debug_bonus