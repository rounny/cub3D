NAME	=	cub3D

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
LDFLAGS	=	-L$(LIBFT_DIR)
RM		=	rm -rf

LIBFT_DIR	= ./libft/
LIBFT		= $(addprefix $(LIBFT_DIR), libft.a)

HEAD	=	cub.h
SRCS	=	main.c utils.c parse_map.c 

OBJS	=	$(SRCS:%.c=%.o)

.PHONY	:	all clean fclean re bonus

all		:	$(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME) :	$(OBJS) $(HEAD)
			$(CC) $(CFLAGS) $(LDFLAGS) $(LIBFT) $(OBJS) -o $(NAME)

%.o		:	%.c $(HEAD)
			$(CC) $(CFLAGS) -c $< -o $@
clean	:
			$(RM) $(OBJS)
			make clean -C ./libft

fclean	:	clean
			$(RM) $(NAME)
			$(RM) $(LIBFT)

re : fclean all