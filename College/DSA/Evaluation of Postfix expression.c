#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct variable
{
    char v;
    float value;
};

short int total_var = 0;
struct variable *var = NULL;

short int stack_size = 0;
float *stack = NULL;

int compare(const void *, const void *);
float value(const char);
float calculate(const float, const float, const char);
void push(const float);
float pop();
float peek();
void traverse();

int main()
{
    short int i, j;
    short int flag;
    char ch;
    char data[51] = "";
    float op_1, op_2;

    printf("Enter postfix notation [MAX 50 CHARACTERS]: ");
    gets(data);

    for (i = 0; i < strlen(data); i++)
    {
        ch = data[i];

        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        {
            for (j = 0, flag = 0; j < total_var; j++)
                if (var[j].v == ch)
                {
                    flag = 1;
                    break;
                }

            if (flag == 0)
            {
                total_var++;
                var = (struct variable *)realloc(var, total_var*sizeof(struct variable));
                var[total_var - 1].v = ch;
            }
        }
    }

    printf("\nEnter value of the variable(s):\n");
    qsort(var, total_var, sizeof(struct variable), compare);
    for (i = 0; i < total_var; i++)
    {
        printf("Enter value for %c: ", var[i].v);
        scanf("%f", &var[i].value);
    }

    for (i = 0; i < strlen(data); i++)
    {
        ch = data[i];

        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
            push(value(ch));
        else if ((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/'))
        {
            op_1 = pop();
            op_2 = pop();

            push(calculate(op_2, op_1, ch));
        }
        else
            continue;

        /*
        printf("\n");
        traverse();
        */
    }

    printf("\nResult = %.2f\n", pop());

    return 0;
}

int compare(const void *elem1, const void *elem2)
{
    struct variable a = *(struct variable *)elem1;
    struct variable b = *(struct variable *)elem2;

    return (a.v - b.v);
}

float value(const char ch)
{
    short int i;

    for (i = 0; i < total_var; i++)
        if (var[i].v == ch)
            break;

    return var[i].value;
}

float calculate(const float op_2, const float op_1, const char op)
{
    float ans;

    if (op == '+')
        ans =  op_2 + op_1;
    else if (op == '-')
        ans =  op_2 - op_1;
    else if (op == '*')
        ans =  op_2 * op_1;
    else if (op == '/')
        ans =  op_2 / op_1;

    return ans;
}

void push(const float ch)
{
    stack_size++;
    stack = (float *)realloc(stack, stack_size*sizeof(float));
    stack[stack_size - 1] = ch;
}

float pop()
{
    float temp;

    temp = stack[stack_size - 1];

    stack_size--;
    stack = (float *)realloc(stack, stack_size);

    return temp;
}

float peek()
{
    return stack[stack_size - 1];
}

void traverse()
{
    short int i;;

    for (i = stack_size - 1; i >= 0; i--)
        printf("%d: %.2f\n", i, stack[i]);
    printf("\n");
}
