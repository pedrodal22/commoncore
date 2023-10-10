/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:22:53 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/10 16:03:29 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(const char *str);
char	*ft_strchr(char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char ft_putchar(unsigned int fd, const char c);
void	ft_putnbr(int fd, int nb);

#endif
