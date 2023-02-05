#include "../minishell.h"

static char *searchpath(char *exec_path)
{
    char    path[PATH_MAX];
    char    *value;
    char    *end;
    char    *exec_filename;

    value = getenv("PATH");
    while (value != '\0')
    {
        ft_bzero(path, PATH_MAX);
        end = strchr(value, ':');
        if (end)
            strncpy(path, value, end - value);//strncpyは作り直す必要性
        else
            ft_strlcpy(path, value, PATH_MAX);
        ft_strlcat(path, "/", PATH_MAX);
        ft_strlcat(path, exec_path, PATH_MAX);
        if (access(path, X_OK) == 0)
        {
            exec_filename = ft_strdup(path);
            if (exec_filename == NULL)
                fatal_error("strdup\n");
            return (exec_filename);
        }
        if (end == NULL)
            return (NULL);
        value = end + 1;
    }
    return (NULL);
}

int exec_relativepath(char *path)
{
    extern char **environ;
    char        *argv[] = {
        searchpath(path),
        NULL
    };
    pid_t       pid;
    int         wstatus;

    pid = fork();
    if (pid < 0)
        fatal_error("fork\n");
    else if (pid == 0)
    {
        execve(searchpath(path), argv, environ);
        fatal_error("execve");
    }
    else
    {
        wait(&wstatus);
        return (WEXITSTATUS(wstatus));
    }
    return (0);
}

int exec_absolutepath(char *ab_path)
{
    extern char **environ;
    char        *argv[] = {
        ab_path,
        NULL
    };
    pid_t		pid;
    int			wstatus;

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