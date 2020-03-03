#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct linklist
{
    int data;
    struct node *next;
}Node;
int count =0    ;
void display(Node *);
 void insertbeg(Node **  );
 void insertAfter(Node **,int );
 void Deletionnum(Node ** );
 void insertEnd(Node **);
int main()
{
    Node *node,*head=NULL,*ptr;
    int co,count=0;
    printf("Enter Number of nodes to be created : ");
    scanf("%d",&co);
    while(co>0)
    {
        node = (Node*)malloc(sizeof(Node));
        printf("\nEnter the element : ");
        scanf("%d",&node->data);
        node->next=NULL;
        if(head==NULL)
        {
            head=node;
            co--;
        }
        else
        {
            ptr=head;
            while(ptr->next!=NULL)
                ptr=ptr->next;
            ptr->next=node;
            co--;
        }
    }

    display(head);
   //Insertion At the Beginning
   printf("\n\t\tElement inserted at beginning\n");
   insertbeg(&head);
   display(head);
   int d;
    //Insertion After  a particular number
    printf("\n\t\tInsertion After  a particular number\n");
    printf("\nEnter after which number a new number to be added : ");
    scanf("%d",&d);
    insertAfter(&head,d);
    printf("\n\tList after insertion of number After a particular number \n");
    display(head);
    //Deletion of element
    printf("\n\t\tDeletion of Element Entered by the User\n");
    Deletionnum(&head);
    printf("\n\tList after Deletion\n");
    display(head);
    //Addition At the end
    printf("\n\t\tAddition of the element at the end\n");
    insertEnd(&head);
    printf("\n\tList after Addition\n");
    display(head);
    printf("\n\t\t-------X----------X--------\n");
}
void insertbeg(Node **temp)
{
    Node * node =(Node *)malloc(sizeof(Node));
    printf("\n\nEnter number to be inserted at the beginning : ");
    scanf("%d",&node->data);
    node->next=*temp;
    *temp=node;
}
void insertAfter(Node **temp,int b)
{
    Node *node=(Node *)malloc(sizeof(Node));
    printf("\n\t\tEnter a number to be inserted : ");
    scanf("%d",&node->data);
    Node*ptr;
    ptr=*temp;
    int flag=0;
    while(ptr->next!=NULL  &&  ptr->data!=b)
    {
        flag=1;
        ptr=ptr->next;
    }
    if(flag==0)
        printf("\n\t Number Not Found !");
    else
    {
        node->next=ptr->next;
    ptr->next=node;
    }
}
void Deletionnum(Node **temp)
{
    int n;
    Node *node=(Node *)malloc(sizeof(Node));
    printf("\nEnter Number to be Deleted from the list : ");
    scanf("%d",&n);
    Node *ptr;
    ptr=*temp;
    Node *pre;
   int flag=0;
    while(ptr->next!=NULL && ptr->data!=n)
    {flag=1;
        pre=ptr;
        ptr=ptr->next;
    }
    if(flag==0)
        printf("\n\tNumber Not Found !");
    else
       pre->next=ptr->next;

}
void insertEnd(Node **temp)
{
    Node *node =(Node*)malloc(sizeof(Node));
    printf("\n\tEnter A number to be Inserted At the end :");
    scanf("%d",&node->data);
    Node *ptr=*temp;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=node;
    node->next=NULL;
}
void display(Node *ptr)
{
    count = 0;
    printf("\nLIST : ");
    while(ptr!=NULL)
    {
        printf("%d  ",ptr->data);
        count++;
        ptr=ptr->next;
    }
    printf("\nNumber of Nodes : %d\n",count);
}
