/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 01:48:19 by pfranco-          #+#    #+#             */
/*   Updated: 2024/08/15 00:54:32 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>
# include <limits.h>

typedef struct node
{
	unsigned int	original_value;
	int				indice_objtv;
	struct node		*next;
}	t_node;

void			put_index(int argc, int *array, int *copy, int *array_index);
void			arrays(int argc, char **argv, int *array, int *copy);
void			in_st(int argc, t_node **stack_a, int *array, int *array_index);
void			do_all(int argc, char *argv[], int *copy, int *array);
void			stck_innit(t_node **top, int original_value, int indice_objtv);
void			push(t_node **fonte, t_node **destino);
void			rotate(t_node **top);
void			reverse_rotate(t_node **top);
void			swap(t_node **top);
int				numero_nodes(t_node **stackA);
int				check_order(t_node **stackA);
void			push_two(t_node **fonte, t_node **destino, int i);
void			rotate_two(t_node **stackA);
int				comparison(t_node **stackA, t_node **stackB);
void			bubble_sort(int *copy, int argc);
void			free_stacks(t_node *stackA);
void			free_arrays(int *array, int *array_index, int *copy);
int				check_double(int argc, char **argv);
int				check(int argc, char **argv);
int				check_overflow(const char *str, long long result, int simbolo);
int				atoi_grande(const char *str);
long int		ft_atoi(const char *str);
int				ft_putchar(char c);
int				ft_putstr(const char *str);
int				ft_conv(char *str, int i, va_list args);
char			*ft_strchr(const char *str, int c);
int				ft_printf(const char *str, ...);
int				sec_check(t_node **stack_a);
void			free_all(int *array, int *array_index, int *copy,
					t_node *stack_a);
void		    reverse_rotate_two(t_node **stackA);
void			swap_two(t_node **stackA);
void			rotate_two(t_node **stackA);
void			sort_3(t_node **stackA);
void 			rotate_three(t_node **stackB);
void		sort_5(t_node **stackA, t_node **stackB);

void print_stack(t_node *stack);

#endif 
