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

#endif