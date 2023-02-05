#include "../minishell.h"

void	ft_bzero(void *str, size_t n)
{
	char	*str_remake;

	str_remake = (char *)str;
	while (n != 0)
	{
		*str_remake = '\0';
		str_remake = str_remake + 1;
		n = n - 1;
	}
}