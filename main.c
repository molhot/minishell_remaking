#include "minishell.h"

int	main()
{
	char	*input;
	int		status;

	status = 0;
	while (true)
	{
		input = readline("$minishell > ");
		//printf("input is > |%s|\n", input);//must delete
		if (input == NULL)
			break ;
		add_history(input);
		if (input[0] == '\0')
			continue;
		interpret(input, &status);
		// interpret
		free(input);
	}
	exit(0);
}