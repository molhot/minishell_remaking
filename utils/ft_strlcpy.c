#include "../minishell.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const char	*src_firstaddress;

	src_firstaddress = src;
	if (size == 0)
		return (ft_strlen(src));
	while ((size != 1) && (*src != '\0'))
	{
		*dst = (char)*src;
		dst = dst + 1;
		src = src + 1;
		size = size - 1;
	}
	*dst = '\0';
	return (ft_strlen(src_firstaddress));
}