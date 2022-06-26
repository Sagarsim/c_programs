#include<stdlib.h>
#include<stdio.h>

struct node
{
    int data;
    struct node* link;
};
struct node* head;
int insert_at_end();
void insert_at_beginning();
void middle();
void remove_first();
void remove_middle();
void printlist();
void findmid();
void main()
{
    int n,i,ch,ch2;
    head=NULL;
    printf("How many elements you want to enter:");
    scanf("%d",&n);
    x:
    printf("\n\t\t\tCHOICES:\n\t1-Enter at the end ...");
    printf("\n\t2-Enter at the beginning...");
    scanf("%d",&ch);
    switch(ch)
    {

    case 1:
    {
    for(i=1;i<=n;i++)
    {
        insert_at_end();
        printlist();
    }
	
    break;
    }

    case 2:
    {
    for(i=1;i<=n;i++)
    {
        insert_at_beginning();
        printlist();
    }
    break;
    }

    default:
        {
            printf("\n\tEnter valid choice...");
            goto x;
        }
    }
    y:
    printf("\n\t\t\tADD OR DELETE ELEMENT FROM THE LIST:-\n\t1-Add an element before any element....");
    printf("\n\t2-Add an element at the beginning....");
    printf("\n\t3-Add an element at the end....");
    printf("\n\t4-Delete an element anywhere in the middle of the list....");
    printf("\n\t5-Delete first element....");
	printf("\n\t6-Find middle element of linked list...");
    printf("\n\t7-End program....");
    
    scanf("%d",&ch2);
    switch(ch2)
    {
    	case 1:
    		{
    			middle();
    			printlist();
    			goto y;
			}
		case 2:
			{
				insert_at_beginning();
				printlist();
				printf("\nElement added successfully...");
				goto y;
			}
		case 3:
		{
           insert_at_end();
		   printlist();	
		   printf("\nElement added successfully...");
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
				findmid();
				goto y;
			} 
		case 7:
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
void insert_at_beginning()
{
   struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\n Enter elements:");
    scanf("%d",&newnode->data);
    newnode->link=head;
    head=newnode;
    
}
int insert_at_end()
{
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\n Enter elements:");
    scanf("%d",&newnode->data);
    newnode->link=NULL;
     if(head==NULL)
    {
        head=newnode;
        return 1;
    }
    else
    {
        temp=head;
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=newnode;
    }
}
void printlist()
{
struct node *temp;
printf("\nList is:");
    for(temp=head;temp!=NULL;temp=temp->link)
    {
        printf("\t%d",temp->data);
    }
}
void middle()
{int x;
	struct node *temp,*tempprev;
	tempprev=NULL;
	printf("\nEnter element from list before which you want to enter new element:");
	scanf("%d",&x);
	for(temp=head;temp!=NULL;temp=temp->link)
	{
		if(temp->data==x)
		{
			printf("\nElement found....");
			struct node* newnode=(struct node*)malloc(sizeof(struct node));
			printf("\nEnter element in newnode:");
			scanf("%d",&newnode->data);
			newnode->link=temp;
			tempprev->link=newnode;
			printf("\nElement added successfully...");
			break;
		}
		else
		{
			tempprev=temp;
			printf("\nSearching....");
			
		}
		
	}
}

void findmid(){
	struct node *temp, *tempprev;
	tempprev = head;
	temp = head;
	while(temp!=NULL){
			temp=temp->link;
		if(temp!=NULL){
			temp=temp->link;
			tempprev = tempprev->link;
			}
	}
		printf("Middle Element:\t%d", tempprev->data);
}
void remove_first()
{
	struct node* temp;
	temp=head;
	head=head->link;
	free(temp);
	printf("Element deleted successfully...");
}
void remove_middle()
{
	int x;
	struct node *temp,*tempprev;
	tempprev=NULL;
	printf("\nEnter element you want to delete:");
	scanf("%d",&x);
	temp=head;
	while(temp!=NULL)
	{
		if(temp->data==x)
		{   printf("\nElement found...");
			tempprev->link=temp->link;
			free(temp);
			printf("\nElement deleted successfully...");
			break;
		}
		else
		{
			printf("\nSearching...");
			tempprev=temp;
			temp=temp->link;
		}
	}
}
