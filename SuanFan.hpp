/////////////////****�㷬****//////////////////////
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <assert.h>
using namespace std;
#define MAXPAI 34
#define MAXIN 18
#define MAXFAN 80
#define DONG 0
#define NAN 1
#define XI 2
#define BEI 3
#define ZHONG 0
#define FA 1
#define BAI 2
#define pb push_back
#define mp make_pair
#define fi first
#define se second

enum PaiType{
	WAN,TIAO,BING,FENG,YUAN 
};
enum Col{
	//�̻���� 
	GRN,NG
};
//�г��Ĵʵ����� 
enum WordType{
	DUI,SHUN,KE,GANG
}; 

enum HuType{
	/*TianHu,DiHu,RenHu,TianTing,*/
	DaSiXi,DaSanYuan,LvYiSe,JiuBaoLianDeng,SiGang,
	LianQiDui,ShiSanYao,QingYaoJiu,XiaoSiXi,XiaoSanYuan,
	ZiYiSe,SiAnKe,YiSeShuangLongHui,YiSeSiTongShun,YiSeSiJieGao,
	YiSeSiBuGao,SanGang,HunYaoJiu, QiDui,QiXingBuKao,
	QuanShuangKe,QingYiSe,YiSeSanJieGao,YiSeSanTongShun,QuanDa,
	QuanZhong,QuanXiao,QingLong,SanSeShuangLongHui,YiSeSanBuGao,
	QuanDaiWu,SanTongKe,SanAnKe,QuanBuKao,ZuHeLong,
	DaYuWu,XiaoYuWu,SanFengKe,HuaLong,TuiBuDao,
	SanSeSanTongShun,SanSeSanJieGao,WuFanHu,MiaoShouHuiChun,HaiDiLaoYue,
	GangShangKaiHua,QiangGangHu,PengPengHu,HunYiSe,SanSeSanBuGao,
	WuMenQi,QuanQiuRen,ShuangAnGang,ShuangJianKe,QuanDaiYao,
	BuQiuRen,ShuangMingGang,HuJueZhang,JianKe,QuanFengKe,
	MenFengKe,MenQianQing,PingHu,SiGuiYi,ShuangTongKe,
	ShuangAnKe,AnGang,DuanYao,YiBanGao,XiXiangFeng,
	LianLiu,LaoShaoFu,MingGang,YaoJiuKe,QueYiMen,
	WuZi,BianZhang,KeZhang,DanDiaoJiang,ZiMo
};
struct Pai{
	enum PaiType type;
	enum Col col;
	int num;
};
//�г��Ĵ� 
struct Word{
	enum WordType type;
	//�ô�����ĸ 
	int first;
	Word(WordType w = DUI,int f = 0):type(w),first(f){
	}
};

bool cmpWord(Word x,Word y){
	if(x.type == DUI)
		return 1;
	if(y.type == DUI)
		return 0;
	return x.first < y.first;
}

struct SuanFan{
	typedef int (SuanFan::*PF) ();
	static const int inf = 0x3f3f3f3f;
	struct Pai paiSet[MAXPAI];
	int huPai[MAXIN];
	int m;
	int menFeng,quanFeng;
	bool isMenQing,isZiMo;
	PF func[MAXFAN];
	int fanShu[MAXFAN];
	vector<int> fuGai[MAXFAN];  
//���㷬������صı��� 
	int ans;
	vector<int> ansVec;
	//������ַ���Ҫ�õ���Word����
	//vector<int> mark_word[MAXFAN];
	bool mark_word[MAXFAN];
	//�洢���÷���
	vector<Word> nowFan;
	//��ǰ����״̬��ʣ������ 
	vector<int>  rest;
	//�������
	bool mark_dui[MAXPAI];
	vector<int> duiSet; 
	//�ܵ����
	bool mark_gang[MAXPAI];
/**********************����***********************/ 
	SuanFan();
	static int getHashcode(struct Pai x);
	//in��������,mm��������, men�ŷ�,qȦ�� 
	//����0��ʾ����������1��ʾ��������⣬����2��ʾ�Ƶ��������� 
	int init(int in[],int mm,int men=DONG,
		int q=DONG,bool zimo = false, bool menQing = false);
		
	pair<int,vector<int> > getFanShu();
	void TePan();
	void dfs(int dep);
	void findGang(int dep);
	void findKe(int dep);
	void findShun(int dep);
	//���һ�ִַʷ�ʽ���м��� 
	int Cal(vector<int>& vec);	
	
/******������******/
	int daSiXi();
	int daSanYuan();
	int lvYiSe();
	int jiuBaoLianDeng();
	int siGang();
	int lianQiDui();
	int shiSanYao();
	int qingYaoJiu();
	int xiaoSiXi();
	int xiaoSanYuan();
	int ziYiSe();
	int siAnKe();
	int yiSeShuangLongHui();
	int yiSeSiTongShun();
	int yiSeSiJieGao();
	int yiSeSiBuGao();
	int sanGang();
	int hunYaoJiu();
	int qiDui();
	int qiXingBuKao();
	int quanShuangKe();
	int qingYiSe();
	int yiSeSanJieGao();
	int yiSeSanTongShun();
	int quanDa();
	int quanZhong();
	int quanXiao();
	int qingLong();
	int sanSeShuangLongHui();
	int yiSeSanBuGao();
	int quanDaiWu();
	int sanTongKe();
	int sanAnKe();
	int quanBuKao();
	int zuHeLong();
	int daYuWu();
	int xiaoYuWu();
	int sanFengKe();
	int huaLong();
	int tuiBuDao();
	int sanSeSanTongShun();
	int sanSeSanJieGao();
	int wuFanHu();
	int miaoShouHuiChun();
	int haiDiLaoYue();
	int gangShangKaiHua();
	int qiangGangHu();
	int pengPengHu();
	int hunYiSe();
	int sanSeSanBuGao();
	int wuMenQi();
	int quanQiuRen();
	int shuangAnGang();
	int shuangJianKe();
	int quanDaiYao();
	int buQiuRen();
	int shuangMingGang();
	int huJueZhang();
	int jianKe();
	int quanFengKe();
	int menFengKe();
	int menQianQing();
	int pingHu();
	int siGuiYi();
	int shuangTongKe();
	int shuangAnKe();
	int anGang();
	int duanYao();
	int yiBanGao();
	int xiXiangFeng();
	int lianLiu();
	int laoShaoFu();
	int mingGang();
	int yaoJiuKe();
	int queYiMen();
	int wuZi();
	int bianZhang();
	int keZhang();
	int danDiaoJiang();
	int ziMo();
		
/*****Debug******/
	void print_rest();
	void print_nowFan();
};


