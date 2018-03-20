#include<iostream>
using namespace std;

#ifndef HEAD_H
	#define HEAD_H
	#include "head.h"
#endif

#ifndef SEARCH_H
	#define SEARCH_H
	#include "search.h"
#endif






int main(){
	CharItem char_item[max_char_count] = {{ 'W', -1, true  }, { 'D', -1, true  }, { 'O', -1, false },
										{ 'T', -1, false }, { 'G', -1, true  }, { 'L', -1, false },
										{ 'E', -1, false }, { 'C', -1, false }, { 'M', -1, false }};

	CharValue char_val[max_number_count] = { {false, 0}, {false, 1}, {false, 2}, {false, 3},{false, 4}, 
											{false, 5}, {false, 6}, {false, 7},{false, 8}, {false, 9} };
	SearchingResult(char_item, char_val, 0, OnCharListReady);

}