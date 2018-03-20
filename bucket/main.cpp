#include <iostream>
#include <deque> 
using namespace std;

#ifndef MYHEAD_H
    #define MYHEAD_H
    #include "myhead.h"
#endif

bool IsSameBucketState(BucketState state1, BucketState state2) {
    return state1.IsSameState(state2);
}

bool IsProcessedState(deque<BucketState>& states, const BucketState& newState) {
    deque<BucketState>::iterator it = states.end();
    it = find_if(states.begin(), states.end(),
        bind2nd(ptr_fun(IsSameBucketState), newState));

    return (it != states.end());
}

void PrintResult(deque<BucketState>& states) {
    cout<<"Find Result:" <<endl;
    for_each(states.begin(), states.end(),
        mem_fun_ref(&BucketState::PrintStates));
    cout<<endl<<endl;
}
void SearchState(deque<BucketState> &states);

void SearchStateOnAction(deque<BucketState> & states, BucketState& current, int from, int to) {
   if(IsCurrentActionValid(current, from, to)) {
      BucketState next;

      bool dDump = current.DumpWater(from, to, next); //执行当前状态下的下一次倒水
      if(dDump && !IsProcessedState(states, next)) {
          states.push_back(next);
          SearchState(states);
          states.pop_back();
      }
   }
}

void SearchState(deque<BucketState> &states)
{
    BucketState current = states.back();
    if (current.IsFinalState()) {
        PrintResult(states);
    }

    for (int j=0; j<buckets_count; ++j) {
        for (int i=0; i<buckets_count; ++i) {
            SearchStateOnAction(states, current, i, j);
        }
    }
}

int main (){

    deque<BucketState> states;

    BucketState init;

    states.push_back(init);
    SearchState(states);
    return 0;
}