#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 10

struct student 
{  
	char name[MAXLEN];   
	int  level;
    int  korean; 
	int  english;
    int  math;
};

void fwrite()
{
	FILE *out	= fopen("data.txt", "w");

	student stu[3] = {	{"È«±æµ¿", 100, 100, 100, 100}, 
						{"±è±æµ¿", 90, 90, 90, 90}, 
						{"°í±æµ¿", 80, 80, 80, 80}};
	
	for(int i=0; i<3; i++)
	{
		fprintf(out, "%10s %10d %10d %10d %10d\n", stu[i].name,
                stu[i].level, stu[i].korean,  stu[i].english, 
                stu[i].math);
	}

	fclose(out);
}

void fread()
{
	FILE *in;
    student data[3];
	student mystudent;
    if ((in = fopen("data.txt", "r")) == NULL){
        fprintf(stderr, "source.txt => file open failure~!!\n");
        exit(1);
    }


    while (fscanf(in, "%s %d %d %d %d", mystudent.name, &mystudent.level, 
        &mystudent.korean,  &mystudent.english, &mystudent.math) != EOF)
	{
        printf("%10s %10d %10d %10d %10d\n", mystudent.name,
                mystudent.level, mystudent.korean,  mystudent.english, 
                mystudent.math);
	}

    fclose(in);

}

void main()
{
//	fwrite();
	fread();
}
