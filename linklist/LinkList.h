#ifndef MYHEAD_H
	#define MYHEAD_H
	#include "myhead.h"
#endif
template <typename T>
class LinkList
{
public:
	class LinkNode
	{
	public:
		T data;
		LinkNode *next;
	};

	typedef LinkNode* NodePointer;
	// 随机生成链表
	void rangLinkList();
	// 把非循环列表逆置
	void adverse();
	// 清空链表
	void clean();
	LinkList();
	// 初始化拷贝函数
	LinkList(const LinkList<T>& otherL);
	virtual ~LinkList();
protected:
	NodePointer head;
	
};
template <typename T>
void LinkList<T>:: rangLinkList(){
	NodePointer s, p;
	head = p = NULL;
	for (int i = 0; i < 7; ++i)
	{
		s = new LinkNode;
		assert(s != 0);

		s->data = (rand() % (100)); 
		if(!head)
			head = s;
		else
			p->next = s;
		p = s;
	}
	p->next = NULL;
}

template <typename T>
void LinkList<T>::adverse(){
	NodePointer r, p, q;
	if (!head)
		return;
	r = NULL, p = head, q = p->next;
	while(p){
		p->next = r;

		r = p;
		p = q;
		if (q)
			q = q->next;
	}
	head = r;
	


}

template <typename T>
void LinkList<T>::clean(){
	NodePointer p, q;
	p = NULL, q = head;
	
	while(q){
		p = q;
		q = q->next;
		delete p;
	}
	head = NULL;
}

template <typename T>
LinkList<T>::~LinkList(){
	clean();
}

template <typename T>
LinkList<T>::LinkList(){
	head = NULL;
}

template <typename T>
LinkList<T>::LinkList(const LinkList& otherL){
	NodePointer p;
	NodePointer op = otherL.head;

	NodePointer s;
	head = p = NULL;

	while(op){
		s = new LinkNode;
		assert(s != 0);

		s->data = op->data;
		if (!head)
			head=s;
		else
			p->next = s;
		p = s;
		op = op->next;
	}
	if(head)
		p->next = NULL;
}