#-------------------------NAME--------------------------/
NAME =		so_long
#------------------------SOURCES------------------------/
INCLUDES =	./

VPATH =		files \
			get_next_line \
			includes \
			libft \
			mlx \
			objects

HEADERS =	so_long.h \
			textures.h \
			get_next_line.h \
			libft.h

LIBRARYS =	mlx/libmlx.a \
			libft/libft.a

#----------FILES
FILES =		main.c \
			game.c \
			get_map.c \
			get_next_line.c \
			get_next_line_utils.c \
			get_frame_and_set_size.c \
			render.c

O_FILES = 	$(addprefix objects/, $(FILES:.c=.o))

#-----ADDITIONAL
#CFLAGS =	-Wall -Wextra -Werror -O3
G =			\033[38;2;154;205;50
W =			\033[38;2;255;255;255


#--------------------RULES-------------------------------/
.PHONY =	all	clean fclean re


all:		$(NAME)

$(NAME):	objects libs $(O_FILES)
			@$(CC) -O3 $(O_FILES) $(LIBRARYS) -framework OpenGL -framework AppKit -o $(NAME)
			@printf %s ./$(NAME) | pbcopy

objects :
			@mkdir $@

libs :
			make -C mlx/
			make -C libft/

objects/%.o :	%.c $(HEADERS)
			    gcc $(FLAGS) -I $(INCLUDES) -c $< -o $@


#-------CLEAN
clean:
			@rm -rf objects/
			@make clean -C mlx/
			@make clean -C libft/

fclean:		clean
			@rm -f $(NAME)
			@make fclean -C libft/

re:			fclean all

