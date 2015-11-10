//[����] fgets()�� fputs() �� �̿��� ���� �����
//- fgets()�� �޸� �����÷ο츦 ������ �� �־ getsO ���� ���� ���δ�.
//- test.txt������ ������ ���ڿ��� �о testcopy.txt��� ���Ͽ� �����Ѵ�.

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 10

int main(void)
{
    FILE *in, *out;
    char line[MAXLEN];

    if ((in = fopen("02_�ҽ�.cpp", "r")) == NULL){
        fprintf(stderr, "test.txt => file open failure~!!\n");
        exit(1);
    }

    if ((out = fopen("02_�ҽ�cpy.txt", "w")) == NULL){
        fprintf(stderr, "testcopy.txt => file open failure~!!\n");
        exit(2);
    }

    while (fgets(line, MAXLEN, in) != NULL)
        fputs(line, out);

    fclose(in);
    fclose(out);

    return 0;
}
