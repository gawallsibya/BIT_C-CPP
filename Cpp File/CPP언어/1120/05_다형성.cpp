/************************************************************
  01. �Ʒ� �ڵ尡 ����� �� �ִ� Ŭ���� ���� 
      Human Ŭ���� : �̸��� ������ �ִ�.
	  StudentŬ���� : Human�� ��ӹ޴´�. 
	                  �й��� ������ �ִ�.
*************************************************************/

void main()
{
     Human H("����");
     Student S("���л�",1234567);

     Human *pH;
     Student *pS;

     pH=&H;         
     pS=&S;         

	 pH->Intro();		// ���� ���� ���
     pS->Intro();		// ���� ���� ���
}


/************************************************************
  02. �Ʒ� �ڵ尡 ����� �� �ִ� Ŭ���� ���� 
      class Graphic
	  class Line : public Graphic
	  class Circle : public Graphic
	  class Rect : public Graphic
*************************************************************/
/*
void main()
{
     Graphic *ar[10]={
          new Graphic(),new Rect(),new Circle(),new Rect(),new Line(),
          new Line(),new Rect(),new Line(),new Graphic(),new Circle() };

     int i;

     for (i=0;i<10;i++) {
          ar[i]->Draw();	// �ش� �������� ���
     }

     for (i=0;i<10;i++) {
          delete ar[i];
     }
}
*/