SRCS	=	./push_swap.c ./srcs/ft_malloc.c ./srcs/ft_sort_2_nbr.c ./srcs/ft_redirect.c ./srcs/ft_print.c ./srcs/ft_lstsize.c ./srcs/ft_lstnew.c ./srcs/ft_lstlast.c ./srcs/ft_lstadd_front.c ./srcs/ft_lstadd_back.c ./srcs/ft_find.c ./srcs/ft_commands_B.c ./srcs/ft_commands_A.c ./srcs/ft_check.c ./srcs/ft_midvalue.c ./srcs/ft_atoi.c ./srcs/ft_reset.c ./srcs/ft_push.c ./srcs/ft_sort_3_nbr_a.c ./srcs/ft_sort_3_nbr_b.c ./srcs/ft_create_chunks.c ./srcs/ft_free.c ./srcs/ft_check_2.c ./srcs/ft_fill_stack_a.c ./srcs/ft_sort_hundred.c ./srcs/ft_sort_hundred_2.c ./srcs/ft_sort_hundred_3.c

INCLUDE	=	./include

CC		=	gcc

NAME	=	push_swap

RM		=	rm -rf

CFLAGS	=	-Werror -Wextra -Wall

OBJS	=	${SRCS:.c=.o}

.c.o:
			${CC} ${CFLAGS} -I ${INCLUDE} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
