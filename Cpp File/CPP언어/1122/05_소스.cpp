//[예제] fgets()와 fputs() 를 이용한 파일 입출력
//- fgets()는 메모리 오버플로우를 방지할 수 있어서 getsO 보다 자주 쓰인다.
//- test.txt파일의 내용을 문자열로 읽어서 testcopy.txt라는 파일에 복사한다.

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 10

int main(void)
{
    FILE *in, *out;
    char line[MAXLEN];

    if ((in = fopen("02_소스.cpp", "r")) == NULL){
        fprintf(stderr, "test.txt => file open failure~!!\n");
        exit(1);
    }

    if ((out = fopen("02_소스cpy.txt", "w")) == NULL){
        fprintf(stderr, "testcopy.txt => file open failure~!!\n");
        exit(2);
    }

    while (fgets(line, MAXLEN, in) != NULL)
        fputs(line, out);

    fclose(in);
    fclose(out);

    return 0;
}
