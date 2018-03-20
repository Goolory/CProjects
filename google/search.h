CharItem* GetChar(CharItem ci[], char c) {
	for (int i=0; i<max_char_count; i++) {
		if (ci[i].c == c) {
			return &ci[i];
		}
	}
	return NULL;
}

int MakeIntegerValue(CharItem ci[], char *st) {
	int value = 0;
	char *p = st;
	while(*p != 0) {
		CharItem *char_item = GetChar(ci, *p);
		if (char_item == NULL){
			return 0;
		}

		value = value*10 + char_item->value;
		p++;
	}

	return value;
}
void OnCharListReady(CharItem ci[max_char_count])
{
	// cout<<ci[0].c<<ci[0].value<<ci[1].c<<ci[1].value<<ci[2].c<<ci[2].value;
	// cout<<ci[3].c<<ci[3].value<<ci[4].c<<ci[4].value<<ci[5].c<<ci[5].value;
	// cout<<ci[6].c<<ci[6].value<<ci[7].c<<ci[7].value<<ci[8].c<<ci[8].value<<endl;
	char *minuend = "WWWDOT";
	char *subtrahend = "GOOGLE";
	char *diff = "DOTCOM";

	int m = MakeIntegerValue(ci, minuend);
	int s = MakeIntegerValue(ci, subtrahend);
	int d = MakeIntegerValue(ci, diff);
	// cout<<"m="<<m<<"s="<<s<<"d="<<d<<endl;

	if ((m - s) == d) {
		cout<<m<<"-"<<s<<"="<<d<<endl<<endl;
	}
}
bool IsValueVaild(CharItem cc, CharValue vv) {
	if (vv.used) {
		return false;
	}

	if (cc.leading && (vv.value == 0)) {
		return false;
	}

	return true;
}

void SearchingResult(CharItem ci[], CharValue cv[], int index, p callback) {
	if (index == max_char_count) {
		callback(ci);
		return;
	}

	for (int i = 0; i < max_number_count; i++) {
		if (IsValueVaild(ci[index], cv[i])){
			cv[i].used = true;
			ci[index].value = cv[i].value;
			SearchingResult(ci, cv, index+1, callback);
			cv[i].used = false;
		}
	}

}

