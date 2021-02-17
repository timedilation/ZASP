// DP with bitmask
#include <iostream>
#include <vector>
#define INT_MAX 987654321
using namespace std;

// dp 배열크기는 최대  20 * pow(2, 20) * integer 4 byte => 80MB
// 문제 메모리 조건이 128MB이므로 가능
int dfs_with_bitmask(int num_of_works, int left_works, int bitmask, 
        vector<vector<int> > &costs, vector<vector<int> > &dp) {
    
    // for (int i = 0; i < num_of_works; i++)
    // {
    //     for (int j = 0; j < 8; j++)
    //     {
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("--------\n");
    
    if (left_works <= 0){
        // end of recursion
        return 0;
    }
    int curr_idx = left_works-1;
    if (dp[curr_idx][bitmask]) {
        // already computed
        return dp[curr_idx][bitmask];
    }

    int result = INT_MAX;
    for (int i = 0; i < num_of_works; i++){
        if(not (bitmask & (1 << i))) {
            bitmask |= (1 << i);
            result = min(result, 
                        dfs_with_bitmask(num_of_works, left_works-1, bitmask, costs, dp) + costs[curr_idx][i]);
            bitmask &= ~(1 << i);
        }
    }

    dp[curr_idx][bitmask] = result;
    return result;
}

int main(void) {
    int num_of_work; // == num of people
    scanf("%d", &num_of_work);
    vector<bool> visited(num_of_work, false);
    vector<vector<int> > costs(num_of_work, vector<int>(num_of_work));
    vector<vector<int> > dp(num_of_work, vector<int>(1 << (num_of_work), 0));        

    for (int i = 0; i < num_of_work; i++) {
        for (int j = 0; j < num_of_work; j++) {
            scanf("%d", &costs[i][j]);
        }
    }

    int initial_bitmask = 0;
    printf("%d", dfs_with_bitmask(num_of_work, num_of_work, initial_bitmask, costs, dp));

    return 0;
}