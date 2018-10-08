#include <stdio.h>
#include <stdlib.h>
#include <string.h>

short int stack_size = 0;
char *stack = NULL;

short int p_size = 0;
char *p = NULL;

void push(const char);
char pop();
char peek();
void traverse();
void add_in_p(const char);
short int check_if_op(const char);
short int find_precedence(const char, const char);

int main()
{
    short int i, counter = 0;
    char q[51], temp_q[51] = "(";
    char ch;

    printf("Enter Infix expression [MAX 50 CHARACTERS]: ");
    gets(q);

    strcat(temp_q, q);
    strcat(temp_q, ")");
    strcpy(q, temp_q);
    strrev(q);

    printf("\nSN %c %-6s %c %-15s %c P\n", 179, "Symbol", 179, "Stack", 179);

    for (i = 0; i < strlen(q); i++)
    {
        ch = q[i];

        if (ch == ')')
            push(ch);
        else if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
            add_in_p(ch);
        else if (check_if_op(ch) == 1)
        {
            if (peek() == ')')
                push(ch);
            else if (check_if_op(peek()) == 1)
            {
                if (find_precedence(ch, peek()) >= 0)
                    push(ch);
                else
                    while (1)
                    {
                        if (peek() == ')')
                        {
                            push(ch);
                            break;
                        }
                        else
                            add_in_p(pop());

                        printf("%-2d %c %-6c %c ", ++counter, 179, ch, 179);
                        traverse();
                        printf(" %c %s\n", 179, p);
                    }
            }
        }
        else if (ch == '(')
            while (1)
            {
                if (peek() == ')')
                {
                    pop();
                    break;
                }
                else
                    add_in_p(pop());

                printf("%-2d %c %-6c %c ", ++counter, 179, ch, 179);
                traverse();
                printf(" %c %s\n", 179, p);
            }
        else
            continue;

        printf("%-2d %c %-6c %c ", ++counter, 179, ch, 179);
        traverse();
        printf(" %c %s\n", 179, p);
    }

    strrev(p);
    printf("\nEquivalent Prefix notation: %s\n", p);

    free(stack);
    free(p);

    return 0;
}

void push(const char ch)
{
    stack_size++;
    stack = (char *)realloc(stack, stack_size*sizeof(char));
    stack[stack_size - 1] = ch;
}

char pop()
{
    char temp;

    temp = stack[stack_size - 1];

    stack_size--;
    stack = (char *)realloc(stack, stack_size);

    return temp;
}

char peek()
{
    return stack[stack_size - 1];
}

void traverse()
{
    short int i;
    char *temp = NULL;

    temp = (char *)calloc(stack_size + 1, sizeof(char));

    for (i = 0; i < stack_size; i++)
        temp[i] = stack[i];

    temp[i] = 0;

    if (stack_size == 0)
        printf("%-15s", "<null>");
    else
        printf("%-15s", temp);

    free(temp);
}

void add_in_p(const char ch)
{
    if (p_size == 0)
    {
        p_size++;
        p = (char *)calloc(p_size, sizeof(char));
    }

    p_size++;
    p = (char *)realloc(p, p_size*sizeof(char));
    p[p_size - 2] = ch;
    p[p_size - 1] = 0;
}

short int check_if_op(const char ch)
{
    if ((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/') || (ch == '%') || (ch == '^'))
        return 1;
    else
        return 0;
}

short int find_precedence(const char ch, const char tos)
{
    struct precedence
    {
        char op;
        short int level;
    };

    short int i, j;
    struct precedence p[6] = {
                                {'-', 1},
                                {'+', 1},
                                {'*', 2},
                                {'/', 2},
                                {'%', 2},
                                {'^', 3},
                            } ;

    for (i = 0; i < 6; i++)
        if (ch == p[i].op)
            break;

    for (j = 0; j < 6; j++)
        if (tos == p[j].op)
            break;

    return (p[i].level - p[j].level);
}
