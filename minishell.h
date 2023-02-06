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
#include <stdint.h>
#include <fcntl.h>

//for torkanizer structor
typedef struct s_token t_token;

typedef enum e_token_kind{
    TK_WORD,
    TK_RESERVED,
    TK_OP,
    TK_EOF
}t_token_kind;

struct s_token{
    char            *word;
    t_token_kind    kind;
    t_token         *next;
};

//tmp error handling fuinc
void	fatal_error(const char *msg) __attribute__((noreturn));

//implemenet command
int     exec(char *argv[]);
void    interpret(char *line, int *stat_loc);

//torkanizer
t_token *torkanizer(char *line);

//is_anything func, like [is_metacharacter]
bool    is_metacharacter(char c);
bool    is_word(const char *s);
bool    is_blank(char c);
bool    is_operator(const char *s);
bool    startswith(const char *s, const char *keyword);

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
char	**ft_split(char const *s, char c);

#endif