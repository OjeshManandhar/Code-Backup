#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int i, size;
    int *queue = NULL;
    int choice, rear;

    printf("Enter size of queue: ");
    scanf("%u", &size);

    queue = (int *)calloc(size, sizeof(int));

    rear = 0;
    do
    {
        system("cls");

        printf("Size of queue = %u\n\n", size);

        printf("1. Enqueue element\n");
        printf("2. Dequeue element\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (rear == size)
            {
                printf("\nQueue is FULL.\n\n");
                system("pause");
            }
            else
            {
                printf("\nEnter element to enqueue: ");
                scanf("%d", &queue[rear++]);
            }
            break;
        case 2:
            if (rear == 0)
                printf("\nQueue is EMPTY.\n\n");
            else
            {
                printf("\nElement dequeued: %d\n\n", queue[0]);
                for (i = 0; i < rear; i++)
                    queue[i] = queue[i + 1];
                rear--;
            }
            system("pause");
            break;
        case 3:
            if (rear == 0)
                printf("\nQueue is EMPTY.\n");
            else
            {
                printf("\nElements in queue are:\n");
                for (i = 0; i < rear; i++)
                    printf("%u: %d\n", i, queue[i]);
            }
            printf("\n");
            system("pause");
            break;
        case 4:
            free(queue);
            break;
        default:
            printf("\nWrong option\n\n");
            system("pause");
        }
    }while (choice != 4);

    return 0;
}
