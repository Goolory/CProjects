#include<iostream>
using namespace std;

#ifndef MYSQLIST_H
	#define MYSQLIST_H
	#include "MySqList.h"
#endif

#ifndef TEST_H
	#define TEST_H
	#include "test.h"
#endif

int main(){
	MySqList<int> rec;

	int choose;
	char continueYesNo = 'N';

	while(1){
		choose = 0;
		system("clear");
		cout<<endl;
		cout<<"**************测试顺序表*************"<<endl<<endl;

		cout<<"\t 1.随机生成循环表;"<<endl;
		cout<<"\t 2.取第i个元素；"<<endl;

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
			default: cout<<"\n 你选择了结束!"<<endl<<endl;
				return 0;
		}

		if(continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}


}