#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
struct Student {
	int stuno;
	char name[20];
	char password[20];
}Stu;
char stufile[] = "student.dat";
Student loginedS;
int findStudent(char * fname,char * name,char * psw,Student * teap)
{FILE * fp;
Student stu;
int no,i;
if((fp=fopen(fname,"rb"))==NULL)
{printf("\t\t�޷����ļ�������ϵͳ����Ա��ϵ��");
getchar();
exit(1);
}
while(!feof(fp))
{fread(&stu,sizeof(Student),1,fp);
if(strcmp(stu.name ,name)==0&&strcmp(stu.password ,psw)==0)
{fclose(fp);
loginedS=stu;
return 1;
}
}
fclose(fp);
return 0;
}
int main() {
	FILE *fp;
	Student t = {100, "home", "home"};
	if((fp=fopen(stufile,"rb"))==NULL) {
		if((fp=fopen(stufile,"wb+"))==NULL) {
	  	printf("\t\t�޷����ļ��У�����ϵͳ����Ա��ϵ��");
	  	getchar();
	  	exit(1);
	  	} else {
			fwrite(&t,sizeof(Student),1,fp);
			fclose(fp);
			printf("\t\t�����ܵ�һ��ʹ�ñ�ϵͳ�������û��������붼��home!");
			getchar();
    	}
		fclose(fp);
	}
	system("cls");
	int type;
	Student as;
	cout<<"���������������룬����"<<endl;
	cin>>as.name >>as.password >>type;
	if(findStudent(stufile,as.name,as.password,&loginedS)) {
		cout<<"You in it!!!";
	} else {
		cout<<" data error!!! Please try again!"<<endl;
	}
}
