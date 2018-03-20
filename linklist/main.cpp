#include<iostream>
using namespace std;

#ifndef MYLINKLIST_H
	#define MYLINKLIST_H
	#include "MyLinkList.h"
#endif

#ifndef TEST_H
	#define TEST_H
	#include "test.h"
#endif

int main(){
	MyLinkList<int> rec;
	int choose;

	char continueYesNo = 'n';

	while(1){
		choose = 0;
		system("clear");
		cout<<endl;
		cout<<"*******************测试顺序链表*******************"<<endl<<endl;

		cout<<"\t 1.随机生成表;"<<endl;
		cout<<"\t 2.倒置表；"<<endl;

		cout<<" 其他，结束！"<<endl;
		cout<<"/////////////////////////////////////////"<<endl<<endl;
		displayObject(rec);
		cout<<"/////////////////////////////////////////"<<endl<<endl;

		cout<<"请输入操作码！";
		cin>>choose;
		if(choose>0 && choose <2){
			system("clear");
			displayObject(rec);
		}

		switch(choose){
			case 1: ex_1(rec, continueYesNo);
				break;
			case 2: ex_2(rec, continueYesNo);
				break;
			default: cout<<"你选择了结束"<<endl;
				return 0;
		}
		if (continueYesNo == 'n' || continueYesNo == 'N')
			return 0;
	}
	return 0;

}