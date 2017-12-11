template<typename T>
void displayObject(MySqList<T> rec){
	cout<<endl;
	cout<<rec;
}

template<typename T>
void ex_1(MySqList<T> &rec, char & continueYesNo){
	int no;
	rec.rangeSqList();
	cout<<"当前顺序表为："<<endl;

	cout<<rec;

	cout<<"***********************************"<<endl<<endl;
	cout<<"还继续？（y.继续\tN.结束）";
	cin>>continueYesNo;
} 

template<typename T>
void ex_2(MySqList<T> &rec, char &continueYesNo){
	int k;
	cout<<"请输入元素序号：";
	cin>>k;
	T e;
	if(rec.getElem(k, e) == OK) {
		cout<<"查找到该序号元素为："<<e<<endl;
	} else {
		cout<<"序号错误，超出范围"<<endl;
	}

	cout<<rec;

	cout<<"***********************************"<<endl<<endl;
	cout<<"还继续？（y.继续\tN.结束）";
	cin>>continueYesNo;

}