/////////////////Debug////////////////
void SuanFan::print_rest(){
	for(int i=0;i<rest.size();i++){
		cout<<rest[i]<<' ';
	}
	cout<<endl;
}
void SuanFan::print_nowFan(){
	for(int i=0;i<nowFan.size();i++){
		if(nowFan[i].type == DUI){
			cout<<nowFan[i].first<<" "<<nowFan[i].first<<"; ";
		}
		else if(nowFan[i].type == SHUN){
			cout<<nowFan[i].first<<" "<<nowFan[i].first+1<<" "
			<<nowFan[i].first+2<<"; ";
		}
		else if(nowFan[i].type == KE){
			cout<<nowFan[i].first<<" "<<nowFan[i].first<<" "
			<<nowFan[i].first<<"; ";
		}
		else{
			cout<<nowFan[i].first<<" "<<nowFan[i].first<<" "
			<<nowFan[i].first<<" "<<nowFan[i].first<<"; ";
		}
	}
	cout<<endl;
}

///////////ʵ��////////////////// 
pair<int,vector<int> > SuanFan::getFanShu(){
	ans = -1;
	ansVec.clear();
	nowFan.clear();
	rest.clear();
	duiSet.clear();
	memset(mark_dui,0,sizeof(mark_dui));
	for(int i=0;i<m;i++){
		rest.pb(huPai[i]);
	}
	TePan();
	//ȡ�����ж��� 
	for(int i=0;i<m-1;i++){
		if(mark_dui[huPai[i]] == 0 && huPai[i] == huPai[i+1]){
			mark_dui[huPai[i]] = 1;
			duiSet.pb(i);
		}
	}
	if(duiSet.size() == 0)
		return mp(ans,ansVec);;
	for(int i=0;i<duiSet.size();i++){
		int tmp = rest[duiSet[i]];
		rest.erase(rest.begin()+duiSet[i],rest.begin()+duiSet[i]+2);
		nowFan.pb(Word(DUI,tmp));
		memset(mark_gang,0,sizeof(mark_gang));
	//	print_rest();
		dfs(0);
		nowFan.pop_back();
		rest.insert(rest.begin()+duiSet[i],2,tmp);
	//	print_rest();
	}
	return mp(ans,ansVec);
}

void SuanFan::dfs(int dep){
	if(dep == 4){
		if(rest.size() != 0)
			return;
		vector<int> vec;
		int tmp = Cal(vec);
		if(tmp > ans){
			ans = tmp;
			ansVec = vec;
		}
		return;
	}
//	print_rest();
//	cout<<"dep="<<dep<<endl;
	if(rest.size() > 3*(4-dep)){
		findGang(dep);
	}
	else{
		findShun(dep);
		findKe(dep);
	}
}

void SuanFan::findKe(int dep){
	if(rest[0] == rest[1] && rest[1] == rest[2])
	{
		int tmp = rest[0];
		nowFan.pb(Word(KE,tmp));
		rest.erase(rest.begin(),rest.begin()+3);
		dfs(dep+1);
		nowFan.pop_back();
		rest.insert(rest.begin(),3,tmp);
	}
}

void SuanFan::findShun(int dep){
	PaiType type = paiSet[rest[0]].type;
	int val = paiSet[rest[0]].num;
	if(type == FENG || type == YUAN || val>=8){
		return;
	}
	int i,j;
	for(i=1;i<rest.size()-1;i++){
		if(rest[i] == rest[0] + 1)
			break;
		else if(rest[i] > rest[0]+1)
			return;
	}
	if(i == rest.size()-1)
		return;
	for(j=i+1;j<rest.size();j++){
		if(rest[j] == rest[i]+1)
			break;
		else if(rest[j] > rest[i]+1)
			return;
	}
	if(j == rest.size())
		return;
	int tmp = rest[0];
	nowFan.pb(Word(SHUN,tmp));
	rest.erase(rest.begin()+j);
	rest.erase(rest.begin()+i);
	rest.erase(rest.begin());
	dfs(dep+1);
	rest.insert(rest.begin(),tmp);
	rest.insert(rest.begin()+i,tmp+1);
	rest.insert(rest.begin()+j,tmp+2);
	nowFan.pop_back();
}


void SuanFan::findGang(int dep){
	int i;
	//j+i��O(3*n)��ΪO(n+3) 
	for(int j=0;j<rest.size()-3;j+=i)
	{
		if(mark_gang[rest[j]] == 1)
			continue;
		for(i=1;i<=3;i++){
			if(rest[j+i] != rest[j])
				break;
		}
		if(i==4){
			int tmp = rest[j];
			mark_gang[tmp] = 1;
			nowFan.pb(Word(GANG,tmp));
			rest.erase(rest.begin()+j,rest.begin()+j+4);
			dfs(dep+1);
			nowFan.pop_back();
			rest.insert(rest.begin()+j,4,tmp);
		}
	}
}

int SuanFan::Cal(vector<int>& vec){
	int ret = 0;
	memset(mark_word,0,sizeof(mark_word));
	print_nowFan();
	for(int i=0;i<MAXFAN;i++){
		if(func[i] != NULL){
		/*	int mark[5] = {0,0,0,0,0};
			int cnt = 0;
			vector<Word> saveWord(nowFan);
			for(int j=0;j<fuGai[i].size();j++){
				int tmp = fuGai[i][j];
				for(int k=0;k<mark_word[tmp].size();k++){
					if(mark[mark_word[tmp][k]]==0){
						mark[mark_word[tmp][k]] = 1;
						cnt++;
					}
					if(cnt == 5){
						break;
					}
				}
				if(cnt == 5)
					break;
			}
			if(cnt == 5)
				continue;
			for(int j=4;j>=0;j--){
				if(mark[j] == 1){
					nowFan.erase(nowFan.begin()+j);
				}
			}*/
			bool flag = 0;
			for(int j=0;j<fuGai[i].size();j++){
				if(mark_word[fuGai[i][j]] != 0){
					flag = 1;
					break;
				}
					
			}
			if(flag == 1)
				continue;
			int num = (this->*func[i])();
			ret += num * fanShu[i];
			mark_word[i] = num;
			for(int j=0;j<num;j++){
				vec.pb(i);
			}
		}	
	}
	return ret;
}


