#include<iostream>
using namespace std;
#ifndef HEAD_H
    #define HEAD_H
    #include "head.h"
#endif

int bucket_capicity[buckets_count] = {8, 5, 3};
int bucket_init_state[buckets_count] = {8, 0, 0};
int bucket_final_state[buckets_count] = {4, 4, 0};


BucketState::BucketState(const int *buckets) {
    SetBuckets(buckets);
    SetAction(8, -1, 0);
}

BucketState::BucketState(const BucketState& state) {
    SetBuckets((const int*)state.bucket_s);
    SetAction(state.curAction.water, state.curAction.from, state.curAction.to);
}

void CopyStateArray(const int *from, int *to, int count){
    for (int i=0; i<count; i++) {
        to[i] = from[i];
    }
}


void BucketState::SetBuckets(const int *buckets){
    CopyStateArray(buckets, (int*)bucket_s, buckets_count);
}

void BucketState::SetAction(int w, int f, int t){
    curAction.water = w;
    curAction.from = f;
    curAction.to = t;
}

BucketState::BucketState(){
    SetBuckets(bucket_init_state);
    SetAction(8, -1, 0);
}




bool BucketState::IsBucketEmpty(int bucket){
   return (bucket_s[bucket] == 0);
}

bool BucketState::IsBucketFull(int bucket) {
    return (bucket_s[bucket] >= bucket_capicity[bucket]);
}

bool IsCurrentActionValid(BucketState &current, int from, int to){
    if ((from != to) && !current.IsBucketEmpty(from) && !current.IsBucketFull(to)){
        return true;
    } 

    return false;
}
bool BucketState::IsSameState(const BucketState &state)const{
    for (int i=0; i<buckets_count; i++){
        if (bucket_s[i] != state.bucket_s[i])
            return false;
    }
    return true;
}

bool BucketState::IsFinalState(){
    return IsSameState(BucketState(bucket_final_state));
}

void BucketState::PrintStates(){
    cout<< "Dump" <<curAction.water<<"water from"
        <<curAction.from+1 << "to" <<curAction.to+1<<",";
    cout<<"buckets wate states is:";
    for (int i=0; i<buckets_count; ++i) {
        cout<<bucket_s[i]<<" ";
    }
    cout<<endl;
}

void BucketState::GetBuckets(int *buckets) const{
    CopyStateArray((const int *)bucket_s, buckets, buckets_count);
}


bool BucketState::DumpWater(int from, int to, BucketState& next) {
    int bucket_water[buckets_count] = {0};

    GetBuckets(bucket_water); //获取当前状态

    int dump_water = bucket_capicity[to] - bucket_water[to];

    if (bucket_water[from] >= dump_water){
        bucket_water[to] += dump_water;
        bucket_water[from] -= dump_water;
    } else {
        bucket_water[to] += bucket_water[from];
        dump_water = bucket_water[from];
        bucket_water[from] = 0;
    }
    if (dump_water > 0) {
        next.SetBuckets(bucket_water);
        next.SetAction(dump_water, from, to);
    }
    return (dump_water > 0);
}