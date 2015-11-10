/************************************************************
  08. 다음 출력 결과를 만족하는 클래스를 구현하시오.
		결과 : 
		1990/1/1 
		1990/1/1 
		1990/1/1 
		true 
		false 
*************************************************************/
class  ___________________			// 1) 클래스명 
{
	int year;	int month;	int day;
public:
	//2) 인자를 3개 받는 생성자



	//3) print 메서드



   //4) 객체를 인자로 받는 cmp 메서드



   //5) 정수형 인자 3개를 받는 cmp 메서드



};

void main ( ) 
{ 
        Date arr[3];         int i; 

        for( i = 0 ; i < 3 ; i++)                
			arr[i].print( );// 모두 1990/1/1 

        arr[1].cmp(arr[0]) ? cout << "true" <<  endl : cout << "false" <<endl ; 
        arr[1].cmp(1990,2,1) ? cout << "true"  <<endl : cout << "false" <<endl ; 
} 
