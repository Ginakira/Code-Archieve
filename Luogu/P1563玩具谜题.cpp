#include <iostream>
using namespace std;

struct Toys {//�洢��ߵĳ����Լ�ְҵ��
    int sta;
    string job;
};

struct Operation {//�洢ÿ�β����ķ����������
    int dire;
    int num;
};

int main() {
    int n, m;
    cin >> n >> m;
    Toys toy[n + 1];
    Operation oper[m + 1];
    //�ṹ����������Ϊ��ʱ�뷽�򣬽���Ϊ˳ʱ�뷽��
    for(int i = 0; i < n; ++i) {
        cin >> toy[i].sta >> toy[i].job;
    }

    for(int i = 0; i < m; ++i) {
        cin >> oper[i].dire >> oper[i].num;
    }

    int ans = 0;
    for(int i = 0; i < m; ++i) {
        //cout << "I / Ans:  " << i<< ' ' << ans << endl;
        if(toy[ans].sta == 0) {//����泯��
            if(oper[i].dire == 0){//���������
                int temp = ans - oper[i].num;
                if(temp >= 0) {
                    ans = temp;
                    continue;
                } else {
                    ans = n + temp;
                    continue;
                }
            }
            if(oper[i].dire == 1){//���������
                int temp = ans + oper[i].num;
                if(temp < n) {
                    ans = temp;
                    continue;
                } else {
                    ans = temp - n;
                    continue;
                }
            }
        }
        if(toy[ans].sta == 1) {//����泯��
            if(oper[i].dire == 1){//���������
                int temp = ans - oper[i].num;
                if(temp >= 0) {
                    ans = temp;
                    continue;
                } else {
                    ans = n + temp;
                    continue;
                }
            }
            if(oper[i].dire == 0){//���������
                int temp = ans + oper[i].num;
                if(temp < n) {
                    ans = temp;
                    continue;
                } else {
                    ans = temp - n;
                    continue;
                }
            }
        }
    }
    //cout << "I / Ans:  " << m << ' ' << ans << endl;
    cout << toy[ans].job << endl;
    return 0;
}