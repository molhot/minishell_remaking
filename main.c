#include "minishell.h"

int	main()
{
	char	*input;

	while (true)
	{
		input = readline("$minishell > ");
		printf("input is > |%s|\n", input);//must delete
		if (input == NULL)
			break ;
		if (input[0] == '\0')
			continue ;
		add_history(input);
		exec_absolutepath(input);
		free(input);
	}
	exit(0);
}