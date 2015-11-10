
#define MAX 5
typedef struct tagstack Stack;
struct tagstack
{
	int arr[MAX];
	int top1;
	int top2;
};


void stack_init(Stack* a);
void Upstack_push_front(Stack* a,int num);
int Upstack_pop_front(Stack* a);

void Downstack_push_front(Stack* a,int num);
int Downstack_pop_front(Stack* a);

void stack_state(Stack* a);


