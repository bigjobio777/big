# **************************************************************************** #
#																			  #
#														 :::	  ::::::::	#
#	Makefile										   :+:	  :+:	:+:	#
#													 +:+ +:+		 +:+	  #
#	By: bigjobio <bigjobio@student.42.fr>		  +#+  +:+	   +#+		 #
#												 +#+#+#+#+#+   +#+			#
#	Created: 2020/11/21 18:28:23 by tfines			#+#	#+#			  #
#	Updated: 2021/03/29 18:29:19 by bigjobio		 ###   ########.fr		#
#																			  #
# **************************************************************************** #

NAME = libft.a
OBJS_D := objs/
HEAD := -I .
#HEAD := -I includes/

CFLAGS = -MMD -Wall -Wextra -Werror -g # -fsanitize=address

SRC := \
		ft_memset.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memcmp.c \
		ft_calloc.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_strrchr.c \
		ft_strlcat.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_putendl_fd.c \
		ft_putchar_fd.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_strncat.c \
		ft_itoa.c \
		ft_lenint.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strmapi.c \
		ft_strtrim.c \
		ft_strchr.c \
		ft_split.c \
		ft_memchr.c \
		ft_memmove.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strdup.c \
		ft_strcmp.c \
		ft_strjoinchr.c \

OBJS := $(SRC:.c=.o)
D := $(SRC:.c=.d)



all: $(NAME)

$(NAME) : $(OBJS)
			ar rcs $(NAME) $(OBJS)

%.o: %.c
		gcc $(CFLAGS) $(HEAD) -c $< -o $@

clean:
		rm -rf $(OBJS)
		rm -rf $(D)

fclean:
		rm -rf $(NAME) $(OBJS)

re: fclean all

-include $(D)