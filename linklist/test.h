template<typename T>
void displayObject(MyLinkList<T> rec){
	cout<<endl;
	cout<<rec;
}

template<typename T>
void ex_1(MyLinkList<T> &rec, char& continueYesNo){
	rec.rangLinkList();
	cout<<"当前链表为："<<endl;

	cout<<rec;

	cout<<"***********************************"<<endl<<endl;
	cout<<"还继续？（y.继续\tN.结束）";
	cin>>continueYesNo;
} 

template<typename T>
void ex_2(MyLinkList<T> &rec, char& continueYesNo){
	cout<<"倒置链表"<<endl;
	rec.adverse();

	cout<<rec;

	cout<<"***********************************"<<endl<<endl;
	cout<<"还继续？（y.继续\tN.结束）";
	cin>>continueYesNo;

}