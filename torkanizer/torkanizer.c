#include "../minishell.h"

//torkanizer では | などのプロセスによって分解してあげればいいのでは

t_token *new_token(char *word, t_token_kind kind)
{
    t_token *tok;

    tok = ft_calloc(1, sizeof(*tok));
    if (tok == NULL)
        fatal_error("calloc\n");
    tok->word = word;
    tok->kind = kind;
    return (tok);
}

bool    consume_blank(char **rest, char *line)
{
    if (is_blank(*line))
    {
        while (*line != '\0' && is_blank(*line) == true)
            line++;
        *rest = line;
        return (true);
    }
    *rest = line;
    return (false);
}

t_token *operator(char **rest, char *line)
{
    static char *const operators[] = {
        "||", "&", "&&", ";", ";;", "(", ")", "|", "\n"
    };
    size_t                          i;
    char                            *op;

    i = 0;
    while (i < sizeof(operators) / sizeof(*operators))
    {
        if (startswith(line, operators[i]) == true)
        {
            op = ft_strdup(operators[i]);
            if (op == NULL)
                fatal_error("strdup\n");
            *rest = line + strlen(op);
            return (new_token(op, TK_OP));
        }
        i++;
    }
    fatal_error("unexpected operator\n");
}

t_token *word(char **rest, char *line)
{
    const char  *start;
    char        *word;

    start = line;
    while (*line != '\0' && is_metacharacter(*line) == false)
    {
		if (*line == '\'')
		{
			line++;
			while (*line != '\'')
			{
				if (*line == '\0')
					fatal_error("single quote\n");
				line++;
			}
			line++;
		}
		else
			line++;
	}
    word = strndup(start, line - start);//strndupの作成
    if (word == NULL)
        fatal_error("strndup");
    *rest = line;
    return (new_token(word, TK_WORD));
}

t_token *torkanizer(char *line)
{
    t_token head;
    t_token *tok;

    head.next = NULL;
    tok = &head;
    while (*line != '\0')
    {
        if (consume_blank(&line, line) == true)
            continue;
        else if (is_operator(line) == true)
        {
            tok->next = operator(&line, line);
            tok = tok->next;
        }
        else if (is_word(line) == true)
        {
            tok->next = word(&line, line);
            tok = tok->next;
        }
        else
            fatal_error("unexpected token");
    }
    tok->next = new_token(NULL, TK_EOF);
    return (head.next);
}

// t_token *torkanizer(char *line)
// {
//     t_token *tok;
//     t_token *f_token;

//     tok = ft_calloc(1, sizeof(t_token *));
//     f_token = tok;
//     printf("f_token is %p\n", f_token);
//     while (*line != '\0')
//     {
//         if (consume_blank(&line, line) == true)
//             continue;
//         else if (is_operator(line) == true)
//         {
//             tok = operator(&line, line);
//             tok = tok->next;
//         }
//         else if (is_word(line) == true)
//         {
//             tok = word(&line, line);
//             printf("tokword is >%s\n", tok->word);
//             printf("token is %p\n", tok);
//             tok = tok->next;
//         }
//         else
//             fatal_error("unexpected token");
//     }
//     printf("token is %p\n", tok);
//     tok = new_token(NULL, TK_EOF);
//     printf("f_token is >%p\n", f_token);
//     return (f_token);
// }