void SuanFan::TePan(){
	if(lianQiDui() == 1){
		ans = fanShu[(int)LianQiDui];
		ansVec.pb((int)LianQiDui);
		if(isZiMo == 1){
			ans += fanShu[(int)ZiMo];
			ansVec.pb((int)ZiMo);
		}
		return;
	}
	if(shiSanYao() == 1){
		ans = fanShu[(int)ShiSanYao];
		ansVec.pb((int)ShiSanYao);
		if(isZiMo == 1){
			ans += fanShu[(int)ZiMo];
			ansVec.pb((int)ZiMo);
		}
		return;
	}
	if(qiDui() == 1){
		ans = fanShu[(int)QiDui];
		ansVec.pb((int)QiDui);
		if(isZiMo == 1){
			ans += fanShu[(int)ZiMo];
			ansVec.pb((int)ZiMo);
		}
		return;
	}
	if(qiXingBuKao()==1){
		ans = fanShu[(int)QiXingBuKao];
		ansVec.pb((int)QiXingBuKao);
		if(isZiMo == 1){
			ans += fanShu[(int)ZiMo];
			ansVec.pb((int)ZiMo);
		}
		return;
	}
	if(quanBuKao() == 1){
		ans = fanShu[(int)QuanBuKao];
		ansVec.pb((int)QuanBuKao);
		if(isZiMo == 1){
			ans += fanShu[(int)ZiMo];
			ansVec.pb((int)ZiMo);
		}
		return;
	}
}

//����ϲ 
int SuanFan::daSiXi()
{
	int i;
	for(i=1;i<nowFan.size();i++){
		if(nowFan[i].first >= 27 && nowFan[i].first <= 30)
		{
			continue;
		}
		return 0;
	}
	if(i == 5){
		return 1;
	}
	return 0;
}

//����Ԫ 
int SuanFan::daSanYuan()
{
	int cnt = 0;
	int mark[3];
	for(int i=1;i<nowFan.size();i++){
		if(nowFan[i].first >= 31 && nowFan[i].first <= 33)
		{
			mark[cnt] = i;
			cnt++;
		}
	}
	if(cnt == 3){
		return 1;
	}	
	return 0;
}

//��һɫ 
int SuanFan::lvYiSe()
{
	for(int i=0;i<m;i++){
		if(paiSet[huPai[i]].col == NG)
			return 0;
	}
	return 1;
}

//�ű����� 
int SuanFan::jiuBaoLianDeng()
{
	if(m != 14)
		return 0;
	int i,j;
	j = huPai[0];
	if(j != 0 && j != 9 && j != 18){
		return 0;
	}
	int pei[13] ={0,0,0,1,2,3,4,5,6,7,8,8,8};
	int flag = 0;
	for(i=1;i<m;i++){
		if(i == m-1 && flag==0){
			if(paiSet[huPai[i]].type == paiSet[j].type)
				continue;
			else
				break;
		}
		if(pei[i-flag]+j != huPai[i]){
			if(flag == 0 && paiSet[huPai[i]].type == paiSet[j].type)
				flag = 1;
			else
				break;
		}
	}
	if(i==m){
		return 1;
	}
	return 0;
}

//�ĸ� 
int SuanFan::siGang()
{
	if(m == 18)
		return 1;
	return 0;
}

//���߶� 
int SuanFan::lianQiDui()
{
	if(m != 14)
		return 0;
	int i,j;
	j = huPai[0];
	for(i=0;i<3;i++){
		if(j == i){
			break;
		}
		if(j == 9+i){
			break;
		}
		if(j==18+i){
			break;
		}
	}
	if(i == 3){
		return 0;
	}
	int pei[14]={0,0,1,1,2,2,3,3,4,4,5,5,6,6};
	for(int i=0;i<m;i+=2){
		if(j+(i>>1) != huPai[i] || huPai[i] != huPai[i+1]){
			return 0;
		}
	}
	return 1;
}

//ʮ���� 
int SuanFan::shiSanYao()
{
	int pei[13] ={0,8,9,17,18,26,27,28,29,30,31,32,33};
	int flag = 0;
	for(int i=1;i<m;i++){
		if(i == m-1 && flag==0){
			if(binary_search(pei,pei+13,huPai[i]) == 1)
				continue;
			else
				return 0;
		}
		if(pei[i-flag] != huPai[i]){
			if(flag == 0 && binary_search(pei,pei+13,huPai[i]) == 1)
				flag = 1;
			else
				return 0;
		}
	}
	return 1;
}


int SuanFan::qingYaoJiu()
{
	for(int i=0;i<nowFan.size();i++){
		Word tmp = nowFan[i];
		if(tmp.type == SHUN){
			return 0;
		}
		Pai p = paiSet[tmp.first];
		if((int)p.type >= 3){
			return 0;
		}
		if(p.num != 1 && p.num != 9)
		{
			return 0;
		}
	}
	return 1;
}


int SuanFan::xiaoSiXi()
{
	int num = 0;
	if(paiSet[nowFan[0].first].type != FENG){
		return 0;
	} 
	for(int i=1;i<nowFan.size();i++){
		Word tmp = nowFan[i];
		if(paiSet[tmp.first].type == FENG){
			num++;
		} 
	}
	if(num == 3){
		return 1;
	}
	return 0;
}


int SuanFan::xiaoSanYuan()
{
	int num = 0;
	if(paiSet[nowFan[0].first].type != YUAN){
		return 0;
	} 
	for(int i=1;i<nowFan.size();i++){
		Word tmp = nowFan[i];
		if(paiSet[tmp.first].type == YUAN){
			num++;
		} 
	}
	if(num == 2){
		return 1;
	}
	return 0;
}


