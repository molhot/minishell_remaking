#include "../minishell.h"

bool startswith(const char *s, const char *keyword)
{
    if (memcmp(s, keyword, ft_strlen(keyword)) == 0)
        return (true);
    else
        return (false);
}