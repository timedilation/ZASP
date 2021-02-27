// 백준 2482 색상환 - DP
// 원형이지만 1번 N번 색 동시 선택 말고는 그냥 선형으로 간주
// 마지막만 예외: dp[N][K] = dp[N-1][K] + dp[N-3][K-1]
#include <iostream>
#include <vector>
#define DIVIDER 1000000003
using namespace std;

void fill_dp_table(vector<vector<int> > &dp) {
    int colors = dp.size()-1, choices = dp[0].size()-1;
    for (int i = 2; i <= colors; i++) {
        int cnt = min(i, choices);
        dp[i][1] = i;
        for (int j = 2; j <= cnt; j++) {
            dp[i][j] = (dp[i-1][j] + dp[i-2][j-1]) % DIVIDER;
        }
    }
    dp[colors][choices] = (dp[colors-1][choices] + dp[colors-3][choices-1]) % DIVIDER;
}

int main(void){
    int colors, choices;
    scanf("%d %d", &colors, &choices);
    vector<vector<int> > dp_table(colors+1, vector<int>(choices+1, 0));
    dp_table[0][0] = 0;
    dp_table[1][0] = 1;
    dp_table[1][1] = 1;

    fill_dp_table(dp_table);
    printf("%d", dp_table[colors][choices]);

    return 0;
}