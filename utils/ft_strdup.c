#include "../minishell.h"

static void	ft_rewrite(const char *src, char *src_2)
{
	while ((*src) != '\0')
	{
		*src_2 = *src;
		src_2 = src_2 + 1;
		src = src + 1;
	}
	*src_2 = '\0';
}

char	*ft_strdup(const char *s)
{
	size_t		len;
	char		*src_sub;

	len = ft_strlen(s);
	src_sub = (char *)malloc(sizeof(char) * (len + 1));
	if (src_sub == NULL)
		return (NULL);
	ft_rewrite(s, src_sub);
	return (src_sub);
}