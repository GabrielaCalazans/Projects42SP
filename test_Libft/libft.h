/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:14:10 by coder             #+#    #+#             */
/*   Updated: 2022/09/09 01:55:37 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_isalpha(int argument);
int		ft_isdigit(int argument);
int		ft_isalnum(int argument);
int		ft_isascii(int argument);
int		ft_isprint(int argument);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *str, int charc, size_t len);
void	ft_bzero(void *str, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t len);
void	*ft_memmove(void *dest, const void	*src, size_t n);
size_t	ft_strlcpy(char	*dst, const char	*src, size_t size);
size_t	ft_strlcat(char	*dst, const char	*src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(const char *str1, const char *str2, size_t len);
void	*ft_memchr(const void *str, int c, size_t len);
int		ft_memcmp(const void *str1, const void *str2, size_t len);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nitems, size_t size);
char	*ft_strdup(const char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strnstr(const char *big, const char *little, size_t len);

#endif