# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 19:26:53 by ldoctori          #+#    #+#              #
#    Updated: 2021/10/30 16:39:45 by ldoctori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
SOURCE_FILES := ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isspace.c \
			ft_bzero.c 	ft_isascii.c ft_isprint.c ft_memcpy.c \
			ft_memmove.c ft_memset.c ft_strlcat.c ft_strlcpy.c \
			ft_strlen.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
			ft_strnstr.c ft_atoi.c ft_strdup.c ft_calloc.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
			ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_putnstr_fd.c ft_itoa_unsigned.c ft_itoa_hex.c \
			ft_strndup.c ft_sqrt.c

BONUS_FILES := ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c	ft_lstmap.c

HEADER := libft.h

FLAGS := -Wall -Wextra -Werror 

all: ${NAME}

$(NAME): ${HEADER} ${SOURCE_FILES}
	gcc -c $(FLAGS) $(SOURCE_FILES)
	ar r $(NAME) *.o
	ranlib $(NAME)

bonus: ${HEADER}
	gcc -c $(FLAGS) $(SOURCE_FILES) $(BONUS_FILES)
	ar r $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o
fclean:
	rm -f $(NAME) *.o
re: fclean all
.PHONY: all clean fclean re bonus
