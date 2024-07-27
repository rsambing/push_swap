/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsambing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:32:20 by rsambing          #+#    #+#             */
/*   Updated: 2024/05/17 14:36:31 by rsambing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <errno.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define CP "\033[1;30m"
# define CVA "\033[1;31m"
# define CVE "\033[1;32m"
# define CAO "\033[1;33m"
# define CAL "\033[1;34m"
# define CM "\033[1;35m"
# define CC "\033[1;36m"
# define CB "\033[1;37m"
# define SC "\033[0m"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *ptr, int c, size_t n);
void				*ft_calloc(size_t num_elements, size_t element_size);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char s, int fd);
void				*ft_memset(void *ptr, int value, size_t num);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_char(char c, int *tamanho);
void				ft_hex_lower(unsigned int num, int *tamanho);
void				ft_hex_upper(unsigned int num, int *tamanho);
void				ft_int(int n, int *tamanho);
void				ft_pointer(void *ptr, int *tamanho);
void				ft_string(char *str, int *tamanho);
void				ft_unsigned(unsigned int num, int *tamanho);

int					ft_lstsize(t_list *lst);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_exec(char *arg[]);
int					ft_tolower(int c);
int					ft_atoi(const char *str);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
int					ft_memcmp(const void *ptr1, const void *ptr2, size_t n);
int					ft_printf(const char *formato, ...);
int					ft_count_words(const char *s);
int					ft_is_valid_space(const char *str, int i);

char				*ft_itoa(int i);
char				*ft_strchr(const char *str, int c);
char				**ft_split(const char *s, char c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnstr(const char *h, const char *nd, size_t len);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strdup(const char *str);
char				*get_next_line(int fd);
char				*ft_strjoin_gnl(char *s1, char *s2);
char				*ft_strchr_gnl(char *s, int c);

size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_lstiter(t_list *lst, void (*f)(void *));
size_t				ft_strlen_gnl(char *s);

#endif
