#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>

#include <QBASIC_func_C.h>

typedef struct variables
{
    unsigned char variable;
    unsigned short int value;
} variables;

unsigned short int total_words, max_len, total_var;
unsigned short int *words_len, sum_len;
unsigned long int answer_count;
unsigned char **words = NULL;
unsigned char *sum = NULL;
variables *list = NULL;

void print_variables(unsigned char *data)
{
    unsigned short int i;

    for (i = 0; i < max_len; i++)
        // printf(" %d:%d", data[i], data[i]);
        printf(" %c", data[i]);
    printf("\n");
}

void print_list(variables *data)
{
    unsigned short int i;

    for (i = 0; i < total_var; i++)
        printf("%c:%u \t", data[i].variable, data[i].value);
    printf("\n");
}

unsigned short int value_of_variable(const unsigned char var, variables *data)
{
    unsigned short int i, result;

    if (var == 0)
        result = 0;

    for (i = 0; i < total_var; i++)
        if (var == data[i].variable)
            result = data[i].value;

    return result;
}

void print_answer(variables *data)
{
    unsigned short int i, j;

    for (i = 0; i < total_words; i++)
    {
        for (j = 0; j < max_len; j++)
            if (words[i][j] == 0)
                printf("  ");
            else
                printf(" %u", value_of_variable(words[i][j], data));
        printf("\n");
    }

    for (i = 0; i < max_len; i++)
        printf("%c%c", 196, 196);
    printf("\n");

    for (i = 0; i < max_len; i++)
        printf(" %u", value_of_variable(sum[i], data));
    printf("\n");
}

unsigned short int check_pattern(variables *data)
{
    unsigned short int i, j;
    unsigned long int words_sum, sum_sum, temp;

    words_sum = sum_sum = 0;

    for (i = 0; i < total_words; i++)
        if (value_of_variable(words[i][max_len - words_len[i]], data) == 0)
            return 0;

    if (value_of_variable(sum[max_len - sum_len], data) == 0)
        return 0;

    for (i = 0; i < max_len; i++)
    {
        sum_sum = sum_sum*10 + value_of_variable(sum[i], data);

        temp = 0;
        for (j = 0; j < total_words; j++)
            temp += value_of_variable(words[j][i], data);
        words_sum = words_sum*10 + temp;
    }

    if (sum_sum == words_sum)
        return 1;
    else
        return 0;
}

void generate_patterns(variables *data, const unsigned int pos)
{
    unsigned short int i, j;
    unsigned short int flag;

    for (i = 0; i < 10; i++)
    {
        data[pos].value = i;

        flag = 0;
        for (j = 0; j < pos; j++)
            if (data[pos].value == data[j].value)
            {
                flag = 1;
                break;
            }

        if (flag == 1)
            continue;

        if (pos == total_var - 1)
        {
            if (check_pattern(data) == 1)
            {
                printf("Ans number: %lu\n\n", ++answer_count);
                print_list(data);
                printf("\n");
                print_answer(data);
                printf("-------------------------------------------------\n");
            }
        }
        else
            generate_patterns(data, pos + 1);
    }
}

int main()
{
    unsigned short int len;
    short int i, j, k;
    unsigned short int flag;
    char temp[11];

    printf("Enter number of words: ");
    scanf("%hu", &total_words);

    words_len = (unsigned short int *)calloc(total_words, sizeof(unsigned short int));
    words = (unsigned char **)calloc(total_words, sizeof(unsigned char *));

    printf("\n");
    max_len = 0;
    for (i = 0; i < total_words; i++)
    {
        printf("Enter word %d: ", i + 1);
        fflush(stdin);
        gets(temp);

        words_len[i] = len = strlen(temp);
        if (len > max_len)
        {
            for (j = 0; j < i; j++)
            {
                words[j] = (unsigned char *)realloc(words[j], max_len*sizeof(unsigned char));
                for (k = len - 1; k >= (len - max_len); k--)
                    words[j][k] = words[j][k - (len - max_len)];
                for (k = 0; k < (len - max_len); k++)
                    words[j][k] = 0;
            }

            max_len = len;
        }

        words[i] = (unsigned char *)realloc(words[i], max_len*sizeof(unsigned char));

        for (j = max_len - 1; j >= (max_len - len); j--)
        {
            flag = 0;
            for (k = 0; k < total_var; k++)
                if (list[k].variable == char_upper(temp[j - (max_len - len)]))
                {
                    flag = 1;
                    break;
                }

            if (flag == 0)
            {
                total_var++;
                list = (variables *)realloc(list, total_var*sizeof(variables));
                list[total_var - 1].variable = char_upper(temp[j - (max_len - len)]);
                list[total_var - 1].value = 0;
            }

            words[i][j] = char_upper(temp[j - (max_len - len)]);
        }
        for (j = 0; j < (max_len - len); j++)
            words[i][j] = 0;
    }

    printf("\nEnter sum: ");
    fflush(stdin);
    gets(temp);

    sum_len = len = strlen(temp);
    if (len > max_len)
    {
        for (i = 0; i < total_words; i++)
        {
            words[i] = (unsigned char *)realloc(words[i], max_len*sizeof(unsigned char));

            for (j = len - 1; j >= (len - max_len); j--)
                words[i][j] = words[i][j - (len - max_len)];
            for (j = 0; j < (len - max_len); j++)
                words[i][j] = 0;
        }

        max_len = len;
    }

    sum = (unsigned char *)calloc(max_len, sizeof(unsigned char));

    for (i = max_len - 1; i >= (max_len - len); i--)
    {
        flag = 0;
        for (j = 0; j < total_var; j++)
            if (list[j].variable == char_upper(temp[i - (max_len - len)]))
            {
                flag = 1;
                break;
            }

        if (flag == 0)
        {
            total_var++;
            list = (variables *)realloc(list, total_var*sizeof(variables));
            list[total_var - 1].variable = char_upper(temp[i - (max_len - len)]);
            list[total_var - 1].value = 0;
        }

        sum[i] = char_upper(temp[i - (max_len - len)]);
    }
    for (i = 0; i < (max_len - len); i++)
        sum[i] = 0;

    printf("\n");
    for (i = 0; i < total_words; i++)
        print_variables(words[i]);
    for (i = 0; i < max_len; i++)
        printf("%c%c", 196, 196);
    printf("\n");
    print_variables(sum);

    printf("============================================================\n");

    generate_patterns(list, 0);
    printf("\nTotal answers = %lu\n", answer_count);

    return 0;
}
