CC = gcc

NAME = so_long

FLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/

GNL = ./get_next_line/

SOURCE = so_long.c render_next_frame.c render_static.c \
		render_dynamic.c ft_read_map.c player_move.c \
		min_movements.c wave_algorithm.c action.c \
		close_functions.c

OBJ = $(SOURCE:.c=.o)

%.o: %.c
	$(CC) -I./include -I./get_next_line -I./libft -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(GNL)
	$(CC) $(FLAGS) $(OBJ) -lmlx -Lget_next_line -lgnl -Llibft -lft -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f *.o

fclean: rmLIBFT rmGNL
	rm -f *.o $(NAME)

rmLIBFT: 
	rm -f $(LIBFT)*.a $(LIBFT)*.o

rmGNL: 
	rm -f $(GNL)*.a $(GNL)*.o

re: fclean all
