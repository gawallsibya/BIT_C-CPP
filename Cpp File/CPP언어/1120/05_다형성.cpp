/************************************************************
  01. 아래 코드가 실행될 수 있는 클래스 구현 
      Human 클래스 : 이름을 가지고 있다.
	  Student클래스 : Human을 상속받는다. 
	                  학번을 가지고 있다.
*************************************************************/

void main()
{
     Human H("김사람");
     Student S("이학생",1234567);

     Human *pH;
     Student *pS;

     pH=&H;         
     pS=&S;         

	 pH->Intro();		// 개인 정보 출력
     pS->Intro();		// 개인 정보 출력
}


/************************************************************
  02. 아래 코드가 실행될 수 있는 클래스 구현 
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
          ar[i]->Draw();	// 해당 도형명을 출력
     }

     for (i=0;i<10;i++) {
          delete ar[i];
     }
}
*/