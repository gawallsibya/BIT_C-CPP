#include "std.h"
void mem_print(Member* data)
{
	int i;
	
	printf("���� ��ȭ��ȣ : %s\n",data->phone);
	printf("���� ������ȣ : %s\n",data->number);
	printf("���� �ż�     : %d\n",data->count);
	printf("�¼� ��ȣ     : ");
	for(i=0; i<data->count; i++)
	printf("%d ",data->seat[i]);
	printf("\n");
}