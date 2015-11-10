//main.cpp

#include "std.h"

#include "app.h"


void main()
{
	App app;

	app.init();
	app.run();
	app.exit();
}



/*
int arr[10] = {1,2,3,4,5,6,7,8,9,10};
char ch = 'a';
char name[20] = "TEST";
void file_save()
{
	FILE *fp = fopen("test.txt", "wb");
	if( fp == NULL)
	{
		cout << "error" << endl;
		return;
	}

	fwrite(arr, sizeof(arr), 1, fp);
	fwrite(&ch, sizeof(char), 1, fp);
	fwrite(name, sizeof(name), 1, fp);

	fclose(fp);
}

int arr1[10];
char ch1 ;
char name1[20];

void file_load()
{
	FILE *fp = fopen("test.txt", "rb");
	if( fp == NULL)
	{
		cout << "error" << endl;
		return;
	}

	fread(arr1, sizeof(arr1), 1, fp);
	fread(&ch1, sizeof(char), 1, fp);
	fread(name1, sizeof(name), 1, fp);

	for(int i=0; i<10; i++)
	{
		cout << arr1[i] << endl; 
	}

	cout << ch1 << endl; 
	cout << name1 << endl; 

	fclose(fp);
}


void main()
{
//	file_save();
	file_load();
}

  */