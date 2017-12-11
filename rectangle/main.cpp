#include<iostream>
using namespace std;

#ifndef MYEXAMPLECLASS_H
	#define MYEXAMPLECLASS_H
	#include "/Users/xiesheng/Cprojects/MyExampleClass.h"
#endif

int main(){
	float al = (float)8.2;
	MyRectangle<int> d1;
	MyRectangle<float> d2, d3;

	d1.setNo(1);
	d2.setNo(2);
	d3.setNo(3);

	cout<<d1<<d2<<d3<<endl;

	cin>>d1>>d2;

	cout<<d1<<d2;


}
