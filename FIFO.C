#include<stdio.h>
#include<conio.h>
#define MAX 3
int queue[MAX];
int front=-1;
int rear=-1;
void einsert(int a);
void edelete();
void printArray();
int checkexistence(int b);

void main()
{
	clrscr();
	for(int k=0;k<MAX;++k)
	{
		queue[k]=-1;
	}
	int a[20];
	float n,hit=0.0,miss=0.0;
	printf("Enter number of pages\n");
	scanf("%f",&n);
	printf("Enter page sequence\n");
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	printf("\n");
	printf("-1 represents empty space\n");
	for(i=0;i<n;++i)
	{
		int x;
		x=checkexistence(a[i]);
		if(x==0)
		{
			if(rear==MAX-1 && front!=0)
			{
				einsert(a[i]);
			}
			else if(rear!=MAX-1)
			{
				einsert(a[i]);
			}
			else if(rear==MAX-1 && front==0)
			{
				edelete();
				einsert(a[i]);
			}
			printArray();
			printf("Miss\n");
			miss++;
		}
		else if(x==1)
		{
			printArray();
			printf("Hit\n");
			hit++;
		}

	}
	float missratio= miss/n;
	float hitratio= hit/n;
	printf("\nNumber of miss : %.f\tNumber of hit : %.f\n",miss,hit);
	printf("\nMISS RATIO : %.4f\tHit Ratio : %.4f\n",missratio,hitratio);
	getch();
}

void printArray()
{
	for(int i=0;i<MAX;++i)
	{
		printf("%d\t",queue[i]);
	}
}

void einsert(int a)
{
	if(front==0 && rear==MAX-1)
	{
		printf("Circular Queue Overflow\n");
	}
	else if(rear==MAX-1 && front!=0)
	{
		rear=0;
		queue[rear]=a;
	}
	else if(rear==-1 && front==-1)
	{
		front=rear=0;
		queue[rear]=a;
	}
	else
	{
		rear++;
		queue[rear]=a;
	}
}

void edelete()
{
	if(front==-1 && rear==-1)
	{
		printf("Circular Queue Underflow\n");
	}
	if(front==rear)
	{
		front=rear=-1;
	}
	else
	{
		if(front==MAX-1)
		{
			front=0;
		}
		else
		{
			front++;
		}
	}
}

int checkexistence(int a)
{
	int val;
	for(int i=0;i<MAX;++i)
	{
		if(a==queue[i])
		{
			val=1;
			break;
		}
		else
		{
			val=0;
		}
	}
	return val;
}