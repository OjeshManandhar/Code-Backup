#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int top, size;
    int *stack = NULL;
    int i, choice;

    printf("enter size of stack: ");
    scanf("%u", &size);

    stack = (int *)calloc(size, sizeof(int));

    top = 0;
    do
    {
        system("cls");

        printf("Size of stack = %u\n\n", size);

        printf("1. Push element\n");
        printf("2. Pop element\n");
        printf("3. Traverse element\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%u", &choice);

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
                printf("\nEnter element to push: ");
                scanf("%d", &stack[top++]);
            }
            break;
        case 2:
            if (top == 0)
                printf("\nStack is EMPTY.\n\n");
            else
                printf("\nElement poped: %d\n\n", stack[--top]);
            system("pause");
            break;
        case 3:
            if (top == 0)
                printf("\nStack is EMPTY.\n");
            else
            {
                printf("\nElements in stack:\n");
                for (i = top - 1; i >= 0; i--)
                    printf("%u: %d\n", i, stack[i]);
            }
            printf("\n");
            system("pause");
            break;
        case 4:
            free(stack);
            break;
        default:
            printf("\nWrong option.\n\n");
            system("pause");
        }
    }while (choice != 4);

    return 0;
}
