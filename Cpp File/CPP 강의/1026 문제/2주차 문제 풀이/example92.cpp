/************************************************************
  11. 아래 코드가 실행될 수 있는 클래스 구현
      단 문자열을 클래스 내에서 char *name으로 선언 할 것
	  생성자(동적 할당)				:
	  소멸자(메모리 해제)			:
	  복사 생성자(깊은 복사)		:
	  기타(Set 메서드, 출력메서드)	:
*************************************************************/

int main(void)
{
    NameCard Hong("홍길동", "010-383-1111", 'M', 20);	//이름, 전화번호, 성별, 나이
	NameCard Kim;
    NameCard Hong2(Hong);

	Kim.SetName("김 길 양");
	Kim.SetPhone("010-1111-4213");
	Kim.SetSex('F');
	Kim.SetAge(20);

    Hong.ShowData();	// 출력 예 : [이름] XXX, [전화번호] XXX, [성별] X, [나이] X
	Hong2.ShowData();
	Kim.ShowData();

	char name[20];
	strcpy(Hong2.GetName(), "이름 변경");
	int  age = Hong2.GetAge();
	cout << name << " : " << age << endl; 

    return 0;
}