# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/12 19:21:21 by mleclair          #+#    #+#              #
#    Updated: 2016/11/29 13:00:20 by mleclair         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

PATH = ./libft/

FILE =	$(PATH)ft_atoi \
		$(PATH)ft_bzero \
		$(PATH)ft_isalnum \
		$(PATH)ft_isalpha \
		$(PATH)ft_isascii \
		$(PATH)ft_isdigit \
		$(PATH)ft_isprint \
		$(PATH)ft_itoa \
		$(PATH)ft_lstadd \
		$(PATH)ft_lstdel \
		$(PATH)ft_lstdelone \
		$(PATH)ft_lstiter \
		$(PATH)ft_lstmap \
		$(PATH)ft_lstnew \
		$(PATH)ft_memalloc \
		$(PATH)ft_memccpy \
		$(PATH)ft_memchr \
		$(PATH)ft_memcmp \
		$(PATH)ft_memcpy \
		$(PATH)ft_memdel \
		$(PATH)ft_memmove \
		$(PATH)ft_memset \
		$(PATH)ft_putchar \
		$(PATH)ft_putchar_fd \
		$(PATH)ft_putendl \
		$(PATH)ft_putendl_fd \
		$(PATH)ft_putnbr \
		$(PATH)ft_putnbr_fd \
		$(PATH)ft_putstr \
		$(PATH)ft_putstr_fd \
		$(PATH)ft_strcat \
		$(PATH)ft_strchr \
		$(PATH)ft_strclr \
		$(PATH)ft_strcmp \
		$(PATH)ft_strcpy \
		$(PATH)ft_strdel \
		$(PATH)ft_strdup \
		$(PATH)ft_strequ \
		$(PATH)ft_striter \
		$(PATH)ft_striteri \
		$(PATH)ft_strjoin \
		$(PATH)ft_strlcat \
		$(PATH)ft_strlen \
		$(PATH)ft_strmap \
		$(PATH)ft_strmapi \
		$(PATH)ft_strncat \
		$(PATH)ft_strncmp \
		$(PATH)ft_strncpy \
		$(PATH)ft_strnequ \
		$(PATH)ft_strnew \
		$(PATH)ft_strnstr \
		$(PATH)ft_strrchr \
		$(PATH)ft_strsplit \
		$(PATH)ft_strstr \
		$(PATH)ft_strsub \
		$(PATH)ft_strtrim \
		$(PATH)ft_tolower \
		$(PATH)ft_toupper \
		$(PATH)ft_itoa_base \
		addprint \
		diese \
		ft_atoi_base \
		ft_isokay \
		ft_opts \
		part1 \
		part2 \
		printf \
		tableaupointeursurfonction \
		tobecontinued

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
	@gcc -c -Wall -Wextra -Werror $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re
