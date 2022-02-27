NAME := libgnl.a

SOURCE_FILES := get_next_line.c get_next_line_utils.c

HEADER := get_next_line.h

FLAGS := -Wall -Werror -Wextra

all: ${NAME}

${NAME}: ${HEADER} ${SOURCE_FILES}
	gcc -c $(FLAGS) $(SOURCE_FILES)
	ar -r $(NAME) *.o $(HEADER)
	ranlib $(NAME)

clean:
	rm -f *.o
fclean:
	rm -f *.o $(NAME)
re: fclean all
.PHONY: all clean fclean re
