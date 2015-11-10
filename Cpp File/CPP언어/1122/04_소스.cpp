//[예제] getc()와 putc() 를 이용한 파일 입출력
//- test.txt파일의 내용을 단일 문자로 읽어서 testcopy.txt라는 파일에 복사한다.
// 문자 전용

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int ch;
    FILE *in, *out;
	
	// 텍스트 모드 + 읽기모드 
    if ((in = fopen("01_소스.cpp", "r")) == NULL){
        fprintf(stderr, "test.txt => file open failure~!!\n");
        exit(1);
    }

	// 텍스트 모드 + 쓰기 모드 
    if ((out = fopen("01_소스copy.txt", "w")) == NULL){
        fprintf(stderr, "testcopy.txt => file open failure~!!\n");
        exit(2);
    }


    while ((ch=getc(in)) != EOF) 
        putc(ch, out);



    fclose(in);

    fclose(out);

    return 0;
}
