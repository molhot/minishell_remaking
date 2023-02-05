#include "../minishell.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t n)
{
	unsigned char	*buf1_sub;
	unsigned char	*buf2_sub;

	if (buf1 == NULL && buf2 == NULL)
		return (0);
	buf1_sub = (unsigned char *)buf1;
	buf2_sub = (unsigned char *)buf2;
	while (n-- != 0)
	{
		if (*buf1_sub != *buf2_sub)
			return (*buf1_sub - *buf2_sub);
		buf1_sub = buf1_sub + 1;
		buf2_sub = buf2_sub + 1;
	}
	return (0);
}