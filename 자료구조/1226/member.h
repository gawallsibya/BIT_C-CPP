
typedef struct tagMember Member;
struct tagMember
{
	char phone[20];     //��ȭ
	char number[5];     //�����ȣ
	int count;          //�ż�
	int seat[5];        //�¼���ȣ
};

void mem_print(Member* data);