#include<stdio.h>
#include<stdlib.h>
typedef struct linklist
{
    int data;
    struct node *next;
}Node;
Node *creatlist(Node *,int );
void Display(Node *);
int main()
{

    printf("\nEnter Elements For List 1\n");
    Node *head1=creatlist(NULL,6);
    printf("\nEnter Elements For List 2\n");
    Node *head2=creatlist(NULL,6);
    Node*head3=NULL;
    Node *ptr1=head1,*ptr2=head2,*ptr,*pt;
    printf("List 1\n\n");
    Display(head1);
    printf("\nList 2\n\n");
    Display(head2);
    while(ptr1!=NULL && ptr2!=NULL)
    {
      ptr=ptr1->next;
        pt=ptr2->next;
      ptr1->next=ptr2;


      ptr2->next=ptr;

      ptr1=ptr;
      ptr2=pt;
    }
    printf("\nFinal List\n\n");
    Display(head1);
}
Node  *creatlist(Node *head,int co)
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
Display(Node *head)
{
    Node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
