#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string str[100];
string str1[100];

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i = 0;
	while(cin>>str[i]){	
		str1[i] = str[i];
		str1[i][0] += 'a' - 'A';
		i++;
		
	}
	for(int j=0;j<i;j++){
		cout<<"\tint "<<str1[j]<<"();\n";
	}
	puts("");
	puts("");
	puts("");
	for(int j=0;j<i;j++){
		cout<<"\tfunc[(int)"<<str[j]<<"] = &SuanFan::"<<str1[j]<<";\n";
	}
	puts("");
	puts("");
	puts("");
	for(int j=0;j<i;j++){
		cout<<"int SuanFan::"<<str1[j]<<"()\n{\n\n\treturn 0;\n}\n\n\n";
	}
}
