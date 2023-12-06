.DEFAULT_GOAL := all

NAME	= push_swap
BONUS_NAME = checker

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
CDEF	= -MMD -MP

LIBFT = ./libft/libft.a
LIBFT_DIR = libft/

INC		= push_swap.h

SRCS	=
SRCS_B	= 

OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)

DEF		= $(SRCS:.c=.d) $(SRCS_B:.c=.d)
-include $(DEP)

all: $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(CC) $(CFLAGS) $(CDEF) $< -o $(NAME) -I $(INC)

bonus: $(LIBFT) $(OBJS) $(OBJS_B)
	cp $(LIBFT) $(NAME)
	$(CC) $(CFLAGS) $(CDEF) $< -o $(BONUS_NAME) -I $(INC)

clean :
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(OBJS_B) $(DEF)

fclean :
	make -C $(LIBFT_DIR) fclean
	rm -f $(OBJS) $(OBJS_B) $(DEF) $(NAME) $(BONUS_NAME)

re :
	make fclean
	make all

$(LIBFT) :
	make -C $(LIBFT_DIR) all

$(NAME) :
	make all

%.o : %.c
	$(CC) $(CFLAGS) $(CDEF) -c $< -o $@ -I $(INC)

.PHONY : all bonus clean fclean re