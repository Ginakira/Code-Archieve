#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
void dfs(string a,string b){
    if (a.size() > 0){
        char ch = b[b.size() - 1];
        cout<<ch;
        int k = a.find(ch);
        dfs(a.substr(0,k),b.substr(0,k));
        dfs(a.substr(k+1),b.substr(k,a.size()-k-1));
    }
}
int main(){
    string a, b;
    cin>>a;
	cin>>b;
    dfs(a,b);
	cout<<endl;
    return 0;
}
//a.substr(0,k)
//����ַ���s�� �ӵ�0λ��ʼ�ĳ���Ϊk���ַ��� // Ĭ��ʱ�ĳ���Ϊ�ӿ�ʼλ�õ�β
