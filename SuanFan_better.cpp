#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include "SuanFan.hpp"
using namespace std;

SuanFan sf;
int n;
int in[18];
pair<int,vector<int> > p;

string strFan[MAXFAN];
void init(){
	freopen("FanShu_Chinese.txt","r",stdin);
 	for(int i=0;i<MAXFAN;i++){
 		cin>>strFan[i];
 	}
 	fclose(stdin);
	freopen("CON","r",stdin);   //加这一句,"CON"代表控制台
}
void print(int i){
	//printf("%s\n",strFan[i]);
	cout<<strFan[i]<<endl;
}

int getOne(){
	char str[10];
	int num;
	int ret = 0;
	Pai p;
	scanf("%s",str);
	num = atoi(str+1);
	p.num = num;
	if(str[0] == 'w'){
		p.type = WAN;
	}
	else if(str[0] == 't'){
		p.type = TIAO;
	}
	else if(str[0] == 'b'){
		p.type = BING;
	}
	else if(str[0] == 'f'){
		p.type = FENG;
	}
	else{
		p.type = YUAN;
	}
	return SuanFan::getHashcode(p);
}


int main(){
	init();
	while(scanf("%d",&n) != EOF){
		for(int i=0;i<n;i++)
			in[i] = getOne();
		sf.init(in,n);
		p = sf.getFanShu();
		printf("番数=%d\n",p.fi);
		for(int i=0;i<p.se.size();i++){
			print(p.se[i]);
			//printf("%d ",p.se[i]);
		}
		puts("");
	}
	return 0;
}
