/************************************************************
  11. �Ʒ� �ڵ尡 ����� �� �ִ� Ŭ���� ����
      �� ���ڿ��� Ŭ���� ������ char *name���� ���� �� ��
	  ������(���� �Ҵ�)				:
	  �Ҹ���(�޸� ����)			:
	  ���� ������(���� ����)		:
	  ��Ÿ(Set �޼���, ��¸޼���)	:
*************************************************************/

int main(void)
{
    NameCard Hong("ȫ�浿", "010-383-1111", 'M', 20);	//�̸�, ��ȭ��ȣ, ����, ����
	NameCard Kim;
    NameCard Hong2(Hong);

	Kim.SetName("�� �� ��");
	Kim.SetPhone("010-1111-4213");
	Kim.SetSex('F');
	Kim.SetAge(20);

    Hong.ShowData();	// ��� �� : [�̸�] XXX, [��ȭ��ȣ] XXX, [����] X, [����] X
	Hong2.ShowData();
	Kim.ShowData();

	char name[20];
	strcpy(Hong2.GetName(), "�̸� ����");
	int  age = Hong2.GetAge();
	cout << name << " : " << age << endl; 

    return 0;
}