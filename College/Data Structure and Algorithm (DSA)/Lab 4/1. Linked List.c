#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list
{
    int data;
    struct linked_list *next;
} node;

node *start = NULL;

void insert_beginning();
void insert_at_pos();
void insert_end();

void delete_beginning();
void delete_at_pos();
void delete_end();

void traverse();

void search();

int main()
{
    int choice;
    node *temp;

    do
    {
        system("cls");

        printf("1. Insert at beginning\n");
        printf("2. Insert at position\n");
        printf("3. Insert at end\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at position\n");
        printf("6. Delete at end\n");
        printf("7. Traverse\n");
        printf("8. Search\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        printf("\n");

        switch (choice)
        {
        case 1:
            insert_beginning();
            break;
        case 2:
            insert_at_pos();
            break;
        case 3:
            insert_end();
            break;
        case 4:
            delete_beginning();
            break;
        case 5:
            delete_at_pos();
            break;
        case 6:
            delete_end();
            break;
        case 7:
            traverse();
            break;
        case 8:
            search();
            break;
        case 9:
            while (start != NULL)
            {
                temp = start;
                start = start->next;

                free(temp);
            }

            printf("Program terminated. List deleted.\n\n");

            break;
        default:
            printf("Wrong option.\n\n");
        }

        system("pause");
    }while (choice != 9);

    return 0;
}

void insert_beginning()
{
    node *item = NULL;

    item = (node *)calloc(1, sizeof(node));

    printf("Enter data to enter: ");
    scanf("%d", &item->data);

    item->next = start;
    start = item;

    printf("\n%d inserted at beginning.\n\n", item->data);
}

void insert_at_pos()
{
    node *position = NULL, *item = NULL;
    int n, i, flag = 0;

    if (start == NULL)
    {
        printf("As list is empty, the data will be inserted at beginning.\n");

        item = (node *)calloc(1, sizeof(node));

        printf("Enter data to be inserted: ");
        scanf("%d", &item->data);

        start = item;
        item->next = NULL;

        printf("\n%d inserted at beginning.\n\n", item->data);
    }
    else
    {
        printf("Enter position to insert data: ");
        scanf("%d", &n);

        i = 1;
        position = start;

        while (1)
        {
            if (position->next == NULL)
                break;
            if (i == n - 1)
            {
                flag = 1;
                break;
            }

            i++;
            position = position->next;
        }

        if (flag == 1)
        {
            item = (node *)calloc(1, sizeof(node));

            printf("\nEnter data to insert: ");
            scanf("%d", &item->data);

            item->next = position->next;
            position->next = item;

            printf("\n%d inserted at location %d.\n\n", item->data, n);
        }
        else if (flag == 0)
            printf("\nLocation not found.\n\n");
    }
}

void insert_end()
{
    node *end = NULL, *item = NULL;

    item = (node *)calloc(1, sizeof(node));

    printf("Enter data to insert: ");
    scanf("%d", &item->data);

    if (start == NULL)
    {
        start = item;
        item->next = NULL;
    }
    else
    {
        end = start;
        while (end->next != NULL)
            end = end->next;

        end->next = item;
        item->next = NULL;
    }

    printf("\n%d inserted at end.\n\n", item->data);
}

void delete_beginning()
{
    node *temp;

    if (start == NULL)
        printf("List is EMPTY.\n\n");
    else
    {
        temp = start;
        start = start->next;

        printf("%d deleted at beginning of list.\n\n", temp->data);

        free(temp);
    }
}

void delete_at_pos()
{
    node *position = NULL, *before_position = NULL;
    int n, i, flag = 0;

    if (start == NULL)
        printf("List is EMPTY.\n\n");
    else
    {
        printf("Enter position to delete data: ");
        scanf("%d", &n);

        if (n == 1)
        {
            flag = 1;
            position = start;

            start = start->next;

            printf("\n%d deleted at location %d.\n\n", position->data, n);

            free(position);
        }
        else
        {
            i = 1;
            position = start;

            while (1)
            {
                if (position == NULL)
                    break;
                if (i == n)
                {
                    flag = 1;
                    break;
                }

                i++;
                before_position = position;
                position = position->next;
            }

            if (flag == 1)
            {
                before_position->next = position->next;

                printf("\n%d deleted at location %d.\n\n", position->data, n);

                free(position);
            }
            else if (flag == 0)
                printf("\nLocation not found.\n\n");
        }
    }

}

void delete_end()
{
    node *last = NULL, *second_last = NULL;

    if (start == NULL)
        printf("List is EMPTY.\n\n");
    else if (start->next == NULL)
    {
        last = start;

        printf("%d deleted from end.\n\n", start->data);

        start = NULL;

        free(last);
    }
    else
    {
        last = second_last = start;

        while (last->next != NULL)
        {
            second_last = last;
            last = last->next;
        }

        second_last->next = NULL;

        printf("%d deleted from end.\n\n", last->data);

        free(last);
    }
}

void traverse()
{
    node *temp = NULL;
    int count = 1;

    if (start == NULL)
        printf("List is EMPTY.\n");
    else
    {
        printf("The elements in the list are:\n");

        temp = start;

        while (temp != NULL)
        {
            printf("%d: %d\n", count++, temp->data);
            temp = temp->next;
        }
    }

    printf("\n");
}

void search()
{
    node *temp = NULL;
    int n, flag = 0, count = 1;

    if (start == NULL)
        printf("List is eEMPTY.\n\n");
    else
    {
        printf("Enter data to search: ");
        scanf("%d", &n);

        temp = start;
        while (temp != NULL)
        {
            if (temp->data == n)
            {
                flag = 1;
                break;
            }

            temp = temp->next;
            count++;
        }
    }

    if (flag == 0)
        printf("\nData not found.\n\n");
    else
        printf("\n%d found at %d position.\n\n", n, count);
}
