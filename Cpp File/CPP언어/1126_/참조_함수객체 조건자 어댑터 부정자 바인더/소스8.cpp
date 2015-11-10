//����������������������������������������
// [ isspace ]
//����������������������������������������

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <functional>
using namespace std;

// ���� ������ �Լ�
bool IsSpace(char c){
	return (bool)isspace(c);
}

vector<string> split(const string& str){
	typedef string::const_iterator iter;
	vector<string> ret;

	iter i = str.begin();
	while(i != str.end()){		
		//                       ������, �Լ���ü�� ��ȯ
		i = find_if(i, str.end(), not1(ptr_fun(IsSpace)));
		// ������ ���ö����� i
		iter j = find_if(i, str.end(), IsSpace);
		// �����̶�� true�̹Ƿ� �űⰡ j ������ �ȳ���  ������ 

		if (i != str.end()){
			ret.push_back(string(i, j));
		}

		i = j;
	}
	return ret;
}

void main(){
	string s1 = "welcome to home";
	vector<string> v = split(s1);

	cout << v[0] << endl;
	cout << v[1] << endl;
	cout << v[2] << endl;
}

