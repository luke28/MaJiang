/////////////////****算番****//////////////////////
#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include "SuanFan.hpp"
using namespace std;

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


SuanFan sf;
int n;
int in[18];
pair<int,vector<int> > p;
int main(){
	init();
	while(scanf("%d",&n) != EOF){
		for(int i=0;i<n;i++)
			scanf("%d",&in[i]);
		sf.init(in,n);
		p = sf.getFanShu();
		printf("番数=%d\n",p.fi);
		for(int i=0;i<p.se.size();i++){
			//printf("%d ",p.se[i]);
			print(p.se[i]);
		}
		puts("");
	}
	return 0;
}
