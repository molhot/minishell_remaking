#include "minishell.h"

int	main()
{
	char	*input;

	while (true)
	{
		input = readline("$minishell > ");
		printf("input is > |%s|\n", input);//must delete
		if (input == NULL)
			break;
		add_history(input);
		free(input);
	}
	exit(0);
}