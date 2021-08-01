SRCS	=	push_swap_main.c push_swap_linked_list.c push_swap_llist_utils.c push_swap_sort_low.c push_swap_sort_high.c
OBJS	=	$(SRCS:c=o)
NAME	=	libpushswap.a
CC		=	gcc
RM		= 	rm -f
FLAGS	=	-Wall -Werror -Wall

all:	$(NAME) run

%o: %c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

run:
	$(CC) $(FLAGS) $(SRCS) -L. -lpushswap -I push_swap.h -o push_swap

clean:
	$(RM) $(OBJS) ./push_swap

fclean: clean
	$(RM) $(NAME)

re:	fclean all
