#include<stdio.h>
#include<malloc.h>
#define MAX 10

char arr[20]={NULL};
int count1=0;
int count2=9;

void init(int _top1,int *_top2);
//1번스택을 위한
void push_front(char *_arr,int *_top1,int *_top2);	//앞에서 부터 채워나간다.
void pop_back(char *_arr,int *_top1,int *_top2);	//뒤에서 부터 지운다.

//2번스택을 위한
char * push_back(char*_arr,int *_top1,int *_top2);	//뒤에서 부터 채워나간다.
void pop_front(char *_arr,int *_top2);	//앞에서 부터 지운다.

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
		printf("\nstack1:	1 ,stack2: 2, 종료: 3	=>");

		fflush(stdin);
		scanf("%d",&num);
		
		switch(num)
		{

			case 1:
		
				printf("1: 입력 , 2: 삭제:");
				fflush(stdin);
				scanf("%d",&num2);
				if(num2==1)
				push_front(arr,&top1,&top2);	//1번스택
				else if(num2==2)
				pop_back(arr,&top1,&top2);		//1번스택
					break;


			case 2:
				printf("1: 입력 , 2: 삭제:");
				fflush(stdin);
				scanf("%d",&num2);
				if(num2==1)
				push_back(arr,&top1,&top2);		//2번스택
				else if(num2==2)
				pop_front(arr,&top2);			//2번스택
				break;
			case 3:
				return;
				break;
			default:
				printf("잘못 입력하셨네요^^\n");
		}
	}
	
}
void init(int *_top1,int *_top2)
{
	*_top1 = -1;
	*_top2 = MAX+1;
}
//1번스택
void push_front(char *_arr,int *_top1,int *_top2)
{
	int i;
	char ch;

	printf("저장할 문자를 입력하세요(문자입력을 끝낼때는 엔터):\n");
		
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
			printf("스택 1의 [%d]번째 ",*_top1);
			if(overf(*_top1,*_top2)==1) return ;
			printf(" 문자: %c\n",_arr[i]);
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
			printf("스택 1의 [%d]번째 ",i);
			printf("삭제되는 문자: %c\n",_arr[i]);
			arr[i]=NULL;			
		}
			
		
	}
}

//2번스택
char * push_back(char *_arr,int *_top1,int *_top2)
{
	int i=0,j=0;
	char ch=0;
	printf("저장할 문자를 입력하세요(문자입력을 끝낼때는 엔터):");
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
			printf("스택 2의 [%d]번째 ",*_top2);
			printf(" 문자: %c\n",_arr[i]);
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
			printf("스택 2의 [%d]번째 ",i);
			printf("삭제되는 문자: %c\n",_arr[i]);
			_arr[i]=NULL;

		}
	}
}

//1번스택
int overf(int _top1,int _top2)
{
	if((_top1 >= _top2)==1)
	{
		printf("에서overflow입니당.\n");
		return 1;
	}
	
	else
	return 0;
}

int underf1(int _top)
{
		if(_top < 0)
			{
				printf("underflow입니당.\n");
				return 1;
			}
		else
		return 0;
}
//2번스택
int underf2(int _top)
{
	if(_top>=MAX)
	{
		printf("underflow입니당\n");
		return 1;
	}
	else
	return 0;
}

