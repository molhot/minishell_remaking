#include "../minishell.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*dest;

	if ((n == 0) || (size == 0))
	{
		dest = ft_calloc(1, 1);
		return (dest);
	}
	if (SIZE_MAX / n <= size)
		return (NULL);
	dest = malloc(n * size);
	if (dest == NULL)
		return (dest);
	ft_bzero(dest, n * size);
	return (dest);
}