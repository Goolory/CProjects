#ifndef SQLISH_H
	#define SQLISH_H
	#include "SqList.h"
#endif

template <typename T>
class MySqList:public SqList<T>
{
public:
	void read(istream &in);

	void display(ostream &out) const;
	
};

template<typename T>
void MySqList<T>::read(istream &in){
	
}

template<typename T>
istream& operator>>(istream& in, MySqList<T>& iD){
	iD.read(in);
	return in;
}

template<typename T>
void MySqList<T>::display(ostream &out) const{
	for(int i = 0; i<MySqList::n; i++){
		cout<<"["<<i+1<<"] ";
	}
	cout<<endl;
	for(int i = 0; i<MySqList::n; i++){
		cout<<" "<<MySqList::elem[i]<<"  ";
	}
	cout<<endl;
}

template<typename T>
ostream& operator<<(ostream& out, const MySqList<T> & oD){
	oD.display(out);
	return out;
}