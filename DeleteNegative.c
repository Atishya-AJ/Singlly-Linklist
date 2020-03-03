
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct linklist
{
    int data;
    struct node *next;
}Node;
int creatlist(Node *,int );
void Deletionnum(Node ** ,int );
void Display(Node *);
int main()
{
 int c;
 printf("Number of elements to be inputed : ");
 scanf("%d",&c);
 printf("\n\t\t\tEnter Positive and Negative Numbers\n ");
 Node *head1=creatlist(NULL,c);
 Node *p=head1;
 printf("\nList\n");
 Display(head1);
 while(p!=NULL)
 {
     if(p->data<0)
        Deletionnum(&head1,p->data);
      p=p->next;
 }
 printf("\nList After Deleting Negative Numbers\n");
 Display(head1);
}
int creatlist(Node *head,int co)
{
    Node * ptr=head;
while(co>0)
    {
       Node* node = (Node*)malloc(sizeof(Node));
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
    return head;
}
void Deletionnum(Node **temp,int n)
{

    Node *node=(Node *)malloc(sizeof(Node));

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
Display(Node *head)
{
    Node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
