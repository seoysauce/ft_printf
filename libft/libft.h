/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:39:16 by seojeong          #+#    #+#             */
/*   Updated: 2020/12/30 16:39:19 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstmap(t_list *a, void *(*f)(void *), void (*del)(void *));
t_list			*ft_lstlast(t_list *lst);
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstadd_back(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
void			ft_lstadd_front(t_list **lst, t_list *new);
t_list			*ft_lstnew(void *content);
void			ft_putnbr_fd(int n, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_itoa(int n);
char			**ft_split(char const *s, char c);
size_t			ft_strlcat(char *dest, char *src, size_t size);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *str);
void			*ft_calloc(size_t num, size_t size);
char			*ft_strnstr(const char *s1, const char *s2, size_t len);
int				ft_toupper(int ch);
int				ft_tolower(int ch);
int				ft_isprint(int ch);
int				ft_isascii(int ch);
int				ft_isalnum(int ch);
int				ft_isdigit(int ch);
int				ft_isalpha(int ch);
int				ft_atoi(const char *str);
void			*ft_memset(void *ptr, int input_char, size_t num);
void			ft_bzero(void *ptr, size_t num);
int				ft_strncmp(const char *str1, const char *str2, size_t num);
char			*ft_strrchr(const char *str, int ch);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
int				ft_strlen(const char *str);
char			*ft_strchr(const char *str, int value);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
void			*ft_memchr(const void *ptr, int value, size_t n);
void			*ft_memmove(void *destination, const void *source, size_t num);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);

#endif
