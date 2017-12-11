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
	}

}