# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slatrech <slatrech@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 11:03:51 by slatrech          #+#    #+#              #
#    Updated: 2025/05/01 13:58:29 by slatrech         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de l'exécutable
NAME = so_long

# Répertoires
SRCS_DIR = src
GNL_DIR = get_next_line
FT_PRINTF_DIR = $(SRCS_DIR)/ft_printf
OBJS_DIR = obj
GNL_OBJS_DIR = $(OBJS_DIR)/gnl
PRINTF_OBJS_DIR = $(OBJS_DIR)/ft_printf
MLX_DIR = minilibx-linux

# Fichiers source explicites
SRCS = $(SRCS_DIR)/main.c $(SRCS_DIR)/utils.c $(SRCS_DIR)/map.c $(SRCS_DIR)/game.c $(SRCS_DIR)/draw.c $(SRCS_DIR)/exit.c $(SRCS_DIR)/flood_fill.c $(SRCS_DIR)/is_map_valid.c $(SRCS_DIR)/utils2.c $(SRCS_DIR)/game2.c $(SRCS_DIR)/flood_fill2.c $(SRCS_DIR)/game3.c
GNL_SRCS = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
PRINTF_SRCS = $(FT_PRINTF_DIR)/ft_printf.c $(FT_PRINTF_DIR)/functions.c

# Fichiers objets explicites (pas de substitution)
OBJS = $(OBJS_DIR)/main.o $(OBJS_DIR)/utils.o $(OBJS_DIR)/map.o $(OBJS_DIR)/game.o $(OBJS_DIR)/draw.o $(OBJS_DIR)/exit.o $(OBJS_DIR)/flood_fill.o $(OBJS_DIR)/is_map_valid.o $(OBJS_DIR)/utils2.o $(OBJS_DIR)/game2.o $(OBJS_DIR)/flood_fill2.o $(OBJS_DIR)/game3.o
GNL_OBJS = $(GNL_OBJS_DIR)/get_next_line.o $(GNL_OBJS_DIR)/get_next_line_utils.o
PRINTF_OBJS = $(PRINTF_OBJS_DIR)/ft_printf.o $(PRINTF_OBJS_DIR)/functions.o
ALL_OBJS = $(OBJS) $(GNL_OBJS) $(PRINTF_OBJS)

# Compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

# Flags pour MiniLibX
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz
MLX_INC = -I$(MLX_DIR)

# Compilation avec les headers
INCLUDES = -I. -I$(GNL_DIR) -I$(FT_PRINTF_DIR)

# Règles de construction
.PHONY: all clean fclean re dirs mlx

# Création de l'exécutable
all: dirs mlx $(NAME)

# Création des dossiers nécessaires
dirs:
	mkdir -p $(OBJS_DIR)
	mkdir -p $(GNL_OBJS_DIR)
	mkdir -p $(PRINTF_OBJS_DIR)

# Compilation de MinilibX
mlx:
	$(MAKE) -C $(MLX_DIR) || true

# Création de l'exécutable
$(NAME): $(ALL_OBJS)
	$(CC) $(ALL_OBJS) $(MLX_FLAGS) -o $(NAME)

# Règles explicites pour chaque fichier objet
$(OBJS_DIR)/main.o: $(SRCS_DIR)/main.c
	$(CC) $(CFLAGS) $(MLX_INC) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)/utils.o: $(SRCS_DIR)/utils.c
	$(CC) $(CFLAGS) $(MLX_INC) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)/map.o: $(SRCS_DIR)/map.c
	$(CC) $(CFLAGS) $(MLX_INC) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)/game.o: $(SRCS_DIR)/game.c
	$(CC) $(CFLAGS) $(MLX_INC) $(INCLUDES) -c $< -o $@
	
$(OBJS_DIR)/draw.o: $(SRCS_DIR)/draw.c
	$(CC) $(CFLAGS) $(MLX_INC) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)/exit.o: $(SRCS_DIR)/exit.c
	$(CC) $(CFLAGS) $(MLX_INC) $(INCLUDES) -c $< -o $@
	
$(OBJS_DIR)/flood_fill.o: $(SRCS_DIR)/flood_fill.c
	$(CC) $(CFLAGS) $(MLX_INC) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)/is_map_valid.o: $(SRCS_DIR)/is_map_valid.c
	$(CC) $(CFLAGS) $(MLX_INC) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)/utils2.o: $(SRCS_DIR)/utils2.c
	$(CC) $(CFLAGS) $(MLX_INC) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)/game2.o: $(SRCS_DIR)/game2.c
	$(CC) $(CFLAGS) $(MLX_INC) $(INCLUDES) -c $< -o $@
	
$(OBJS_DIR)/flood_fill2.o: $(SRCS_DIR)/flood_fill2.c
	$(CC) $(CFLAGS) $(MLX_INC) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)/game3.o: $(SRCS_DIR)/game3.c
	$(CC) $(CFLAGS) $(MLX_INC) $(INCLUDES) -c $< -o $@

$(GNL_OBJS_DIR)/get_next_line.o: $(GNL_DIR)/get_next_line.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(GNL_OBJS_DIR)/get_next_line_utils.o: $(GNL_DIR)/get_next_line_utils.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(PRINTF_OBJS_DIR)/ft_printf.o: $(FT_PRINTF_DIR)/ft_printf.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(PRINTF_OBJS_DIR)/functions.o: $(FT_PRINTF_DIR)/functions.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	$(MAKE) -C $(MLX_DIR) clean || true
	rm -rf $(OBJS_DIR)

# Nettoyage complet
fclean: clean
	rm -f $(NAME)

# Recompile tout
re: fclean all
