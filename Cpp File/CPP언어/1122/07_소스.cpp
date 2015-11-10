#include <iostream>
using namespace std;

//02_소스cpy.txt

//SEEK_SET  처음
//SEEK_CUR  현재위치
//SEEK_END  파일의 끝
//int fseek(FILE * stream, long offset, int startpos);
//long ftell(FILE * stream);

/*
void main()
{
	int ch;
    FILE *in;
	
	// 텍스트 모드 + 읽기모드 
    if ((in = fopen("02_소스cpy.txt", "r")) == NULL){
        fprintf(stderr, "test.txt => file open failure~!!\n");
        exit(1);
    }

	fseek(in, -2, SEEK_END);		// EOF
   //abcdefg
	ch=getc(in);	// f

	ch= getc(in);	// g
    printf("%c\n", ch);		// 

	int byte = ftell(in);
	printf("%d\n", byte);	// 7

	// 파일의 크기를 구하기
	fseek(in, 0, SEEK_END);
	printf("%d\n", ftell(in));

    fclose(in);
}
*/

/*
void main()
{
	int ch;
    FILE *in;
	
	// 텍스트 모드 + 읽기모드 
    if ((in = fopen("02_소스cpy.txt", "r")) == NULL){
        fprintf(stderr, "test.txt => file open failure~!!\n");
        exit(1);
    }

	fseek(in, 9, SEEK_SET);		// EOF
	//abcdefg	// \r\n
	//hijklmn
	ch=getc(in);	// f


    printf("%c\n", ch);

    fclose(in);
}
*/

void write()
{
	char ch[20] = {"abcde\nfght"};
    FILE *out;
	
	// 바이너리 모드 + 읽기모드 
    if ((out = fopen("바이너리.txt", "wb")) == NULL){
        fprintf(stderr, "test.txt => file open failure~!!\n");
        exit(1);
    }

	fwrite(ch, sizeof(ch), 1, out); 

    fclose(out);
}


void read()
{
	int ch;
    FILE *in;
	
	// 바이너리 모드 + 읽기모드 
    if ((in = fopen("바이너리.txt", "rb")) == NULL){
        fprintf(stderr, "test.txt => file open failure~!!\n");
        exit(1);
    }

	fseek(in, 6, SEEK_SET);		// EOF
	//abcde\nfght
	ch=getc(in);	// f

    printf("%c\n", ch);

    fclose(in);
}

void main()
{
//	write();
	read();
	
}