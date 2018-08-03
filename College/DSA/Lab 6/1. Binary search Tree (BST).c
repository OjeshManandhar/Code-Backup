#include <stdio.h>
#include <stdlib.h>

//bst => binary search tree
typedef struct bst
{
    struct bst *left;
    int info;
    struct bst *right;
} node;

node *insert_node(node *, int);
void pre_order(node *);
void in_order(node *);
void post_order(node *);
node *delete_node(node *, int);
void search(node *, int);
node *find_max(node *);
node *find_min(node *);
void delete_tree(node *);

int main()
{
    int data, choice;
    node *root = NULL, *temp;

    do
    {
        system("cls");

        printf("1. Insert node\n");
        printf("2. Traverse in pre-order\n");
        printf("3. Traverse in in-order\n");
        printf("4. Traverse in post-order\n");
        printf("5. Delete node\n");
        printf("6. Search node\n");
        printf("7. Find maximum\n");
        printf("8. Find minimum\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        printf("\n");

        switch (choice)
        {
        case 1:
            printf("Enter node to add: ");
            scanf("%d", &data);

            root = insert_node(root, data);
            break;
        case 2:
            if (root == NULL)
                printf("Tree is empty.\n\n");
            else
            {
                printf("Nodes in pre-order:\n");
                pre_order(root);
                printf("\b\b.\n\n");
            }
            break;
        case 3:
            if (root == NULL)
                printf("Tree is empty.\n\n");
            else
            {
                printf("Nodes in in-order:\n");
                in_order(root);
                printf("\b\b.\n\n");
            }
            break;
        case 4:
            if (root == NULL)
                printf("Tree is empty.\n\n");
            else
            {
                printf("Nodes in post-order:\n");
                post_order(root);
                printf("\b\b.\n\n");
            }
            break;
        case 5:
            if (root == NULL)
                printf("Tree is empty.\n\n");
            else
            {
                printf("Enter node to delete: ");
                scanf("%d", &data);

                root = delete_node(root, data);
            }
            break;
        case 6:
            if (root == NULL)
                printf("Tree is empty.\n\n");
            else
            {
                printf("Enter node to search: ");
                scanf("%d", &data);

                search(root, data);
            }
            break;
        case 7:
            if (root == NULL)
                printf("Tree is empty.\n\n");
            else
                root = find_max(root);
            break;
        case 8:
            if (root == NULL)
                printf("Tree is empty.\n\n");
            else
            {
                temp = find_min(root);
                printf("Minimum = %d\n\n", temp->info);
            }
            break;
        case 9:
            delete_tree(root);

            printf("Tree deleted. Program terminated.\n\n");
            break;
        default:
            printf("Wrong choice.\n\n");
            break;
        }

        system("pause");
    }while (choice != 9);

    return 0;
}

node *insert_node(node *data, int num)
{
    if (data == NULL)
    {
        data = (node *)calloc(1, sizeof(node));
        data->info = num;
        data->left = data->right = NULL;

        printf("\nNode added.\n\n");
    }
    else if (num < data->info)
        data->left = insert_node(data->left, num);
    else if (num > data->info)
        data->right = insert_node(data->right, num);
    else if (num == data->info)
        printf("\nNode already exist.\n\n");

    return data;
}

void pre_order(node *data)
{
    if(data != NULL)
    {
        printf("%d, ",data->info);
        pre_order(data->left);
        pre_order(data->right);
    }
}

void in_order(node *data)
{
    if(data != NULL)
    {
        in_order(data->left);
        printf("%d, ",data->info);
        in_order(data->right);
    }
}

void post_order(node *data)
{
    if(data != NULL)
    {
        post_order(data->left);
        post_order(data->right);
        printf("%d, ",data->info);
    }
}

node *delete_node(node *data, int num)
{
    node *temp;

    if (data == NULL)
        printf("\nNode not found.\n\n");
    else if (num < data->info)
        data->left = delete_node(data->left, num);
    else if (num > data->info)
        data->right = delete_node(data->right, num);
    else if (data->left != NULL && data->right != NULL)
    {
        temp = find_min(data->right);
        data->info = temp->info;
        data->right = delete_node(data->right, data->info);
    }
    else
    {
        temp = data;

        if (data->left == NULL)
            data = data->right;
        else if (data->right == NULL)
            data = data->left;

        free(temp);

        printf("\nNode deleted.\n\n");
    }

    return data;
}

void search(node *data, int num)
{
    if (data == NULL)
        printf("\n%d not found.\n\n", num);
    else if (num == data->info)
        printf("\n%d found.\n\n", num);
    else if (num < data->info)
        search(data->left, num);
    else if (num > data->info)
        search(data->right, num);
}

node *find_max(node *data)
{
    if (data->right == NULL)
        printf("Maximum = %d\n\n", data->info);
    else
        data->right = find_max(data->right);

    return data;
}

node *find_min(node *data)
{
    if (data->left == NULL)
        return data;
    else
        return find_min(data->left);
}

void delete_tree(node *data)
{
    if (data != NULL)
    {
        delete_tree(data->left);
        delete_tree(data->right);
        //printf("%d removed\n",data->info);
        free(data);
    }
}
