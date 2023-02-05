#include "../minishell.h"

int exec_absolutepath_n(char *ab_path)
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

int exec_relativepath(char *exec_path)
{
    char    path[PATH_MAX];
    char    *value;
    char    *end;

    value = getenv("PATH");
    while (value != '\0')
    {
        
    }
}

int main(int argc, char *argv[])
{
    (void)argc;
    if (argv[1][1] == '/')
        exec_absolutepath_n(argv[1]);
    else
        exec_relativepath(argv[1]);
}