# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/12 19:21:21 by mleclair          #+#    #+#              #
#    Updated: 2016/11/24 13:27:41 by mleclair         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILE =	ft_atoi \
		ft_bzero \
		ft_isalnum \
		ft_isalpha \
		ft_isascii \
		ft_isdigit \
		ft_isprint \
		ft_itoa \
		ft_lstadd \
		ft_lstdel \
		ft_lstdelone \
		ft_lstiter \
		ft_lstmap \
		ft_lstnew \
		ft_memalloc \
		ft_memccpy \
		ft_memchr \
		ft_memcmp \
		ft_memcpy \
		ft_memdel \
		ft_memmove \
		ft_memset \
		ft_putchar \
		ft_putchar_fd \
		ft_putendl \
		ft_putendl_fd \
		ft_putnbr \
		ft_putnbr_fd \
		ft_putstr \
		ft_putstr_fd \
		ft_strcat \
		ft_strchr \
		ft_strclr \
		ft_strcmp \
		ft_strcpy \
		ft_strdel \
		ft_strdup \
		ft_strequ \
		ft_striter \
		ft_striteri \
		ft_strjoin \
		ft_strlcat \
		ft_strlen \
		ft_strmap \
		ft_strmapi \
		ft_strncat \
		ft_strncmp \
		ft_strncpy \
		ft_strnequ \
		ft_strnew \
		ft_strnstr \
		ft_strrchr \
		ft_strsplit \
		ft_strstr \
		ft_strsub \
		ft_strtrim \
		ft_tolower \
		ft_toupper

OBJ  := $(addsuffix .o, $(FILE))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "----------------------------------------"
	@echo "|       Debut de la compilation        |"
	@echo "|              Ecole 42                |"
	@ar rc $(NAME) $(OBJ)
	@echo "|                 FIN                  |"
	@echo "----------------------------------------"
	@echo "               ________"
	@echo "          _,.-Y  |  |  Y-._"
	@echo "      .-~\"   ||  |  |  |   \"-."
	@echo "      I\" \"\"==\"|\" !\"\"! \"|\"[]\"\"|     _____"
	@echo "      L__  [] |..------|:   _[----I\" .-{\"-."
	@echo "     I___|  ..| l______|l_ [__L]_[I_/r(=}=-P"
	@echo "    [L______L_[________]______j~  '-=c_]/=-^"
	@echo "     \_I_j.--.\==I|I==_/.--L_]"
	@echo "       [_((==)[\`-----\"](==)j"
	@echo "          I--I\"~~\"\"\"~~\"I--I"
	@echo "          |[]|         |[]|"
	@echo "          l__j         l__j"
	@echo "          |!!|         |!!|"
	@echo "          |..|         |..|"
	@echo "          ([])         ([])"
	@echo "          ]--[         ]--["
	@echo "          [_L]         [_L]"
	@echo "         /|..|\       /|..|\\"
	@echo "        \`=}--{='     \`=}--{=i'"
	@echo "       .-^--r-^-.   .-^--r-^-."
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"

$(OBJ): %.o: %.c
	@gcc -c -g -Wall -Wextra -Werror -I. $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re
