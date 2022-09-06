/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:14:10 by coder             #+#    #+#             */
/*   Updated: 2022/09/06 19:44:18 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>

int		ft_isalpha(int argument);
int		ft_isdigit(int argument);
int		ft_isalnum(int argument);
int		ft_isascii(int argument);
int		ft_isprint(int argument);
size_t	ft_strlen(const char *str);
void	*memset(void	*str, int c, size_t n);
void	ft_bzero(void	*s, size_t n);
void	*ft_memcpy(void	*restrict dest, const void	*restrict src, size_t n);
void	*ft_memmove(void	*dest, const void	*src, size_t n);
size_t	ft_strlcpy(char	*dst, const char	*src, size_t size);
size_t	ft_strlcat(char	*dst, const char	*src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char	*s, int c);
char	*ft_strrchr(const char	*s, int c);
int		ft_strncmp(const char	*s1, const char	*s2, size_t n);
void	*ft_memchr(const void	*s, int c, size_t n);
int		ft_memcmp(const void	*s1, const void	*s2, size_t n);
char	*ft_strnstr(const char	*big, const char	*little, size_t len);
int		ft_atoi(const char	*nptr);
void	*ft_calloc(size_t nitems, size_t size);
char	*ft_strdup(const char *s);

#endif