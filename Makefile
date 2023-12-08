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
			main_bonus.c parsing_bonus.c parsing_utils_bonus.c

OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)

DEF		= $(SRCS:.c=.d) 
DEF_B	= $(SRCS_B:.c=.d)
-include $(DEP) $(DEF_B)

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

re :
	make fclean
	make all

$(LIBFT) :
	make -C $(LIBFT_DIR) all

$(NAME) :
	make all

%.o : %.c
	$(CC) $(CFLAGS) $(CDEF) -c $< -o $@

.PHONY : all bonus clean fclean re