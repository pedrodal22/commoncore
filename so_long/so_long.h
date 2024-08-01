/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:27:23 by pfranco-          #+#    #+#             */
/*   Updated: 2024/08/01 19:30:18 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include "mlx_linux/minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdarg.h>
# include <stdint.h>

typedef struct s_data
{
	char	**mapa;
	int		x_mapa;
	int		y_mapa;
	char	**flood_mapa;
	int		flood_mapa_x;
	int		flood_mapa_y;
	int		flood_player_count;
	int		flood_colet_count;
	int		flood_exit_count;
	int		mapa_colunas;
	int		mapa_linhas;
	int		pos_inicial_x;
	int		pos_inicial_y;
	int		pos_atual_x;
	int		pos_atual_y;
	int		exit_pos_x;
	int		exit_pos_y;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr_sand;
	void	*img_ptr_cato;
	void	*img_ptr_cowboy;
	void	*img_ptr_colet;
	void	*img_ptr_exit;
	void	*img_ptr_din;
	void	*img_ptr_cop;
	int		colet_total;
	int		colet_count;
	int		num_enemies;
	int		enemy_x;
	int		enemy_y;
	int		enemy_direction;
	int		count_moves;
}	t_data;

char	*get_next_line(int fd);
char	*ft_strjoin(char *line, char *buffer);
int		ft_strlen(char *str);
void	clear(char *buffer, int index);
int		checkline(char *buffer);
int		check_all(int argc, char **argv, t_data *dados);
int		check_nome_ficheiro(int argc, char **argv);
int		check_mapa_valido(char **argv, t_data *dados);
void	allocate_struct_map(int rows, int columns, t_data *dados);
void	moves(t_data *dados, int keysym, int px);
void	moves_ws(t_data *dados, int i);
void	moves_ad(t_data *dados, int i);
int		destruir(t_data *dados);
void	allocate_flood_map(int rows, int columns, t_data *dados);
void	mapa_linhas_colunas(t_data *dados, int fd);
int		flood_fill(t_data *dados);
void	find_player(t_data *dados, int fd);
void	flood(t_data *dados, int y, int x);
int		check_walls(t_data *dados);
void	free_map(t_data *dados);
void	map_images(t_data *dados);
void	create_images(t_data *dados, int largura, int altura);
void	map_images(t_data *dados);
void	put_image(t_data *dados, int x, int y, char caracter);
void	put_image2(t_data *dados, int x, int y, char caracter);
int		tecla(int keysym, t_data *dados);
int		destruir(t_data *dados);
int		moves_all(int keysym);
void	create_map(t_data *dados, int fd);
void	free_basic(t_data *dados);
void	free_all(t_data *dados);
void	free_map_flood(t_data *dados);
void	free_images(t_data *dados);
void	game_over(t_data *dados, int type);
void	inimigos_init(t_data *dados);
int		move_inimigos(t_data *dados);
void	move_inimigos_ad(t_data *dados);
int		ft_printf(const char *str, ...);
int		ft_conv(char *str, int i, va_list args);
int		ft_putchar(char c);
int		ft_putnbr(int nb);
int		ft_putstr(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_itoa(int n);
void	display_moves(t_data *dados);
void	start_all(t_data *dados, char *map);
int		check_invalid_char(int fd);
void	moves_ad2(t_data *dados, int x, int y, int i);
void	moves_ws2(t_data *dados, int x, int y, int i);
void	display_colet(t_data *dados);
void	print_errors(int error);

#endif