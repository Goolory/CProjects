#include <iostream>
#include <deque> 
using namespace std;

const int buckets_count = 3;

struct Action 
{
    int from;
    int to;
    int water;
};

struct BucketState
{
    BucketState();
    BucketState(const int *buckets);
    BucketState(const BucketState& state);
    BucketState& operator=(const BucketState& state);
    bool IsSameState(const BucketState& state) const;
    // bool IsCurrentActionValid(BucketState &current, int from, int to);
    bool IsBucketEmpty(int bucket);
    bool IsBucketFull(int bucket);
    bool IsFinalState();

    void SetBuckets(const int *buckets);
    void SetAction(int w, int f, int t);
    void PrintStates();
    void GetBuckets(int *buckets) const;
    bool DumpWater(int f, int t, BucketState& next);

    int bucket_s[buckets_count];  //向量状态
    Action curAction;   //倒水动作

};