template <typename T>
class Rectangle
{
public:
	class RectangleNo
	{
	public:
		int no;
		
	};

	Rectangle operator = (Rectangle rightR);

	void setLength(T l);

	void setNo(int i);

	Rectangle();

	Rectangle(const Rectangle <T> & otherD);

	virtual ~Rectangle();

protected:
	T length;
	T width;
	RectangleNo myNo;
	
};


template <typename T>
Rectangle<T> Rectangle<T>::operator = (Rectangle <T> rightR){
	if (this != &rightR) {
		length = rightR.length;
		width = rightR.width;
		myNo = rightR.myNo;

		cout<<"    赋值后，当前长方形为（"<<length<<","<<width<<")"<<endl;
	}
	return *this;
}

template<typename T>
void Rectangle<T>::setLength(T l) {
	length = l;
}

template<typename T>
void Rectangle<T>::setNo(int i){
	myNo.no = i;
}

template<typename T>
Rectangle<T>::Rectangle(){
	width = length = 0;
	cout<<"   自动调用函数"<<endl;
}

template<typename T>
Rectangle<T>::Rectangle(const Rectangle<T> & otherD){
	length = otherD.length;
	width = otherD.width;
	myNo = otherD.myNo;
	cout<<"  自动调用拷贝初始化构造函数初始化为（";
	cout<<length<<","<<width<<")"<<endl;
}

template<typename T>
Rectangle<T>::~Rectangle(){
	cout<<"   第"<<myNo.no<<"个长方形对象（"<<length<<","<<width<<")生存周期结束！"<<endl;
}