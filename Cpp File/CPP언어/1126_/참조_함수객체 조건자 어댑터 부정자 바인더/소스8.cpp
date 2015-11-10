//〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓
// [ isspace ]
//〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <functional>
using namespace std;

// 단항 조건자 함수
bool IsSpace(char c){
	return (bool)isspace(c);
}

vector<string> split(const string& str){
	typedef string::const_iterator iter;
	vector<string> ret;

	iter i = str.begin();
	while(i != str.end()){		
		//                       부정자, 함수객체로 변환
		i = find_if(i, str.end(), not1(ptr_fun(IsSpace)));
		// 공백이 나올때까지 i
		iter j = find_if(i, str.end(), IsSpace);
		// 공백이라면 true이므로 거기가 j 공백이 안나올  때까지 

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

