#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <assert.h>
#include <readline/readline.h>
#include <readline/history.h>

//tmp error handling fuinc
void	fatal_error(const char *msg);

//implemenet command
int     exec_absolutepath(char *ab_path);
int     exec_relativepath(char *path);

//utils
void	ft_bzero(void *str, size_t n);
int     ft_strncpy(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *string_row);
void	*ft_calloc(size_t n, size_t size);
int     ft_memcmp(const void *buf1, const void *buf2, size_t n);
char	*ft_strchr(const char *s, int c);

#endif