/////////////////****Ëã·¬****//////////////////////
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <list>
#include <vector>
#include "SuanFan.hpp"
using namespace std;

SuanFan sf;
int n;
int in[18];
pair<int,vector<int> > p;
int main(){
	while(scanf("%d",&n) != EOF){
		for(int i=0;i<n;i++)
			scanf("%d",&in[i]);
		sf.init(in,n);
		p = sf.getFanShu();
		printf("·¬Êý=%d\n",p.fi);
		for(int i=0;i<p.se.size();i++){
			printf("%d ",p.se[i]);
		}
		puts("");
	}
	return 0;
}
