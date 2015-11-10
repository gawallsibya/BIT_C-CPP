//employee.h

#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

class Employee
{
	string	name;		// 이름
	int	id;				// 학번
	string	grade;		// 직급
	string	depart;		// 부서 

public:
	Employee();					//default 생성자
	Employee(string, int, string, string);		//데이터를 인자로 받는 생성자
	~Employee();					//소멸자

	//Set property :맴버 데이터에 대한 쓰기 연산 제공
	void SetName(string);
	void SetiId(int);
	void SetGrade(string);
	void SetDepart(string);

	//Get property : 맴버 데이터에 대한 읽기 연산 제공
	string  getName() { return name; }
	int	getId();
	string	getGrade();
	string	getDepart();

	void printdata();
};

#endif /*_EMPLOYEE_H_*/