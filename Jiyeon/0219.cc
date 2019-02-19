/*
    https://leetcode.com/problems/jump-game/
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace::std;

bool canJump(vector<int>& nums)
{
    vector<bool> isVisited(nums.size(), false);
    queue<int> nextVisit;
    nextVisit.push(0);
    while(nextVisit.empty() == false) {
        int visitIndex = nextVisit.front();
        nextVisit.pop();
        if(visitIndex + nums[visitIndex] >= nums.size()-1)
            return true;
        for(int i = nums[visitIndex]; i>0; i--) {
            if(isVisited[visitIndex + i] == false) {
                nextVisit.push(visitIndex + i);
                isVisited[visitIndex + i] = true;
            }
        }
    }
    return false;
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
