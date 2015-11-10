#define MAX 5

typedef struct STACK Stack;
struct STACK
{
	int arr[MAX];
	int start;
	int end;
};

void stack_init();
void stack1_push();
void stack1_pop();
void stack2_push();
void stack2_pop();
void stack_now();
void start_printall();
void end_printall();
void stack1_now();
void stack2_now();
