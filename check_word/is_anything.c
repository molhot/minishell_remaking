#include "../minishell.h"

bool is_metacharacter(char c)
{
    if (c != '\0' && ft_strchr("|&;()<>\t\n", c) != NULL)
        return (true);
    else
        return (false);
}

bool is_word(const char *s)
{
    if (s != NULL && is_metacharacter(*s) == false)
        return (true);
    else
        return (false);
}

bool is_blank(char c)
{
    if (c == ' ' || c == '\t' || c == '\n')
        return (true);
    else
        return (false);
}

bool is_operator(const char *s)
{
    static char *const operators[] = {
        "||", "&", "&&", ";", ";;", "(", ")", "|", "\n"
    };
    size_t                          i = 0;

    while (i < sizeof(operators) / sizeof(*operators))
    {
        if (startswith(s, operators[i]))
            return (true);
        i++;
    }
    return (false);
}