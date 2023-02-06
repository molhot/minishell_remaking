#include "../minishell.h"

//torkanizer では | などのプロセスによって分解してあげればいいのでは

t_token *new_token(char *word, t_token_kind kind)
{
    t_token *tok;

    tok = ft_calloc(1, sizeof(*tok));
    printf("word is > |%s|\n", word);
    printf("kind is > |%d|\n", kind);
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
        line++;
    word = strndup(start, line - start);//strndupの作成
    if (word == NULL)
        fatal_error("strndup");
    *rest = line;
    return (new_token(word, TK_WORD));
}

t_token *torkanizer_n(char *line)
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
            tok = tok->next;
            tok = operator(&line, line);
        }
        else if (is_word(line) == true)
        {
            tok = tok->next;
            tok = word(&line, line);
        }
        else
            fatal_error("unexpected token");
    }
    tok->next = new_token(NULL, TK_EOF);
    return (head.next);
}

int main()
{
    t_token *test;
    char    *input;

    while (true)
	{
		input = readline("$minishell > ");
		printf("input is > |%s|\n", input);//must delete
        test = torkanizer_n(input);//とーかないざーに入ったものは整合性が取れたものとする
        // かつ引数は必ずある（ない場合は初めにリターンされるとする
        while (test != NULL)
        {
            printf("kind is > %d and word is > %s\n", test->kind, test->word);
            test = test->next;
        }	
	}
}

// gcc torkanizer_notinmain.c ../utils/*.c ../check_word/is_anything.c ../check_word/startswith.c  ../tmp_func/fatal_error.c -lreadline
//command
