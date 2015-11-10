#define MAX 10
typedef struct STACK DATA; 
struct STACK
{
	int arr[MAX];
	int top1;
	int top2;
};


void stack_init(DATA *s);
void stack_push_up(DATA *s, int ar);
void stack_push_down(DATA *s, int ar);
int stack_pop_up(DATA *s);
int stack_pop_down(DATA *s);
