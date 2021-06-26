/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 13:57:01 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/01/20 20:14:04 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H
# include <stdlib.h>
# include <unistd.h>

void				*ft_memccpy(void *dest, const void *src, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memchr(const void *s, int c, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t len);
void				*ft_memcpy(void *dest, void *src, size_t len);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memset(void *s, int c, size_t len);
char				*ft_strcat(char *s1, const char *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t len);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *str);
size_t				ft_strlen(const char *s);
char				*ft_strncat(char *s1, const char *s2, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
size_t				ft_strlcpy(char *dest, const char *src, size_t dstsize);
char				*ft_strnstr(const char *hay, const char *n, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_atoi(const char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

#endif