int SuanFan::ziYiSe()
{
	for(int i=0;i<nowFan.size();i++){
		Word tmp = nowFan[i];
		if(paiSet[tmp.first].type == YUAN || paiSet[tmp.first].type == FENG){
			continue;
		}
		return 0;
	}
	return 1;
}


int SuanFan::siAnKe()
{
	
	return 0;
}

//һɫ˫���� 
int SuanFan::yiSeShuangLongHui()
{
	if(m != 14)
		return 0;
	PaiType now = paiSet[nowFan[0].first].type;
	if(paiSet[nowFan[0].first].num != 5)
		return 0;
	if(now >= FENG)
		return 0;
	int pei[4] = {1,1,7,7};
	for(int i=1;i<nowFan.size();i++){
		Word tmp = nowFan[i];
		if(paiSet[tmp.first].type != now)
			return 0;
		if(tmp.type != SHUN)
		 	return 0;
		if(paiSet[tmp.first].num != pei[i-1]){
			return 0;
		}
	}
	return 1;
}

//һɫ��ͬ˳ 
int SuanFan::yiSeSiTongShun()
{
	if(m!=14)
		return 0;
	for(int i=1;i<nowFan.size();i++){
		if(nowFan[i].type != SHUN)
		 	return 0;
		if(i!=nowFan.size()-1 && nowFan[i].first != nowFan[i+1].first)
			return 0;
	}
	return 1;
}

//һɫ�Ľڸ� 
int SuanFan::yiSeSiJieGao()
{
	vector<Word> nowF(nowFan);
/*	for(int i=0;i<nowF.size();i++){
		cout<<nowF[i].type<<' '<<nowF[i].first<<endl;
	}*/
	sort(nowF.begin(),nowF.end(),cmpWord);
/*	for(int i=0;i<nowF.size();i++){
		cout<<nowF[i].first<<endl;
	}*/
	PaiType now = paiSet[nowF[1].first].type;
	if(now >= FENG)
		return 0;
	if(nowF[1].type != KE && nowF[1].type != GANG)
		return 0;
	if(paiSet[nowF[1].first].num >= 7)
		return 0;
	for(int i=2;i<nowF.size();i++){
		if(nowF[i].type != KE && nowF[i].type != GANG)
		 	return 0;
		if(nowF[i].first != nowF[i - 1].first + 1)
			return 0;
	}
	return 1;
}

//һɫ�Ĳ��� 
int SuanFan::yiSeSiBuGao()
{
	if(m!=14)
		return 0;
	int i;
	for(i=1;i<nowFan.size();i++){
		if(nowFan[i].type != SHUN)
		 	break;
		if(i!=nowFan.size()-1 && nowFan[i].first != nowFan[i+1].first+1)
			break;
	}
	if(i == nowFan.size())
		return 1;
	for(i=1;i<nowFan.size();i++){
		if(nowFan[i].type != SHUN)
		 	return 0;
		if(i!=nowFan.size()-1 && nowFan[i].first != nowFan[i+1].first+2)
			return 0;
	}	
	return 1;
}

//���� 
int SuanFan::sanGang()
{
	if(m == 17)
		return 1;
	return 0;
}

//���۾� 
int SuanFan::hunYaoJiu()
{
	for(int i=0;i<nowFan.size();i++){
		Word tmp = nowFan[i];
		if(tmp.type == SHUN){
			return 0;
		}
		Pai p = paiSet[tmp.first];
		if((int)p.type < FENG){
			if(p.num != 1 && p.num != 9)
			{
				return 0;
			}
		}
	}
	return 1;
}


int SuanFan::qiDui()
{
	if(m != 14)
		return 0;
	for(int i=0;i<m;i+=2){
		if(huPai[i] != huPai[i+1])
			return 0;
	}
	return 1;
}


int SuanFan::qiXingBuKao()
{
	if(m != 14)
		return 0;
	for(int i=0;i<7;i++){
		if(huPai[m-i-1] != MAXPAI-i-1){
			return 0;
		}
	}
	int res = m - 7;
	int num[3]={0,0,0};
	int sum[4]={0,0,0,0};
	int mark[10] = {-1,0,1,2,0,1,2,0,1,2};
	int mark_se[3] = {0,0,0};
	for(int i=0;i<res;i++){
		if(paiSet[huPai[i]].type >= FENG)
			return 0;
		num[(int)(paiSet[huPai[i]].type)]++;
	}
	sum[1] = num[0];
	sum[2] = sum[1] + num[1];
	sum[3] = sum[2] + num[2];
	for(int i=0;i<3;i++){
		if(num[i]<1 || num[i]>3)
			return 0;
		int now = mark[paiSet[huPai[sum[i]]].num];
		if(mark_se[now] == 1)
			return 0;
		mark_se[now] = 1; 
		for(int j=sum[i]+1;j<sum[i+1];j++){
			if(huPai[j] == huPai[j-1])
				return 0;
			if(mark[paiSet[huPai[j]].num] != now){
				return 0;
			}
		}
	}
	return 1;
}


int SuanFan::quanShuangKe()
{

	return 0;
}


int SuanFan::qingYiSe()
{

	return 0;
}


int SuanFan::yiSeSanJieGao()
{

	return 0;
}


int SuanFan::yiSeSanTongShun()
{

	return 0;
}


int SuanFan::quanDa()
{

	return 0;
}


int SuanFan::quanZhong()
{

	return 0;
}


int SuanFan::quanXiao()
{

	return 0;
}


int SuanFan::qingLong()
{

	return 0;
}


int SuanFan::sanSeShuangLongHui()
{

	return 0;
}


int SuanFan::yiSeSanBuGao()
{

	return 0;
}


int SuanFan::quanDaiWu()
{

	return 0;
}


int SuanFan::sanTongKe()
{

	return 0;
}


int SuanFan::sanAnKe()
{

	return 0;
}


