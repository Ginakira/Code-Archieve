#include<iostream>
#include<string.h>
using namespace std;
#define MAXN 100501
struct NODE{
	int w;
	int to;
	int next; //next[i]��ʾ���i����ͬ������һ���ߵĴ���λ��
}edge[MAXN];
int cnt = 1;
int head[MAXN]; 
void add(int u,int v,int w){
	edge[cnt].w=w;
	edge[cnt].to=v;    //edge[i]��ʾ��i���ߵ��յ� 
	edge[cnt].next=head[u]; //head[i]��ʾ��iΪ�������һ���ߵĴ���λ�� 
	head[u]=cnt++;
}
int main(){
	memset(head,0,sizeof(head));  //�ص� 
	cnt=1;
	int n, m;
	cin>>n>>m;
	int a,b,c;
	for(int i = 1;i <= m;++i) {
		cin>>a>>b>>c;
		add(a,b,c);
	}
	for(int i = 1;i <= n;++i) {
		for(int j = head[i];j;j = edge[j].next ) {
			cout<<i<<"->"<<edge[j].to <<" "<<edge[j].w ;
			cout<<endl;
		}
	}
	return 0;
}
