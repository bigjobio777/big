NAME := cub3D
SRC := main.c errors.c init_flags.c gnl.c all_for_parse/parse_for_map.c all_for_parse/parse_F_C.c all_for_parse/parse_1.c gnl/get_next_line.c gnl/get_next_line_utils.c all_for_parse/small_fun_parse.c image.c cast_rays.c angle_maker.c all_for_parse/make_karta.c sprites.c all_for_parse/make_karta2.c cast_rays2.c cast_rays3.c draw_main.c errors2.c all_for_parse/ceiling_floor.c
OBJS := $(SRC:.c=.o)
CC := clang
D := $(SRC:.c=.d)
CFLAGS ?= -MMD -Imlx -ILibft -g -fsanitize=address -Wall -Wextra -Werror

all: Makelib cub3D

Makelib: 
	make -C Libft
	make -C mlx
	cp mlx/libmlx.dylib libmlx.dylib 
cub3D: $(OBJS) mlx/libmlx.dylib
	$(CC) -g -framework OpenGL -Lmlx -lmlx -framework AppKit $(CFLAGS) $(OBJS) -LLibft -lft -o $(NAME)

debug:
	make all CFLAGS+="$(CFLAGS) -g"
clean : 
	make clean -C Libft
	rm -rf $(D)
	rm -f *.o
	rm -f gnl/*.o
	rm -f all_for_parse/*.o
	rm -f libmlx.dylib

fclean : clean
	make fclean -C Libft
	rm -f $(NAME)

re : fclean
	make re -C Libft
	make all

-include $(D)
