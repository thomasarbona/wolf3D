/*
** my.h for libmy in /home/arbona/CPool/CPool_Day09
**
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
**
** Started on  Thu Oct 13 09:22:28 2016 Thomas Arbona
** Last update Thu Nov 24 16:42:36 2016 Thomas ARBONA
*/

#ifndef MY_H_
# define MY_H_

# include <stdarg.h>

char	*convert_base(char *, char *, char *);
int	my_find_prime_sup(int);
int	my_getnbr_base(char *, char *);
int	my_getnbr(char *);
int	my_is_prime(int);
int	my_power_rec(int, int);
void	my_putchar(char);
int	my_putnbr_base(int, char *);
int	my_put_nbr(int);
int	my_putstr(char *);
char	*my_revstr(char *);
int	my_showmem(char *, int);
int	my_showstr(char *);
int	my_show_wordtab(char **);
void	my_sort_int_tab(int *, int);
int	my_square_root(int);
char	*my_strcapitalize(char *);
char	*my_strcat(char *, char *);
int	my_strcmp(char *, char *);
char	*my_strcpy(char *, char *);
char	*my_strdup(char *);
char	*my_strndup(char *, int);
int	my_str_isalpha(char *);
int	my_str_islower(char *);
int	my_str_isnum(char *);
int	my_str_isprintable(char *);
int	my_str_isupper(char *);
int	my_strlen(char *);
char	*my_strlowcase(char *);
char	*my_strncat(char *, char *, int);
int	my_strncmp(char *, char *, int);
char	*my_strncpy(char *, char *, int);
char	*my_strstr(char *, char *);
char	**my_str_to_wordtab(char *, char *);
char	*my_strupcase(char *);
int	my_swap(int *, int *);
int	my_swapchar(char **, int, int);
int	my_swapstr(char **, char **);
int	my_find_in_wordtab(char **, char *);
void	my_memset(char *, int, char);
int	my_str_contain(char *, char);
int	my_tablen(void **);
char	*my_str_replace(char *, int, int, char *);
int	my_intlen(int);
int	my_l_intlen(long int);
int	my_ll_intlen(long long int);
int	my_u_intlen(unsigned int);
int	my_ul_intlen(unsigned long int);
int	my_ull_intlen(unsigned long long int);
char	*my_int_str(int);
char	*my_l_int_str(long int);
char	*my_ll_int_str(long long int);
char	*my_u_int_str(unsigned int);
char	*my_ul_int_str(unsigned long int);
char	*my_ull_int_str(unsigned long long int);
char	*my_str_concat(char *, char *);
char	*my_str_template(char *template, ...);

int	my_printf(const char *, ...);
int	my_sprintf(char *, const char *, ...);
int	my_snprintf(char *, int, const char *, ...);
int	my_dprintf(int, const char *, ...);
char	*my_asprintf(const char*, ...);

int	my_vprintf(const char *, va_list);
int	my_vsprintf(char *, const char *, va_list);
int	my_vsnprintf(char *, int, const char *, va_list);
int	my_vdprintf(int, const char *, va_list);
char	*my_vasprintf(const char *, va_list);

#endif /* !MY_H_ */
