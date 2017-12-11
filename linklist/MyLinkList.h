#ifndef LINKLIST_H
	#define LINKLIST_H
	#include "LinkList.h"
#endif

template<typename T>
class MyLinkList:public LinkList<T>
{
public:
	void read(istream &in);

	void display(ostream &out) const;
	
};

template<typename T>
void MyLinkList<T>::read(istream &in){
	
}

template<typename T>
istream& operator>>(istream& in, MyLinkList<T>& iD){
	iD.read(in);
	return in;
}

template<typename T>
void MyLinkList<T>::display(ostream &out) const{
	MyLinkList::NodePointer p;
	p = MyLinkList::head;
	cout<<"head"<<endl;
	cout<<"|"<<endl;
	while(p){
		cout<<p->data<<"->";
	}
	cout<<"NULL";
	cout<<endl;
}

template<typename T>
ostream& operator<<(ostream& out, const MyLinkList<T> & oD){
	oD.display(out);
	return out;
}