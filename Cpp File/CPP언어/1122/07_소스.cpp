#include <iostream>
using namespace std;

//02_�ҽ�cpy.txt

//SEEK_SET  ó��
//SEEK_CUR  ������ġ
//SEEK_END  ������ ��
//int fseek(FILE * stream, long offset, int startpos);
//long ftell(FILE * stream);

/*
void main()
{
	int ch;
    FILE *in;
	
	// �ؽ�Ʈ ��� + �б��� 
    if ((in = fopen("02_�ҽ�cpy.txt", "r")) == NULL){
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

	// ������ ũ�⸦ ���ϱ�
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
	
	// �ؽ�Ʈ ��� + �б��� 
    if ((in = fopen("02_�ҽ�cpy.txt", "r")) == NULL){
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
	
	// ���̳ʸ� ��� + �б��� 
    if ((out = fopen("���̳ʸ�.txt", "wb")) == NULL){
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
	
	// ���̳ʸ� ��� + �б��� 
    if ((in = fopen("���̳ʸ�.txt", "rb")) == NULL){
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