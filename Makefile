NAME		=	cub3D

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra #-fsanitize=address
LDFLAGS		=	-L$(LIBFT_DIR) -L$(LIBFT_DIR) -framework OpenGL -framework Appkit
RM			=	rm -rf

LIBFT_DIR	= ./libft/
LIBMLX_DIR		= ./mlx/
LIBFT		= $(addprefix $(LIBFT_DIR), libft.a)
LIBMLX		= $(addprefix $(LIBMLX_DIR), libmlx.a)

HEAD		=	cub.h draw/draw.h
SRCS		=	main.c utils.c split_cub.c parser/parse_main.c  \
				parser/directions.c parser/floor_ceiling.c \
				parser/map.c parser/map_features.c \
				draw/draw.c
			

OBJS		=	$(SRCS:%.c=%.o)

.PHONY		:	all clean fclean re bonus

all			:	libmlx libmake $(NAME)

libmlx:
	@make -C $(LIBMLX_DIR)

libmake:
	@make -C $(LIBFT_DIR)

$(NAME) 	:	$(OBJS) $(HEAD)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIBFT) $(LIBMLX) $(OBJS) -o $(NAME)
	@echo ""
	@echo "\x1b[1;35m \x1b[1;35m ☆* Makefile is done SUCCESSFULLY! *☆\033[0m"
	@echo ""

%.o			:	%.c $(HEAD)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
clean		:
	$(RM) $(OBJS)
	make clean -C ./libft
	make clean -C ./mlx

fclean		:	clean
	$(RM) $(NAME)
	$(RM) $(LIBFT) $(LIBMLX)

re : fclean all