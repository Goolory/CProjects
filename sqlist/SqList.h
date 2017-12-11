#ifndef MYHEAD_H
	#define MYHEAD_H
	#include "myhead.h"
#endif

#define LIST_MAX_SIZE 100
#define LISTINCREMENT 10


template <typename T>
class SqList
{
public:
	//有序顺序表折半查找
	int bin_Search(T key);
	// 置空顺序表
	void clear();
	// 删除第i个元素
	Status deleteElem(int i, T &e);
	// 取第i个元素
	Status getElem(int i, T &e);
	// 求顺序表中元素个数
	int getLength();
	// 取顺序表存储空间大小
	int getListSize();
	// 在第i个元素之前插入一个元素
	Status insret(int i, T e);
	// 判断是否为空
	bool isEmpty();
	// 查找第i个元素页e满足compare()关系的元素序号
	int locateElem(T e, Status(*compare)(T, T));
	// 返回某个元素的后继
	Status nextElem(T e, T& next_e);
	// 重载赋值运算符的定义
	SqList<T> operator = (SqList<T> rightT);
	// 返回某元素的前驱
	Status priorElem(T e, T& prior_e);
	// 在顺序表中查找某个元素
	int sequentialSearch(T e);
	// 随机生成顺序表
	Status rangeSqList();

	SqList();
	virtual ~SqList();
	SqList(const SqList<T>& otherL);

protected:
	T *elem;
	int listSize;
	int n;
	
};
template <typename T>
Status SqList<T>::rangeSqList(){
	for (int i = 0; i<7; i++){
		elem[i] = (rand() % (10)); 
	}
	n = 6;
	return OK;
}
// /有序顺序表折半查找
template <typename T>
int SqList<T>::bin_Search(T key){
	int low, mid, high;

	low = 0, high = n - 1;
	while(low <= high){
		mid = (high - low) / 2;

		if(elem[mid] == key)
			return mid+1;
		else if (elem[mid] < key)
			low = mid + 1;
		else if (elem[mid] > key)
			high = mid -1;
	}
	return 0;
}

template <typename T>
void SqList<T>::clear(){
	n = 0;
}

// 删除第i个元素
template <typename T>
Status SqList<T>::deleteElem(int i, T& e){
	if (i < 1 || i > n) return ERROR;
	e = elem[i-1];

	for(int j=i+1; j<=n; j++){
		elem[j-2] = elem[j-1];
	}
	n--;
	return OK;
}

// 取第i个元素
template <typename T>
Status SqList<T>::getElem(int i, T& e){
	if (i<0 || i>n) return ERROR;
	e = elem[i-1];
	return OK;
}

// 求顺序表中元素个数
template <typename T>
int SqList<T>::getLength(){
	return n;
}

// 求顺序表存储空间大小
template <typename T>
int SqList<T>::getListSize(){
	return listSize;
}

// 在第i个元素之前插入一个元素
template <typename T>
Status SqList<T>::insret(int i, T e){
	if (i<0 || i>n) return ERROR;
	T* newbase;

	if (n >= listSize){
		newbase = new T[listSize + LISTINCREMENT];
		assert(newbase != 0);
		for(int j=1; j<=n; j++){
			newbase[j-1] = elem[j-1];
		}
		delete[] elem;
		elem = newbase;
		listSize += LISTINCREMENT;
	}
	for (int j = n; j>=i ; j--)
	{
		elem[j] = elem[j-1];
	}
	elem[i-1] = e;
	++n;
	return OK;
}
// 判断是否为空
template <typename T>
bool SqList<T>::isEmpty(){
	return n?false:true;
}
// 查找第1个元素页e满足compare
template <typename T>
int SqList<T>::locateElem(T e, Status(*compare)(T, T)){
	int i=1;
	for (; i<=n && !(*compare)(elem[i-1], e); ++i);
	if (i<=n) 
		return i;
	else 
		return 0;
}
// 返回某个元素的后继
template <typename T>
Status SqList<T>::nextElem(T e, T& next_e){
	int i = locateElem(e, equal);
	if (i<1||i==n)
		return ERROR;
	else 
		getElem(i+1, next_e);
	return OK;

}
// 重载赋值运算符的定义
template <typename T>
SqList<T> SqList<T>::operator=(SqList<T> rightT){
	if (this != &rightT){
		if (listSize < rightT.listSize){
			delete[] elem;
			elem = new T[rightT.listSize];
			assert(elem != 0);
			listSize = rightT.listSize;
		}
		n = rightT.n;
		for(int i=1; i<=n; ++i)
			elem[i-1] = rightT[i-1];
	}
	return *this;
}

// 返回某元素的前驱
template <typename T>
Status SqList<T>::priorElem(T e, T& prior_e){
	int i = locateElem(e, equal);
	if (i<=1)
		return ERROR;
	else
		getElem(i-1, prior_e);
	return OK;
}

template <typename T>
SqList<T>::SqList(){
	elem = new T[LIST_MAX_SIZE];
	assert(elem != 0);
	listSize = LISTINCREMENT;
	n = 0;
}

template <typename T>
SqList<T>::~SqList(){
	delete[] elem;
}

template <typename T>
SqList<T>::SqList(const SqList<T>& otherL){
	elem = new T[otherL.listSize];
	assert(elem != 0);
	listSize = otherL.listSize;
	n = otherL.n;

	for(int i = 1; i <= n; i++){
		elem[i-1] = otherL.elem[i-1];
	}
}






























