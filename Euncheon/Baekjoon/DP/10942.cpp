#include <iostream>
#include <vector>
using namespace std;

void check_palindromes(vector<int> &nums, vector<vector<bool> > &dp) {
    int N = nums.size();
    for (int i = 0; i < N; i++) {
        dp[i][i] = true;
    }
    for (int i = 0; i < N-1; i++){
        dp[i][i+1] = (nums[i] == nums[i+1]);
    }
    for (int dif = 2; dif < N; dif++) {
        for (int start = 0; start + dif < N; start++) {
            int end = start + dif;
            if (dp[start+1][end-1]) {
                dp[start][end] = (nums[start] == nums[end]);
            }
        }
    }
}

int main(void) {
    int num_of_nums, num_of_questions, start, end;
    scanf("%d", &num_of_nums);
    vector<int> nums(num_of_nums);
    vector<vector<bool> > is_palindrome(num_of_nums, vector<bool>(num_of_nums, false));
    for (int i = 0; i < num_of_nums; i++) {
        scanf("%d", &nums[i]);
    }

    check_palindromes(nums, is_palindrome);

    scanf("%d", &num_of_questions);
    for (int i = 0; i < num_of_questions; i++) {
        scanf("%d %d", &start, &end);
        printf("%c\n", is_palindrome[start-1][end-1] ? '1' : '0');
    }
    
    return 0;
}