int SuanFan::quanBuKao()
{
	if(m != 14)
		return 0;
	int mar[7] = {0,0,0,0,0,0,0};
	int cnt;
	for(cnt=0;cnt<7;cnt++){
		if(huPai[m-cnt-1] < 27){
			break;
		}
		if(mar[huPai[m-cnt-1]-27] == 1)
			return 0;
		mar[huPai[m-cnt-1]-27] = 1;
	}
	if(cnt < 5)
		return 0;
	int res = m - cnt;
	int num[3]={0,0,0};
	int sum[4]={0,0,0,0};
	int mark[10] = {-1,0,1,2,0,1,2,0,1,2};
	int mark_se[3] = {0,0,0};
	for(int i=0;i<res;i++){
		if(paiSet[huPai[i]].type >= FENG)
			return 0;
		num[(int)(paiSet[huPai[i]].type)]++;
	}
	sum[1] = num[0];
	sum[2] = sum[1] + num[1];
	sum[3] = sum[2] + num[2];
	for(int i=0;i<3;i++){
		if(num[i]<1 || num[i]>3)
			return 0;
		int now = mark[paiSet[huPai[sum[i]]].num];
		if(mark_se[now] == 1)
			return 0;
		mark_se[now] = 1; 
		for(int j=sum[i]+1;j<sum[i+1];j++){
			if(huPai[j] == huPai[j-1])
				return 0;
			if(mark[paiSet[huPai[j]].num] != now){
				return 0;
			}
		}
	}
	return 1;
}


int SuanFan::zuHeLong()
{

	return 0;
}


int SuanFan::daYuWu()
{

	return 0;
}


int SuanFan::xiaoYuWu()
{

	return 0;
}


int SuanFan::sanFengKe()
{

	return 0;
}


int SuanFan::huaLong()
{

	return 0;
}


int SuanFan::tuiBuDao()
{

	return 0;
}


int SuanFan::sanSeSanTongShun()
{

	return 0;
}


int SuanFan::sanSeSanJieGao()
{

	return 0;
}


int SuanFan::wuFanHu()
{

	return 0;
}


int SuanFan::miaoShouHuiChun()
{

	return 0;
}


int SuanFan::haiDiLaoYue()
{

	return 0;
}


int SuanFan::gangShangKaiHua()
{

	return 0;
}


int SuanFan::qiangGangHu()
{

	return 0;
}


int SuanFan::pengPengHu()
{

	return 0;
}


int SuanFan::hunYiSe()
{

	return 0;
}


int SuanFan::sanSeSanBuGao()
{

	return 0;
}


int SuanFan::wuMenQi()
{

	return 0;
}


int SuanFan::quanQiuRen()
{

	return 0;
}


int SuanFan::shuangAnGang()
{

	return 0;
}


int SuanFan::shuangJianKe()
{

	return 0;
}


int SuanFan::quanDaiYao()
{

	return 0;
}


int SuanFan::buQiuRen()
{

	return 0;
}


int SuanFan::shuangMingGang()
{

	return 0;
}


int SuanFan::huJueZhang()
{

	return 0;
}


int SuanFan::jianKe()
{

	return 0;
}


int SuanFan::quanFengKe()
{

	return 0;
}


int SuanFan::menFengKe()
{

	return 0;
}


int SuanFan::menQianQing()
{

	return 0;
}


int SuanFan::pingHu()
{

	return 0;
}


int SuanFan::siGuiYi()
{

	return 0;
}


int SuanFan::shuangTongKe()
{

	return 0;
}


int SuanFan::shuangAnKe()
{

	return 0;
}


int SuanFan::anGang()
{

	return 0;
}


int SuanFan::duanYao()
{

	return 0;
}


int SuanFan::yiBanGao()
{

	return 0;
}


int SuanFan::xiXiangFeng()
{

	return 0;
}


int SuanFan::lianLiu()
{

	return 0;
}


int SuanFan::laoShaoFu()
{

	return 0;
}


int SuanFan::mingGang()
{

	return 0;
}


int SuanFan::yaoJiuKe()
{

	return 0;
}


int SuanFan::queYiMen()
{

	return 0;
}


int SuanFan::wuZi()
{

	return 0;
}


int SuanFan::bianZhang()
{

	return 0;
}


int SuanFan::keZhang()
{

	return 0;
}


int SuanFan::danDiaoJiang()
{

	return 0;
}


int SuanFan::ziMo()
{

	return 0;
}



int SuanFan::init(int in[],int mm,int men,int q,bool zimo, bool menQing)
{
	if(mm > 18 || mm < 14)
		return 2;
	for(int i=0;i<mm;i++)
	{
		//assert(in[i] < MAXPAI);
		if(in[i] >= MAXPAI)
			return 1;
		huPai[i] = in[i];
	}	
	m = mm;
	
	sort(huPai,huPai+m);
	menFeng = men;
	quanFeng = q;
	isZiMo = zimo;
	isMenQing = menQing;
	
	//func[(int)DaSiXi] = this->daSiXi;
	return 0;
}

int SuanFan::getHashcode(Pai x)
{
	if((int)x.type < 3){
		return (int)x.type * 9 + x.num;
	}
		else if(x.type == FENG){
		return 27 + x.num;
	}
	else{
		return 31 + x.num;
	}
}


