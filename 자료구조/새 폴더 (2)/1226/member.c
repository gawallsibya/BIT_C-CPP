#include "std.h"
void mem_print(Member* data)
{
	int i;
	
	printf("예약 전화번호 : %s\n",data->phone);
	printf("예약 접수번호 : %s\n",data->number);
	printf("예약 매수     : %d\n",data->count);
	printf("좌석 번호     : ");
	for(i=0; i<data->count; i++)
	printf("%d ",data->seat[i]);
	printf("\n");
}