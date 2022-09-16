/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:45:30 by gacalaza          #+#    #+#             */
/*   Updated: 2022/09/16 00:51:01 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_isalpha(int argument); //feita
int		ft_isdigit(int argument); //feita
int		ft_isalnum(int argument); //feita
int		ft_isascii(int argument); //feita
int		ft_isprint(int argument); //feita
size_t	ft_strlen(const char *str); //feita
int		ft_toupper(int c); //feita
int		ft_tolower(int c); //feita
void	ft_bzero(void *str, size_t len); //feita
void	*ft_memset(void *str, int charc, size_t len); //feita
void	*ft_memcpy(void *dest, const void *src, size_t len); //feita
void	*ft_memmove(void *dest, const void *src, size_t n); //feita
void	*ft_memchr(const void *str, int c, size_t len);
int		ft_memcmp(const void *str1, const void *str2, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *str, int c); //feita
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(const char *str1, const char *str2, size_t len); //feita
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);
void	ft_putstr_fd(char *s, int fd); //feita
void	ft_putchar_fd(char c, int fd); //feita
void	ft_putnbr_fd(int n, int fd); //feita
void	ft_putendl_fd(char *s, int fd); //feita
char	*ft_strdup(const char *s); //feita
void	*ft_calloc(size_t nitems, size_t size);

#endif