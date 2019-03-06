/*
    https://leetcode.com/problems/jump-game/
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace::std;

bool canJump(vector<int>& nums)
{
    vector<bool> canReachFrom(nums.size(), false);
    canReachFrom[nums.size()-1] = true;
    for(int i=nums.size()-1; i>=0; i--) {
        int max = (nums[i]+i > nums.size()-1) ? nums.size()-1 : nums[i];
        for(int j=max; j>=0; j--) {
            if(canReachFrom[i+j] == true) {
                canReachFrom[i] = true;
                break;
            }
        }
    }

    return canReachFrom[0];
}
int main()
{
    int N;
    vector<int> nums;
    cin >> N;
    while(N-- > 0) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    if(canJump(nums))
        cout << "can" << endl;
    else
        cout << "can\'t" << endl;
    return 0;
}
