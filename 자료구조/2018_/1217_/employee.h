//employee.h

#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

class Employee
{
	string	name;		// �̸�
	int	id;				// �й�
	string	grade;		// ����
	string	depart;		// �μ� 

public:
	Employee();					//default ������
	Employee(string, int, string, string);		//�����͸� ���ڷ� �޴� ������
	~Employee();					//�Ҹ���

	//Set property :�ɹ� �����Ϳ� ���� ���� ���� ����
	void SetName(string);
	void SetiId(int);
	void SetGrade(string);
	void SetDepart(string);

	//Get property : �ɹ� �����Ϳ� ���� �б� ���� ����
	string  getName() { return name; }
	int	getId();
	string	getGrade();
	string	getDepart();

	void printdata();
};

#endif /*_EMPLOYEE_H_*/