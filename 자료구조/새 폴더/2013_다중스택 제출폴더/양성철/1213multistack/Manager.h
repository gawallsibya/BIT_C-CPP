
typedef struct tagstack STACK;
struct tagstack
{
	int top1;
	int top2;
	int stack[MAX];
};

void init_stack();

void top1_push_stack();
void top1_pop_stack();

void top2_push_stack();
void top2_pop_stack();
void stack_printall();





