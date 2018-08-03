#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, choice;
    unsigned int top, size;
    int *stack = NULL;

    printf("Enter size of stack: ");
    scanf("%u", &size);

    stack = (int *)calloc(size, sizeof(int));

    top = 0;
    do
    {
        system("cls");

        printf("Size of stack = %u\n\n", size);

        printf("1. Push element\n");
        printf("2. Pop element\n");
        printf("3. Peek element\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (top == size)
            {
                printf("\nStack is FULL.\n\n");
                system("pause");
            }
            else
            {
                for (i = top - 1; i >= 0; i--)
                    stack[i + 1] = stack[i];

                printf("\nEnter element top push: ");
                scanf("%d", &stack[0]);

                top++;
            }
            break;
        case 2:
            if (top == 0)
                printf("\nStack is EMPTY\n\n");
            else
            {
                printf("\nElement poped: %d\n\n", stack[0]);

                for (i = 1; i < top; i++)
                    stack[i - 1] = stack[i];

                top--;
                stack[top] = 0;
            }
            system("pause");
            break;
        case 3:
            if (top == 0)
                printf("\nStack is EMPTY\n\n");
            else
                printf("\nElement peeked: %d\n\n", stack[0]);
            system("pause");
            break;
        case 4:
            if (top == 0)
                printf("\nStack is EMPTY\n");
            else
                for (i = top - 1; i >= 0; i--)
                    printf("%u: %d\n", i, stack[i]);

            printf("\n");
            system("pause");
            break;
        case 5:
            free(stack);
            break;
        default:
            printf("\nWrong option.\n\n");
            system("pause");
        }
    }while (choice != 5);
}
