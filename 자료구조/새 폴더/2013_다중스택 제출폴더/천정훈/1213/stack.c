#include<stdio.h>
#include<malloc.h>
#define MAX 10

char arr[20]={NULL};
int count1=0;
int count2=9;

void init(int _top1,int *_top2);
//1�������� ����
void push_front(char *_arr,int *_top1,int *_top2);	//�տ��� ���� ä��������.
void pop_back(char *_arr,int *_top1,int *_top2);	//�ڿ��� ���� �����.

//2�������� ����
char * push_back(char*_arr,int *_top1,int *_top2);	//�ڿ��� ���� ä��������.
void pop_front(char *_arr,int *_top2);	//�տ��� ���� �����.

int overf(int _top1,int _top2);

int underf2(int _top);
int underf1(int _top);

void main()
{
	int top1 =0;
	int top2 =0;
	int num,num2;
	
	init(&top1,&top2);
	
	while(1)
	{
		printf("\nstack1:	1 ,stack2: 2, ����: 3	=>");

		fflush(stdin);
		scanf("%d",&num);
		
		switch(num)
		{

			case 1:
		
				printf("1: �Է� , 2: ����:");
				fflush(stdin);
				scanf("%d",&num2);
				if(num2==1)
				push_front(arr,&top1,&top2);	//1������
				else if(num2==2)
				pop_back(arr,&top1,&top2);		//1������
					break;


			case 2:
				printf("1: �Է� , 2: ����:");
				fflush(stdin);
				scanf("%d",&num2);
				if(num2==1)
				push_back(arr,&top1,&top2);		//2������
				else if(num2==2)
				pop_front(arr,&top2);			//2������
				break;
			case 3:
				return;
				break;
			default:
				printf("�߸� �Է��ϼ̳׿�^^\n");
		}
	}
	
}
void init(int *_top1,int *_top2)
{
	*_top1 = -1;
	*_top2 = MAX+1;
}
//1������
void push_front(char *_arr,int *_top1,int *_top2)
{
	int i;
	char ch;

	printf("������ ���ڸ� �Է��ϼ���(�����Է��� �������� ����):\n");
		
	fflush(stdin);
//	gets(arr);

	for(i=count1;i<MAX;i++)
	{
		fflush(stdin);
		scanf("%c",&ch);
		arr[i]=ch;

		if(arr[i]=='\n') 
		{		
			arr[i] = NULL;
			count1 -=1;
			break;
		}
		else
		{
			count1 ++;
//			printf("%c\n",arr[i]);

		}
		
	}
	for(i=0;i<MAX+2;i++)
	{
		if(_arr[i]!=NULL) 
		{
			*_top1 = i;
			printf("���� 1�� [%d]��° ",*_top1);
			if(overf(*_top1,*_top2)==1) return ;
			printf(" ����: %c\n",_arr[i]);
		}
		else
		{return;}
		
	}
}
void pop_back(char *_arr,int *_top1,int *_top2)
{
	int i;

	for(i=*_top1;i>-2;i--)
	{
		*_top1 = i;
		count1 = 0;
		if(underf1(i)==1)	{count1 = 0;return ;}

		if(_arr[i]!=NULL) 
		{
			printf("���� 1�� [%d]��° ",i);
			printf("�����Ǵ� ����: %c\n",_arr[i]);
			arr[i]=NULL;			
		}
			
		
	}
}

//2������
char * push_back(char *_arr,int *_top1,int *_top2)
{
	int i=0,j=0;
	char ch=0;
	printf("������ ���ڸ� �Է��ϼ���(�����Է��� �������� ����):");
	fflush(stdin);
		
	fflush(stdin);
//	gets(arr);
	for(i=count2;i>-1;i--)
	{
		fflush(stdin);
		scanf("%c",&ch);
		arr[i]=ch;

		if(arr[i]=='\n') 
		{		
			arr[i] = NULL;
			count2 +=1;
			break;
		}
		else
		{
			count2 --;
//			printf("%c\n",arr[i]);

		}
		
	}
	for(i=MAX-1;i>=count2;i--)
	{		
		if(_arr[i]!= NULL) 
		{
			*_top2 = i;
			fflush(stdin);
			printf("���� 2�� [%d]��° ",*_top2);
			printf(" ����: %c\n",_arr[i]);
				if(overf(*_top1,*_top2)==1) return ;
				
	
		}
		else
		{return;}
		
	}
	return _arr;
}
void pop_front(char *_arr,int *_top2)
{
	int i;
	for(i=*_top2;i<MAX+1;i++)
	{
		*_top2 = i;
		if(underf2(i)==1)	{ count2 = MAX; return ;}

		if(_arr[i]!=NULL) 
		{
			printf("���� 2�� [%d]��° ",i);
			printf("�����Ǵ� ����: %c\n",_arr[i]);
			_arr[i]=NULL;

		}
	}
}

//1������
int overf(int _top1,int _top2)
{
	if((_top1 >= _top2)==1)
	{
		printf("����overflow�Դϴ�.\n");
		return 1;
	}
	
	else
	return 0;
}

int underf1(int _top)
{
		if(_top < 0)
			{
				printf("underflow�Դϴ�.\n");
				return 1;
			}
		else
		return 0;
}
//2������
int underf2(int _top)
{
	if(_top>=MAX)
	{
		printf("underflow�Դϴ�\n");
		return 1;
	}
	else
	return 0;
}

