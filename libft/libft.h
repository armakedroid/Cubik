/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argharag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:58:51 by argharag          #+#    #+#             */
/*   Updated: 2025/04/12 18:59:12 by argharag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct my_v
{
	int		i;
	int		m;
	int		a;
	int		b;
	char	**for_c;
	int		count;
	int		count_e;
	int		count_p;
	int		count_c;
}	t_s_str;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct my_nodes
{
	int				num;
	int				index;
	struct my_nodes	*next;
	struct my_nodes	*prev;
}	t_m;

char		*ft_strdup(const char *s1);
void		*ft_calloc(size_t count, size_t size);
ssize_t		ft_atoi(const char *str);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strrchr(const char *s, int c);
char		*ft_strchr(const char *s, int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *b, int c, size_t len);
size_t		ft_strlen(const char *s);
int			ft_isprint(int c);
int			ft_isascii(int c);
int			ft_isalnum(int c);
int			ft_isdigit(int c);
int			ft_isalpha(int c);
void		ft_putnbr_fd(int n, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_itoa(int n);
char		**ft_split(char const *s, char c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		ft_lstadd_back(t_m **lst, t_m *new);
void		ft_lstadd_front(t_m **lst, t_m *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_m			*ft_lstlast(t_m **lst);
t_m			*ft_lstnew(int num, int index);
int			ft_lstsize(t_m *lst);

#endif
