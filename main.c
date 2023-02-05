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
		if (input[0] == '/')
			exec_absolutepath(input);
		else
			exec_relativepath(input);
		free(input);
	}
	exit(0);
}