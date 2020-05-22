#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct results {
	char subject[20];
	int marks;
};
struct node
{
	struct node *lchild;
	char un[20];
	char pw[20];
	struct node *rchild;
	struct results res[5];
};struct node *t,*s;
struct node *insert(struct node *ptr,char uname[], char pword[]);
struct node *search(struct node *ptr,char uname[], char pword[], char person);
void insertMarks(struct node *student);
void displayMarks(struct node *student);
int main()
{
	struct node *t=NULL,*s=NULL,*ptr;
	char usern[20],passw[20],u[20],p[20];
	int choice;
	printf("--------------Welcome to STUDENT-TEACHER PORTAL!--------------");
	while(1)
	{
		printf("\nAlready a user?\n Press 1 for TEACHER LOGIN \n Press 2 for STUDENT LOGIN\n");
		printf("New user?\n Press 3 for TEACHER SIGN UP \n Press 4 for STUDENT SIGN UP \nPress 5 to exit\n");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1: //TEACHER LOGIN
				printf("Enter Username:\n");
				scanf("%s",&u);
				printf("Enter Password:\n");
				scanf("%s",&p);
				ptr=search(t,u,p, 's');
				if(ptr==NULL)
				{
					printf("User doesn't exist\n");
				} else {
					printf("--------------------------Hi!!! %s, Welcome!--------------------------\n", ptr->un);
					char stud_name[20];
					printf("Please enter the name of the student to enter his marks\n");
					scanf("%s", &stud_name);
					ptr = search(s, stud_name, "", 't');
					if(ptr == NULL) {
						printf("Student doesn't exist\n");
					} else {
						printf("%s exists\n", ptr->un);
						insertMarks(ptr);
					}
				}
				break;
			case 2: //STUDENT LOGIN
				printf("Enter Username:\n");
				scanf("%s",&u);
				printf("Enter Password:\n");
				scanf("%s",&p);
				ptr=search(s,u,p, 's');
				if(ptr==NULL)
				{
					printf("User doesn't exist\n");
				} else {
					printf("--------------------------Hi!!! %s, Welcome!--------------------------\n", ptr->un);
					printf("------------Please find your results------------");
					displayMarks(ptr);
				}
				break;
			case 3:
				printf("Enter Username:\n");
				scanf("%s",&usern);
				printf("Enter Password:\n");
				scanf("%s",&passw);
				t=insert(t,usern,passw);
				break;
			case 4:
				printf("Enter Username:\n");
				scanf("%s",&usern);
				printf("Enter Password:\n");
				scanf("%s",&passw);
				s=insert(s,usern,passw);
				break;
			case 5:
				exit(1);
			default :
				printf("Enter LOGIN OR SIGNUP\n");
				break;
		}
	}
	return 0;
}
struct node *insert(struct node *ptr,char uname[], char pword[])
{
	if(ptr==NULL)
	{
		ptr=(struct node *)malloc(sizeof(struct node));
		strcpy(ptr->un, uname);
		strcpy(ptr->pw, pword);
		ptr->lchild=NULL;
		ptr->rchild=NULL;
	}
	else if(strcmp(uname,ptr->un)==-1)
	{
		ptr->lchild=insert(ptr->lchild,uname,pword);
	}
	else if(strcmp(uname,ptr->un)==1)
	{
		ptr->rchild=insert(ptr->rchild,uname,pword);
	}
	else if(strcmp(uname,ptr->un)==0)
	{
		printf("Username already exists!!! Enter a  new username!\n");
		return ptr;
	}
	return ptr;
}
struct node *search(struct node *ptr,char uname[],char pword[], char person)
{
	if(ptr==NULL)
	{
		return NULL;
	}
	else if(strcmp(uname,ptr->un)==-1)
	{
		return search(ptr->lchild,uname,pword, person);
	}
	else if(strcmp(uname,ptr->un)==1)
	{
		return search(ptr->rchild, uname,pword, person);
	}
	else if(strcmp(uname,ptr->un)==0)
	{
		if(person!='s') //NOT A SELF-LOGIN. IT MEANS TEACHER IS TRYING TO ACCESS STUDENT'S PROFILE
			return ptr;
		else if(strcmp(pword,ptr->pw)==0) //IF A SELF-LOGIN. CHECK FOR PASSWORD TOO.
			return ptr;
		else
			printf("Invalid Password\n");
			return NULL;
	}
	else
		return ptr;
}
void insertMarks(struct node *student)
{
	printf("Enter subject and respective marks of the student\n");
	for(int i=0;i<5;i++)
	{
		printf("Enter subject name:");
		scanf("%s",&student->res[i].subject);
		printf("Enter Marks:");
		scanf("%d",&student->res[i].marks);
	}
	displayMarks(student);
}
void displayMarks(struct node *student)
{
	printf("\nSubject\tMarks\n");
	for(int i=0;i<5;i++)
	{
		printf("%s\t",student->res[i].subject);
		printf("%d\n",student->res[i].marks);
	}
}
