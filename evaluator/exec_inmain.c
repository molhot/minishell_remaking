#include "../minishell.h"

static char *searchpath(const char *exec_path)
{
    char    path[PATH_MAX];
    char    *value;
    char    *end;
    char    *exec_filename;

    value = getenv("PATH");
    while (*value != '\0')
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

void    path_check(const char *path)
{
    if (path == NULL)
        fatal_error("path is NULL\n");
    else if (access(path, F_OK) < 0)
        fatal_error("path can not access\n");
}

//interpretを分割している

int exec(char *argv[])
{
    extern char **environ;
    const char  *path;
    pid_t       pid;
    int         wstatus;

    pid = fork();
    path = (const char *)argv[0];
    if (pid < 0)
        fatal_error("fork\n");
    else if (pid == 0)
    {
        if (path[0] != '/')
            path = searchpath(path);
        path_check(path);
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

char	**token_to_chararray(t_token	*token)
{
	char	**argv;
	t_token	*token_f;
	size_t	malloc_count;
	size_t	arg_position;

	malloc_count = 0;
	if (token == NULL)
		return (NULL);
	token_f = token;
	while (token->kind != TK_EOF)
	{
		printf("%s\n", token->word);
		token = token->next;
		malloc_count++;
	}
	argv = (char **)malloc(sizeof(char *) * (malloc_count + 1));
	if (argv == NULL)
		fatal_error("malloc\n");
	token = token_f;
	arg_position = 0;
	while (arg_position != malloc_count)
	{
		argv[arg_position] = ft_strdup(token->word);
		arg_position++;
		token = token->next;
	}
	argv[arg_position] = NULL;
	return (argv);
}

void    interpret(char *line, int *stat_loc)
{
    t_token *token;
    char    **argv;

	printf("%s\n", line);
	token = torkanizer(line); //この時点でeofはすでにはじいているので記載なし
	printf("%s\n", token->word);
	if (token == NULL)
		return ;
	argv =  token_to_chararray(token);
	*stat_loc = exec(argv);
}