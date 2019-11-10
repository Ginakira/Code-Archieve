#include<iostream>
#include<cstdio>
#include<string.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
unsigned int *x;    //��̬���� 
/* ��N!��λ����ʽ log10(1)+log10(2)+������+log10(n) ȡ����1  */
int wei(int d) {
    int i;
    double sum = 0;
    for(i = 1;i <= d;i++) {
    	sum += log10((double)i);	
	}
    /* ����Ϊ���ƣ�һλ���Ա�ʾ4���������ٴ洢�ռ� */
    return (int)((sum + 1) / 4 + 1);
}
int main() {
	int n;
	cin>>n;
	
    int i, j, jinwei, weishu = 1, temp;
    x=(unsigned int*) malloc(wei(n) * sizeof(int));
    x[0] = 1;
    for(i = 2;i <= n;i++) {
        jinwei = 0;
        for(j = 1;j <= weishu;j++) {
            temp = x[j-1] * i + jinwei;
            if (temp >= 1) {
                x[j-1] = temp % 10000;
                jinwei = temp / 10000;
            }
        }
        while(jinwei) {
            weishu++;
            x[weishu-1] = jinwei % 10000;
            jinwei /= 10000;
        }
    }
    cout<<x[weishu-1];
    for(j=weishu-2;j>=0;j--) {
    	printf("%04d",x[j]);
	}
    free(x);    
    return 0;
} 

