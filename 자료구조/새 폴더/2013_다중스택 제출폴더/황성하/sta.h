#define MAX 3
/*
typedef struct Stack DATA;
struct Stack
{
	int sta[MAX];
	int top;
};

void stack_init();
void front_push();
void back_push();

void front_pop();
void back_pop();
*/

typedef struct Stack DATA;
struct Stack
{
	int sta[MAX];
	int front;
	int back;
};

void stack_init();
void front_push();
void back_push();

void front_pop();
void back_pop();