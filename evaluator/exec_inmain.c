#include "../minishell.h"

int exec_absolutepath(char *ab_path)
{
    extern char **environ;
    char        *argv[] = {
        ab_path,
        NULL
    };
    pid_t       pid;
    int         wstatus;

    pid = fork();
    if (pid < 0)
        fatal_error("fork\n");
    else if (pid == 0)
    {
        execve(ab_path, argv, environ);
        fatal_error("execve");
    }
    else
    {
        wait(&wstatus);
        return (WEXITSTATUS(wstatus));
    }
    return (0);
}