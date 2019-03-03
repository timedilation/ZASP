/*
 * 시간복잡도 O(2^0+2^1+...+2^n-1) = O(2^n)
 * 처럼 보이지만.. 벡터 복사하는 시간을 고려해야 함.
 * 계산하면 n*(2^n)됨
 */
#include <iostream>
#include <vector>
using namespace::std;
vector<vector<int> > subsets(vector<int>& nums) {
    vector<vector<int> > result;
    if(nums.size() != 0) {
        int erased = nums[0];
        nums.erase(nums.begin());
        result = subsets(nums);
        int last = result.size();
        for(int i=0; i<last; i++){
            vector<int> bigSubSet = result[i];
            bigSubSet.push_back(erased);
            result.push_back(bigSubSet);
        }
    } else {
        vector<int> emptySet;
        result.push_back(emptySet);
    }
    return result;
}
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    // 이제 외부 인풋 받기도 귀찮아짐
    vector<vector<int> > result = subsets(nums);
    for(vector<vector<int> >::iterator it = result.begin(); it!=result.end(); it++) {
        for(vector<int>::iterator it2 = it->begin(); it2!=it->end(); it2++)
            cout << *it2 << " ";
        cout << endl;
    }
    return 0;
}


