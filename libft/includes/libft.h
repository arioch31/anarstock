/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:57:26 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/05/11 04:44:48 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# define VAL_ABS(x) (((x) < 0) ? -(x) : (x))

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi (char *str);
long int			ft_atoli (char *str);
void				ft_bzero (void *s, size_t n);
int					ft_isalnum (int c);
int					ft_isalpha (int c);
int					ft_isascii (int c);
int					ft_isdigit (int c);
int					ft_isprint (int c);
int					ft_ispace (char c);
int					uint_strlen(uintmax_t n, int base);
int					int_strlen(intmax_t n);
void				*ft_memccpy (void *dest, const void *src, int c, size_t n);
void				*ft_memchr (const void *str, int c, size_t n);
int					ft_memcmp (const void *s1, const void *s2, size_t n);
void				*ft_memcpy (void *dest, const void *src, size_t n);
void				*ft_memmove (void *dest, const void *src, size_t n);
void				*ft_memset (void *b, int c, size_t len);
size_t				ft_strlen (const char *str);
char				*ft_strdup (const char *str);
char				*ft_strcpy (char *dest, const char *src);
char				*ft_strncpy (char *dest, const char *src, size_t n);
char				*ft_strcat (char *dest, const char *src);
char				*ft_strncat (char *dest, const char *src, size_t n);
size_t				ft_strlcat (char *dest, const char *src, size_t n);
char				*ft_strchr (const char *src, int c);
char				*ft_strrchr (const char *str, int c);
char				*ft_strstr (const char *s1, const char *s2);
char				*ft_strnstr (const char *s1, const char *s2, size_t n);
int					ft_strcmp (const char *s1, const char *s2);
int					ft_strncmp (const char *s1, const char *s2, size_t n);
size_t				ft_lenword(const char *str, char c);
int					ft_tolower (int c);
int					ft_toupper (int c);
void				ft_putchar (char c);
void				ft_putchar_fd (char c, int fd);
void				ft_putstr (const char *str);
void				ft_putstr_fd (const char *str, int fd);
void				ft_putendl(const char *str);
void				ft_putendl_fd(const char *str, int fd);
void				ft_putdouble(double nb, int precision);
void				ft_putfloat(float nb, int precision);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *str);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t size);
void				ft_striter(char *str, void (*f)(char *));
void				ft_striteri(char *str, void (*f)(unsigned int, char *));
char				*ft_strmap(const char *str, char (*f)(char));
char				*ft_strmapi(const char *str, char (*f)(unsigned int, char));
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *str);
char				**ft_strsplit(const char *str, char c);
char				**ft_strsplit_charset(const char *str, char *charset);
unsigned int		nb_words(const char *str, char c);
char				*ft_itoa(int n);
char				*ft_ultoa_base(unsigned long long nb, int base, int maj);
char				*ft_umaxtoa_base(uintmax_t n, int base, int maj);
int					int_strlen(uintmax_t n, int base);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
size_t				ft_strindex(char *str, char c);
void				ft_print_tab(char **tab);

/*
** fonctions liste
*/
t_list				*ft_lstlast(t_list *start);
t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *nouveau);
void				ft_lstapp(t_list **alst, t_list *nouveau);
void				ft_lstaff(t_list *lst, void (*f)(t_list *elem));
int					ft_lstlen(t_list *start);
char				*ft_lstcat(t_list *start);
t_list				*ft_lstrsplit(const char *str, char c);
void				ft_lstinsert_all(t_list **alst, t_list **nouveau);
void				ft_lstinsert_one(t_list **alst, t_list **nouveau);
t_list				*ft_lstcpy(t_list *lst);
t_list				*ft_lstget(t_list *start, size_t index);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelpropre(t_list **alst, void (*del)(void*, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				*ft_lstiter_ret(t_list *lst, void *(*f)(t_list *e, void *r),
					void *ret);
void				*ft_lstiter_ret_rev(t_list *lst, void *(*f)(t_list *elem,
					void *r), void *ret);
t_list				*ft_lstxnew(size_t nb);

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_lstcmp(t_list *l1, t_list *l2,
					int (*f)(t_list *l1, t_list *l2));
void				ft_lstmove(t_list **dest, t_list **elem);
t_list				*ft_lst_tri_as(t_list *l, int (*f)(t_list *l1, t_list *l2));
t_list				*ft_lst_tri_ds(t_list *l, int (*f)(t_list *l1, t_list *l2));
int					ft_lstcheck(t_list *lst, int (*f)(t_list*));

#endif
