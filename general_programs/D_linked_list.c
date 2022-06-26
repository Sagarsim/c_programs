#include<stdlib.h>
#include<stdio.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* head;
void insert_beg();
void insert_end();
void insert_middle();
void remove_middle();
void remove_first();
void remove_last();
void printlist();
void print_rev();

void main()
{
    head=NULL;

    int n,i,ch,ch1;
    printf("\nNo. of elements you want to enter:-");
    scanf("%d",&n);
    x:
    printf("\t\t\nCHOICES:-\n1-Enter at the end...");
    printf("\n2-Enter at the beginning...");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        {
            for(i=1;i<=n;i++)
            {
                insert_end();
                printlist();
            }
            break;
        }
    case 2:
        {
            for(i=1;i<=n;i++)
            {
                insert_beg();
                printlist();
            }
            break;
        }
    default:
        {
            printf("\nEnter valid choice...\n\n");
            goto x;
        }
    }
    y:
    printf("\n\t\t\tADD OR DELETE ELEMENT FROM THE LIST:-\n\t1-Add an element before any element....");
    printf("\n\t2-Add an element at the beginning....");
    printf("\n\t3-Add an element at the end....");
    printf("\n\t4-Delete an element anywhere in the middle of the list....");
    printf("\n\t5-Delete first element....");
    printf("\n\t6-Delete last element...");
    printf("\n\t7-Print list in reverse...");
    printf("\n\t8-End program....");
    scanf("%d",&ch1);
    switch(ch1)
    {
    	case 1:
    		{
    			insert_middle();
    			printlist();
    			goto y;
			}
		case 2:
			{
				insert_beg();
				printlist();
				goto y;
			}
		case 3:
		{
           insert_end();
		   printlist();
		   goto y;
		}
		case 4:
			{
				remove_middle();
				printlist();
				goto y;
			}
		case 5:
			{
				remove_first();
				printlist();
				goto y;
			}

		case 6:
            {
               remove_last();
               printlist();
               goto y;
            }
        case 7:
            {
                print_rev();
                goto y;
            }
        case 8:
            {
                break;
            }
		default:
			{
				printf("\nEnter valid choice...");
				goto y;
			}
	}
   
    }

void insert_beg()
{
 struct node* newnode=(struct node*)malloc(sizeof(struct node));
 printf("\nEnter element:-");
 scanf("%d",&newnode->data);
  newnode->next=NULL;
 newnode->prev=NULL;
 if(head==NULL)
 {
     head=newnode;
     return;
 }
 head->prev=newnode;
 newnode->next=head;
head=newnode;
head->prev=NULL;

}
void insert_end()
{struct node* temp=head;
struct node* newnode=(struct node*)malloc(sizeof(struct node));
 printf("\nEnter element:-");
 scanf("%d",&newnode->data);
  newnode->next=NULL;
 newnode->prev=NULL;
 if(temp==NULL)
 {
     head=newnode;
     return;
 }
 while(temp->next!=NULL)
 {
     temp=temp->next;
 }
 temp->next=newnode;
 newnode->prev=temp;
}
void insert_middle()
{   struct node* temp=head;
    int s;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
  newnode->next=NULL;
 newnode->prev=NULL;
 printf("\nEnter new element before:-");
 scanf("%d",&s);
 while(temp!=NULL)
 {
     if(temp->data==s)
     {
         printf("\nElement found...");
         printf("\nEnter element in newnode:-");
         scanf("%d",&newnode->data);
         temp->prev->next=newnode;
         newnode->prev=temp->prev;
         newnode->next=temp;
         temp->prev=newnode;
         printf("\nElement added successfully...");
         break;
    }
    else
    {
        printf("\nSearching...");
        temp=temp->next;
    }
 }
}
void remove_middle()
{
    int s;
    struct node* temp=head;
    printf("\nEnter element you want to remove...");
    scanf("%d",&s);
    while(temp!=NULL)
    {
        if(temp->data==s)
        {
            printf("\nElement found...");
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free(temp);
            printf("\nElement deleted successfully...");
            break;
        }
        else
        {
            printf("\nSearching...");
            temp=temp->next;
        }
    }
}
void remove_first()
{
    struct node* temp=head;
    head=head->next;
    free(temp);
}
void printlist()
{printf("\nList is:-");
    struct node* temp;
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        printf("\t%d",temp->data);
    }
}
void remove_last()
{
    struct node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;

    }
    temp->prev->next=NULL;
    temp->prev=NULL;
    temp->next=NULL;
    free(temp);

}
void print_rev()
{   printf("\nList is:-");
    struct node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    while(temp!=NULL)
    {
        printf("\t%d",temp->data);
        temp=temp->prev;
    }
}


