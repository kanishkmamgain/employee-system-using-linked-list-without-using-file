/*
Create the record
delete the record
search a record
find the number of employees

attributes should contain:
a. EMPLOYEE
1. Employee number
2. year of joining
3. name
4. father name
5. address (pincode, town, city)

*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

struct address
{
    int pin;
    char city[30];
    char town[30];
    struct address *next1;
};
struct address *start1 = NULL;

struct employee
{
    char empid[10];
    char name[20];
    char father[20];
    char designation[40];//clerk, officer, multitasking
    int year;
    struct employee *next;
    struct address add;
};
struct employee *start = NULL;

void insert();
void del();
void update();
void display();
void search();

int main()
{
    //struct employee *start;
    int i;
    while(1)
    {
        printf ("Enter the number corresponding to the option you want to enter\n\n");
        printf ("\n1. insert\n2. display\n3. delete\n4. update\n5. search\n6. Nothing to do\n");
        scanf("%d", &i);
        switch(i)
            {
                case 1:	insert();
                        break;
                case 2: display(start);
                        break;
                case 3: del();
                        break;
                case 4: update(start);
                        break;
                case 5:	search(start);
                        break;
                case 6: exit(1);
                default: printf("Invalid Choice\n");
            }
    }
}

void insert()
{
    //struct employee *start=NULL;
    struct employee *temp=(struct employee*)malloc(sizeof(struct employee));
	printf("Enter Employee id: ");
	scanf("%s",&temp->empid);
	printf("Enter Name: ");
	scanf("%s",&temp->name);
	printf("Enter father's name: ");
	scanf("%s",&temp->father);
	printf("Enter designation: ");
	scanf("%s",&temp->designation);
	printf ("Enter the year of joining:");
	scanf ("%d",&temp->year);
	printf ("Enter the pin code of the address of employee:");
	scanf ("%d", &temp->add.pin);
	printf ("Enter the city:");
	scanf ("%s", &temp->add.city);
	temp->next=NULL;
	if(start==NULL)
    {
		start=temp;
	}
	else
	{
		temp->next=start;
		start=temp;
	}
}

void display(struct employee *p)
{
    p=start;
	printf("\nEmployee id\t\tName\t\tFather name\t\tDesignation\t\tYear\t\tAddress\n");
	while(p)
    {
		printf("%10s	%12s	%12s	%20s    %20d  %10d,%s\n",p->empid,p->name,p->father,p->designation,p->year,p->add.pin,p->add.city);
		p=p->next;
	}
}

void del(struct employee *p)
{
	struct employee *q ; //*start;
	p=start;
	q=p;
	char id[10];
	if(p==NULL)
	{
		printf("\n No record found!!");
		return;
	}
	printf("\nEnter employee id for which record has to be deleted- ");
	scanf("%s",&id);
	if(strcmp(id,p->empid)==0)
	{
		start=start->next;
		free(p);
		printf("\n Record Deleted !!");
	}
	else
    {
		while(strcmp(id,p->empid)!=0)
		{
			q=p;
			p=p->next;
			if(!p)
			{
				printf("No record Found for the given employee id");
				return;
			}
		}
		q->next=p->next;
		free(p);
		printf("\n Record Deleted !!");
	}
}

void update(struct employee *p)
{
	char id[10];
	printf("\n Enter employee id of the person whose information needs to be updated :");
	scanf("%s",&id);
	while(p)
    {
		if(strcmp(id,p->empid)==0)
		{
			printf("Enter new employee id: ");
			scanf("%s",&p->empid);
			printf("Enter new Name: ");
			scanf("%s",&p->name);
			printf("Enter father name: ");
			scanf("%s",&p->father);
			printf("Enter designation : ");
			scanf("%s",&p->designation);
            printf ("Enter the pin code of the address of employee:");
            scanf ("%d", &p->add.pin);
            printf ("Enter the city:");
            scanf ("%s", &p->add.city);
			return;
		}
		p=p->next;
	}
	printf("No records Found");
}

void search(struct employee *p)
{
	char id[10],des[20];
	int x;
	printf ("Enter in what way you want to search the record\n");
	printf ("1. By id \n2. By designation\n");
	scanf ("%d",&x);
	if(x==1)
    {
        printf("\n Enter the employee id to be searched :");
        scanf("%s",&id);
        while(p)
        {
            if(strcmp(id,p->empid)==0)
            {
                printf("Record Found!!\n\n");
                printf("\nEmployee id\t\tName\t\tFather name\t\tDesignation\t\tYear\t\tAddress\n");
                printf("%10s	%12s	%12s	%20s    %20d  %20d,%s\n",p->empid,p->name,p->father,p->designation,p->year,p->add.pin,p->add.city);
                return;
            }
            p=p->next;
        }
    }
    else if(x==2)
    {
        printf ("Enter the designation you want to search for:\n");
        scanf ("%s",&des);
        while(p)
        {
            if(strcmp(des,p->designation)==0)
            {
                printf("Record Found!!\n\n");
                printf("\nEmployee id\t\tName\t\tFather name\t\tDesignation\t\tYear\t\tAddress\n");
                printf("%10s	%12s	%12s	%20s    %20d  %20d,%s\n\n\n",p->empid,p->name,p->father,p->designation,p->year,p->add.pin,p->add.city);
            }
            p=p->next;
        }
	return;
    }
	printf("No record found!!\n\n");
}
