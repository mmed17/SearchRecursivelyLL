#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct list
{
    int data;
    struct list *next;
}list;
typedef struct info
{
    int element;
    bool found;
}binary;
list * define(int value)
{
    list *node=(list*)malloc(sizeof(list));
    node->data=value;
    node->next=NULL;
    return node;
}
list * insert(list *head,int value)
{
    if(head==NULL)  return define(value);
    head->next=insert(head->next,value);
    return head;
}
list * input(list *head)
{
    int i=1,value;
    do
    {
        printf("input the element %d : ",i++);
        scanf("%d",&value);
        if(value!=0)
            head=insert(head,value);
    }while(value!=0);
     return head;
}
void printl(list *head)
{
    if(head)
        while(head!=NULL)
        {
            printf("%d\t",head->data);
            head=head->next;
        }
    else
        printf("the list is empty!!");
    printf("\n");
}
list * find_mid(list *head,list *last)
{
    if(head==NULL)  return NULL;
    list *slow=head;
    list *fast=head->next;
    if(fast==last)  return head;
    while(fast!=last)
    {
        fast=fast->next;
        if(fast!=last)
        {
            fast=fast->next;
            slow=slow->next;
        }
    }
    return slow;
}
binary * binary_search(list *head,list *last,binary *temp)
{
     list *mid=find_mid(head,last);
    if(last != head)
    {
        if(mid->data < temp->element)
            head=mid->next;
        else if(mid->data > temp->element)
            last=mid;
        else
        {
            temp->found=true;
            return temp;
        }
        return binary_search(head,last,temp);
    }
    return temp;
}
int main()
{
    list *head=NULL,*last=NULL;
    printf("input the elements of the list <input 0 to stop>:\n");
    head=input(head);
    printf("the elements of the list:\n");
    printl(head);

    binary *temp=(binary*)malloc(sizeof(binary));
    temp->found=false;

    printf("input a value:\n");
    scanf("%d",&temp->element);

    temp=binary_search(head,last,temp);
    if(temp->found)
        printf("found");
    else
        printf("not found");
    return 0;
}
