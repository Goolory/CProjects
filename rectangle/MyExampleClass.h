#ifndef EXAMPLECLASS_H
	#define EXAMPLECLASS_H
	#include "/Users/xiesheng/Cprojects/ExampleClass.h"
#endif

template<typename T>
class MyRectangle:public Rectangle<T>
{
public:
	void read(istream &in);

	void display(ostream &out) const;
	
};

template<typename T>
void MyRectangle<T>::read(istream &in){
	cout<<"   请输入第"<<MyRectangle::myNo.no<<"个长方形对象"<<endl;
	cout<<"   长方形的长";
	in>>MyRectangle::length;
	cout<<"   长方形的宽";
	in>>MyRectangle::width;
}

template<typename T>
istream& operator>>(istream& in, MyRectangle<T>& iD){
	iD.read(in);
	return in;
}

template<typename T>
void MyRectangle<T>::display(ostream &out) const{
	out<<"  第"<<MyRectangle::myNo.no<<"个长方形对象 长="<<MyRectangle::length<<"\t 宽="<<MyRectangle::width<<endl;
}

template<typename T>
ostream& operator<<(ostream& out, const MyRectangle<T> & oD){
	oD.display(out);
	return out;
}