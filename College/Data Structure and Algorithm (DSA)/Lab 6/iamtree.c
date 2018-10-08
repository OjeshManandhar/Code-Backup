#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct bst
{
    struct bst *left;
    int data;
   struct bst *right;

};
typedef struct bst node;
node *insert(node*,int);
void preorder(node*);
void inorder(node*);
void postorder(node*);
void search(node*,int);
void main()
{
 int n,num;
 node *root=NULL,*temp;
 do
 {
     printf("\n 1.Create a Binary Search Tree ");
     printf("\n 2.Preorder traverse ");
     printf("\n 3.inorder traverse ");
     printf("\n 4.post order traverse ");
     printf("\n 5.Search a node value ");
     printf("\n 6.exit ");
     printf("\n Enter your choice");
     scanf("%d",&n);
     switch(n)
     {
         case 1:
         printf("Enter the data");
         scanf("%d",&num);
         root = insert(root,num);
         break;
         case 2:
         if(root==NULL)
         printf("The tree is empty");
         else
         preorder(root);
         getch();
         break;
         case 3:
         if(root=NULL)
         printf("tree is empty");
         else
         inorder(root);
         getch();
         break;
         case 4:
         if(root==NULL)
         printf("Tree is empty");
         else
         preorder(root);
         getch();
         break;
         case 5:
         printf("Enter the number to be searched");
         scanf("%d",&num);
         search(root,num);
         break;
         case 6:
         printf("Press any key to exit");
         getch();
         exit(1);
     }


}while(n!=6);

 }

node *insert(node *r,int num)
{
    if(r==NULL)
    {
        r=(node*)malloc(sizeof(node));
        r->data=num;
        r->left=r->right=NULL;
    }
    else if(num < r->data)
    r->left =insert(r->left,num);
    else if(num >r->data)
    r->right =insert(r->right,num);
    else if(num==r->data)
    printf("\n the node a;ready exists");
}
void preorder(node *root)
{
    if(root!=NULL)
    {
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);

    }
}
void inorder(node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);

    }
}
void postorder(node *root)
{

  if(root!=NULL)
  {
      postorder(root->left);
      postorder(root->right);
      printf("%d",root->data);


  }
}
void search(node *root,int num)
{
    if(root==NULL)
    {
        printf("SEARACH unsceuseefukl");
        getch();
        return;
    }
    else if(num==root->data)
    {
        printf("SEARCH sucessful number %d is found \n",num);
        getch();
        return;
    }
    else if(num<root->data)
    search(root->left,num);
    else
    search(root->right, num);
}
