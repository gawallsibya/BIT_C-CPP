//arr.h

typedef struct tagArr Arr;
struct tagArr
{
	Member* data[MAX];
	int ncount;
};

void init_arr(Arr* parr);
void arr_info(Arr* parr);
void arr_insert(Arr* parr, Member *pdata, int idx);
Member* arr_getdata(Arr* parr,int idx);
