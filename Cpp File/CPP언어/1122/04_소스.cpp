//[����] getc()�� putc() �� �̿��� ���� �����
//- test.txt������ ������ ���� ���ڷ� �о testcopy.txt��� ���Ͽ� �����Ѵ�.
// ���� ����

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int ch;
    FILE *in, *out;
	
	// �ؽ�Ʈ ��� + �б��� 
    if ((in = fopen("01_�ҽ�.cpp", "r")) == NULL){
        fprintf(stderr, "test.txt => file open failure~!!\n");
        exit(1);
    }

	// �ؽ�Ʈ ��� + ���� ��� 
    if ((out = fopen("01_�ҽ�copy.txt", "w")) == NULL){
        fprintf(stderr, "testcopy.txt => file open failure~!!\n");
        exit(2);
    }


    while ((ch=getc(in)) != EOF) 
        putc(ch, out);



    fclose(in);

    fclose(out);

    return 0;
}