SuanFan::SuanFan(){
	int i=0;
	for(int k=0;k<3;k++){
		for(int j=1;j<=9;j++,i++){
			paiSet[i].num = j;
			paiSet[i].type = (enum PaiType)k;
			if(paiSet[i].type == TIAO){
				if(j==2||j==3||j==4||j==6||j==8){
					paiSet[i].col = GRN;
				}
				else{
					paiSet[i].col = NG;
				}
			}
			else{
				paiSet[i].col = NG;
			}	
		}
	}
	for(int j=0;j<=3;j++,i++){
			paiSet[i].num = j;
			paiSet[i].type = FENG;
			paiSet[i].col = NG;
	}
	for(int j=0;j<=2;j++,i++){
			paiSet[i].num = j;
			paiSet[i].type = YUAN;
			if(j == FA){
				paiSet[i].col = GRN;
			}
			else{
				paiSet[i].col = NG;
			}	
	}
	for(int i=0;i<MAXFAN;i++){
		func[i] = NULL;
	}
	for(i=0;i<MAXFAN;i++)
	{
		if(i<7)
			fanShu[i] = 88;
		else if(i < 13)
			fanShu[i] = 64;
		else if(i<15)
			fanShu[i] = 48;
		else if(i<18)
			fanShu[i] = 32;
		else if(i<27)
			fanShu[i] = 24;
		else if(i<33)
			fanShu[i] = 16;
		else if(i<38)
			fanShu[i] = 12;
		else if(i<47)
			fanShu[i] = 8;
		else if(i<54)
			fanShu[i] = 6;
		else if(i<58)
			fanShu[i] = 4;
		else if(i<68)
			fanShu[i] = 2;
		else
			fanShu[i] = 1;
	}
/********************��������**************************/	
	func[(int)DaSiXi] = &SuanFan::daSiXi;
	func[(int)DaSanYuan] = &SuanFan::daSanYuan;
	func[(int)LvYiSe] = &SuanFan::lvYiSe;
	func[(int)JiuBaoLianDeng] = &SuanFan::jiuBaoLianDeng;
	func[(int)SiGang] = &SuanFan::siGang;
	//func[(int)LianQiDui] = &SuanFan::lianQiDui;
	//func[(int)ShiSanYao] = &SuanFan::shiSanYao;
	func[(int)QingYaoJiu] = &SuanFan::qingYaoJiu;
	func[(int)XiaoSiXi] = &SuanFan::xiaoSiXi;
	func[(int)XiaoSanYuan] = &SuanFan::xiaoSanYuan;
	func[(int)ZiYiSe] = &SuanFan::ziYiSe;
	func[(int)SiAnKe] = &SuanFan::siAnKe;
	func[(int)YiSeShuangLongHui] = &SuanFan::yiSeShuangLongHui;
	func[(int)YiSeSiTongShun] = &SuanFan::yiSeSiTongShun;
	func[(int)YiSeSiJieGao] = &SuanFan::yiSeSiJieGao;
	func[(int)YiSeSiBuGao] = &SuanFan::yiSeSiBuGao;
	func[(int)SanGang] = &SuanFan::sanGang;
	func[(int)HunYaoJiu] = &SuanFan::hunYaoJiu;
	//func[(int)QiDui] = &SuanFan::qiDui;
	//func[(int)QiXingBuKao] = &SuanFan::qiXingBuKao;
	func[(int)QuanShuangKe] = &SuanFan::quanShuangKe;
	func[(int)QingYiSe] = &SuanFan::qingYiSe;
	func[(int)YiSeSanJieGao] = &SuanFan::yiSeSanJieGao;
	func[(int)YiSeSanTongShun] = &SuanFan::yiSeSanTongShun;
	func[(int)QuanDa] = &SuanFan::quanDa;
	func[(int)QuanZhong] = &SuanFan::quanZhong;
	func[(int)QuanXiao] = &SuanFan::quanXiao;
	func[(int)QingLong] = &SuanFan::qingLong;
	func[(int)SanSeShuangLongHui] = &SuanFan::sanSeShuangLongHui;
	func[(int)YiSeSanBuGao] = &SuanFan::yiSeSanBuGao;
	func[(int)QuanDaiWu] = &SuanFan::quanDaiWu;
	func[(int)SanTongKe] = &SuanFan::sanTongKe;
	func[(int)SanAnKe] = &SuanFan::sanAnKe;
	//func[(int)QuanBuKao] = &SuanFan::quanBuKao;
	func[(int)ZuHeLong] = &SuanFan::zuHeLong;
	func[(int)DaYuWu] = &SuanFan::daYuWu;
	func[(int)XiaoYuWu] = &SuanFan::xiaoYuWu;
	func[(int)SanFengKe] = &SuanFan::sanFengKe;
	func[(int)HuaLong] = &SuanFan::huaLong;
	func[(int)TuiBuDao] = &SuanFan::tuiBuDao;
	func[(int)SanSeSanTongShun] = &SuanFan::sanSeSanTongShun;
	func[(int)SanSeSanJieGao] = &SuanFan::sanSeSanJieGao;
	func[(int)WuFanHu] = &SuanFan::wuFanHu;
	func[(int)MiaoShouHuiChun] = &SuanFan::miaoShouHuiChun;
	func[(int)HaiDiLaoYue] = &SuanFan::haiDiLaoYue;
	func[(int)GangShangKaiHua] = &SuanFan::gangShangKaiHua;
	func[(int)QiangGangHu] = &SuanFan::qiangGangHu;
	func[(int)PengPengHu] = &SuanFan::pengPengHu;
	func[(int)HunYiSe] = &SuanFan::hunYiSe;
	func[(int)SanSeSanBuGao] = &SuanFan::sanSeSanBuGao;
	func[(int)WuMenQi] = &SuanFan::wuMenQi;
	func[(int)QuanQiuRen] = &SuanFan::quanQiuRen;
	func[(int)ShuangAnGang] = &SuanFan::shuangAnGang;
	func[(int)ShuangJianKe] = &SuanFan::shuangJianKe;
	func[(int)QuanDaiYao] = &SuanFan::quanDaiYao;
	func[(int)BuQiuRen] = &SuanFan::buQiuRen;
	func[(int)ShuangMingGang] = &SuanFan::shuangMingGang;
	func[(int)HuJueZhang] = &SuanFan::huJueZhang;
	func[(int)JianKe] = &SuanFan::jianKe;
	func[(int)QuanFengKe] = &SuanFan::quanFengKe;
	func[(int)MenFengKe] = &SuanFan::menFengKe;
	func[(int)MenQianQing] = &SuanFan::menQianQing;
	func[(int)PingHu] = &SuanFan::pingHu;
	func[(int)SiGuiYi] = &SuanFan::siGuiYi;
	func[(int)ShuangTongKe] = &SuanFan::shuangTongKe;
	func[(int)ShuangAnKe] = &SuanFan::shuangAnKe;
	func[(int)AnGang] = &SuanFan::anGang;
	func[(int)DuanYao] = &SuanFan::duanYao;
	func[(int)YiBanGao] = &SuanFan::yiBanGao;
	func[(int)XiXiangFeng] = &SuanFan::xiXiangFeng;
	func[(int)LianLiu] = &SuanFan::lianLiu;
	func[(int)LaoShaoFu] = &SuanFan::laoShaoFu;
	func[(int)MingGang] = &SuanFan::mingGang;
	func[(int)YaoJiuKe] = &SuanFan::yaoJiuKe;
	func[(int)QueYiMen] = &SuanFan::queYiMen;
	func[(int)WuZi] = &SuanFan::wuZi;
	func[(int)BianZhang] = &SuanFan::bianZhang;
	func[(int)KeZhang] = &SuanFan::keZhang;
	func[(int)DanDiaoJiang] = &SuanFan::danDiaoJiang;
	func[(int)ZiMo] = &SuanFan::ziMo;
	
		
/********************��ʼ����������***********************/	
	//����ϲ 
	fuGai[(int)QuanFengKe].pb((int)DaSiXi);
	fuGai[(int)MenFengKe].pb((int)DaSiXi);
	fuGai[(int)SanFengKe].pb((int)DaSiXi);
	fuGai[(int)PengPengHu].pb((int)DaSiXi);
	fuGai[(int)YaoJiuKe].pb((int)DaSiXi);
	fuGai[(int)XiaoSiXi].pb((int)DaSiXi);
	fuGai[(int)QueYiMen].pb((int)DaSiXi);
	//����Ԫ 
	fuGai[(int)ShuangJianKe].pb((int)DaSanYuan);
	fuGai[(int)JianKe].pb((int)DaSanYuan);
	fuGai[(int)XiaoSanYuan].pb((int)DaSanYuan);
	fuGai[(int)QueYiMen].pb((int)DaSanYuan);
	//��һɫ 
	fuGai[(int)HunYiSe].pb((int)LvYiSe);
	fuGai[(int)QueYiMen].pb((int)LvYiSe);
	//�ű����� 
	fuGai[(int)QingYiSe].pb((int)JiuBaoLianDeng);
	fuGai[(int)BuQiuRen].pb((int)JiuBaoLianDeng);
	fuGai[(int)MenQianQing].pb((int)JiuBaoLianDeng);
	fuGai[(int)YaoJiuKe].pb((int)JiuBaoLianDeng);
	fuGai[(int)QueYiMen].pb((int)JiuBaoLianDeng);
	fuGai[(int)WuZi].pb((int)JiuBaoLianDeng);
	//�ĸ�
	fuGai[(int)SanGang].pb((int)SiGang);
	fuGai[(int)PengPengHu].pb((int)SiGang);
	fuGai[(int)ShuangAnGang].pb((int)SiGang);
	fuGai[(int)AnGang].pb((int)SiGang);
	fuGai[(int)MingGang].pb((int)SiGang);
	fuGai[(int)DanDiaoJiang].pb((int)SiGang); 
	//���߶�
	fuGai[(int)QingYiSe].pb((int)LianQiDui); 
	fuGai[(int)BuQiuRen].pb((int)LianQiDui);
	fuGai[(int)DanDiaoJiang].pb((int)LianQiDui);
	fuGai[(int)QiDui].pb((int)LianQiDui);
	fuGai[(int)MenQianQing].pb((int)LianQiDui);
	fuGai[(int)QueYiMen].pb((int)LianQiDui);
	fuGai[(int)WuZi].pb((int)LianQiDui);
	//ʮ����
	fuGai[(int)WuMenQi].pb((int)ShiSanYao);
	fuGai[(int)BuQiuRen].pb((int)ShiSanYao);
	fuGai[(int)DanDiaoJiang].pb((int)ShiSanYao); 
	fuGai[(int)QuanDaiYao].pb((int)ShiSanYao);
	fuGai[(int)MenQianQing].pb((int)ShiSanYao);
	//���۾�
	fuGai[(int)PengPengHu].pb((int)QingYaoJiu); 
	fuGai[(int)ShuangTongKe].pb((int)QingYaoJiu);
	fuGai[(int)WuZi].pb((int)QingYaoJiu);
	fuGai[(int)HunYaoJiu].pb((int)QingYaoJiu);
	fuGai[(int)QuanDaiYao].pb((int)QingYaoJiu);
	fuGai[(int)YaoJiuKe].pb((int)QingYaoJiu);
	//С��ϲ 
	fuGai[(int)SanFengKe].pb((int)XiaoSiXi);
	fuGai[(int)YaoJiuKe].pb((int)XiaoSiXi);
	fuGai[(int)QueYiMen].pb((int)XiaoSiXi);
	//С��Ԫ
	fuGai[(int)JianKe].pb((int)XiaoSanYuan);
	fuGai[(int)ShuangJianKe].pb((int)XiaoSanYuan);
	fuGai[(int)QueYiMen].pb((int)XiaoSanYuan); 
	//��һɫ
	fuGai[(int)PengPengHu].pb((int)ZiYiSe); 
	fuGai[(int)HunYaoJiu].pb((int)ZiYiSe);
	fuGai[(int)QuanDaiYao].pb((int)ZiYiSe);
	fuGai[(int)YaoJiuKe].pb((int)ZiYiSe);
	fuGai[(int)QueYiMen].pb((int)ZiYiSe);
	//�İ���
	fuGai[(int)MenQianQing].pb((int)SiAnKe);
	fuGai[(int)PengPengHu].pb((int)SiAnKe);
	fuGai[(int)BuQiuRen].pb((int)SiAnKe);
	fuGai[(int)ShuangAnKe].pb((int)SiAnKe);  
	//һɫ˫����
	fuGai[(int)PingHu].pb((int)YiSeShuangLongHui);
	fuGai[(int)QiDui].pb((int)YiSeShuangLongHui);  
	fuGai[(int)QingYiSe].pb((int)YiSeShuangLongHui);  
	fuGai[(int)YiBanGao].pb((int)YiSeShuangLongHui);  
	fuGai[(int)LaoShaoFu].pb((int)YiSeShuangLongHui);
	fuGai[(int)QueYiMen].pb((int)YiSeShuangLongHui);
	fuGai[(int)WuZi].pb((int)YiSeShuangLongHui);
	//һɫ��ͬ˳
	fuGai[(int)YiSeSanJieGao].pb((int)YiSeSiTongShun);      
	fuGai[(int)YiSeSanTongShun].pb((int)YiSeSiTongShun);      
	fuGai[(int)YiBanGao].pb((int)YiSeSiTongShun);      
	fuGai[(int)SiGuiYi].pb((int)YiSeSiTongShun);      
	fuGai[(int)QueYiMen].pb((int)YiSeSiTongShun);      
	//һɫ�Ľڸ�
	fuGai[(int)YiSeSanTongShun].pb((int)YiSeSiJieGao);       
	fuGai[(int)PengPengHu].pb((int)YiSeSiJieGao);      
	fuGai[(int)YiSeSanJieGao].pb((int)YiSeSiJieGao);      
	fuGai[(int)QueYiMen].pb((int)YiSeSiJieGao);      
	//һɫ�Ĳ���
	fuGai[(int)YiSeSanBuGao].pb((int)YiSeSiBuGao);
	fuGai[(int)QueYiMen].pb((int)YiSeSiBuGao);
	//���� 
	fuGai[(int)ShuangAnGang].pb((int)SanGang);
	fuGai[(int)ShuangMingGang].pb((int)SanGang);
	fuGai[(int)AnGang].pb((int)SanGang);
	fuGai[(int)MingGang].pb((int)SanGang);
	//���۾�
	fuGai[(int)PengPengHu].pb((int)HunYaoJiu);
	fuGai[(int)QuanDaiYao].pb((int)HunYaoJiu);
	fuGai[(int)YaoJiuKe].pb((int)HunYaoJiu);
	//�߶�
	fuGai[(int)BuQiuRen].pb((int)QiDui);
	fuGai[(int)DanDiaoJiang].pb((int)QiDui);
	fuGai[(int)MenQianQing].pb((int)QiDui);
	//���ǲ���
	fuGai[(int)WuMenQi].pb((int)QiXingBuKao);
	fuGai[(int)BuQiuRen].pb((int)QiXingBuKao);
	fuGai[(int)DanDiaoJiang].pb((int)QiXingBuKao);
	fuGai[(int)QuanBuKao].pb((int)QiXingBuKao);
	fuGai[(int)MenQianQing].pb((int)QiXingBuKao);
	//ȫ˫��
	fuGai[(int)DuanYao].pb((int)QuanShuangKe);
	fuGai[(int)PengPengHu].pb((int)QuanShuangKe);
	fuGai[(int)DuanYao].pb((int)QuanShuangKe);
	fuGai[(int)WuZi].pb((int)QuanShuangKe);
	//��һɫ
	fuGai[(int)WuZi].pb((int)QingYiSe);
	fuGai[(int)QueYiMen].pb((int)QingYiSe); 
	//һɫ���ڸ�
	fuGai[(int)YiSeSanTongShun].pb((int)YiSeSanJieGao); 
	//һɫ��ͬ˳
	fuGai[(int)YiBanGao].pb((int)YiSeSanTongShun); 
	fuGai[(int)YiSeSanJieGao].pb((int)YiSeSanTongShun);
	//ȫ��
	fuGai[(int)DaYuWu].pb((int)QuanDa); 
	fuGai[(int)WuZi].pb((int)QuanDa); 
	//ȫ�� 
	fuGai[(int)DuanYao].pb((int)QuanZhong); 
	fuGai[(int)WuZi].pb((int)QuanZhong); 
	//ȫС
	fuGai[(int)WuZi].pb((int)QuanXiao); 
	fuGai[(int)XiaoYuWu].pb((int)QuanXiao); 
	//����
	fuGai[(int)LianLiu].pb((int)QingLong);  
	//��ɫ˫����
	fuGai[(int)XiXiangFeng].pb((int)SanSeShuangLongHui);  
	fuGai[(int)LaoShaoFu].pb((int)SanSeShuangLongHui);
	fuGai[(int)WuZi].pb((int)SanSeShuangLongHui);
	fuGai[(int)PingHu].pb((int)SanSeShuangLongHui);
	fuGai[(int)YiBanGao].pb((int)SanSeShuangLongHui);
	//ȫ����
	fuGai[(int)DuanYao].pb((int)QuanDaiWu); 
	fuGai[(int)WuZi].pb((int)QuanDaiWu);
	//��ͬ��
	fuGai[(int)ShuangTongKe].pb((int)SanTongKe); 
	//������ 
	fuGai[(int)ShuangAnKe].pb((int)SanAnKe);
	//ȫ����
	fuGai[(int)WuMenQi].pb((int)QuanBuKao);
	fuGai[(int)BuQiuRen].pb((int)QuanBuKao);
	fuGai[(int)DanDiaoJiang].pb((int)QuanBuKao);
	fuGai[(int)MenQianQing].pb((int)QuanBuKao);
	//������
	fuGai[(int)WuZi].pb((int)DaYuWu); 
	//�����
	fuGai[(int)YaoJiuKe].pb((int)SanFengKe); 
	fuGai[(int)QueYiMen].pb((int)SanFengKe);
	//�Ʋ��� 
	fuGai[(int)QueYiMen].pb((int)TuiBuDao); 
	//��ɫ��ͬ˳
	fuGai[(int)XiXiangFeng].pb((int)SanSeSanTongShun); 
	//���ֻش�
	fuGai[(int)ZiMo].pb((int)MiaoShouHuiChun); 
	//���Ͽ���
	fuGai[(int)ZiMo].pb((int)GangShangKaiHua); 
	//���ܺ�
	fuGai[(int)HuJueZhang].pb((int)QiangGangHu); 
	//ȫ����
	fuGai[(int)DanDiaoJiang].pb((int)QuanQiuRen); 
	//Ȧ���
	//fuGai[(int)YaoJiuKe].pb((int)QuanFengKe);  
	//�ŷ�� 
	//fuGai[(int)YaoJiuKe].pb((int)MenFengKe); 
	//ƽ��
	fuGai[(int)WuZi].pb((int)PingHu);  
	//����
	fuGai[(int)WuZi].pb((int)DuanYao);  
	//������(���)
	fuGai[(int)MenQianQing].pb((int)BuQiuRen);  
	fuGai[(int)ZiMo].pb((int)BuQiuRen);	
}





