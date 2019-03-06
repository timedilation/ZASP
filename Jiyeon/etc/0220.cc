/*
 * https://leetcode.com/problems/jump-game-ii/
 */

#include <iostream>
#include <vector>
using namespace::std;

int canJump(vector<int>& nums)
{
    vector<int> jmpCnt2Reach(nums.size(), -1);
    jmpCnt2Reach[nums.size()-1] = 0;
    for(int i=nums.size()-2; i>=0; i--) {
        int max = (i+nums[i] >= nums.size()) ? nums.size()-1 : i+nums[i];
        int minCnt = nums.size();
        for(int j=i+1; j<=max; j++) {
            if(jmpCnt2Reach[j] != -1)
                minCnt = (minCnt > jmpCnt2Reach[j] + 1) ? jmpCnt2Reach[j]+1 : minCnt;
        }
        if(minCnt != nums.size())
            jmpCnt2Reach[i] = minCnt;
    }
    return jmpCnt2Reach[0];
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
    cout << canJump(nums) << endl;
    return 0;
}
