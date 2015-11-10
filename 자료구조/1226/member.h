
typedef struct tagMember Member;
struct tagMember
{
	char phone[20];     //전화
	char number[5];     //예약번호
	int count;          //매수
	int seat[5];        //좌석번호
};

void mem_print(Member* data);