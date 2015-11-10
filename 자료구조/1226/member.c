#include "std.h"
void mem_print(Member* data)
{
	int i;
	
	printf("%s\n",data->phone);
	printf("%s\n",data->number);
	printf("%d\n",data->count);
	for(i=0; i<data->count; i++)
	printf("%d ",data->seat[i]);
}