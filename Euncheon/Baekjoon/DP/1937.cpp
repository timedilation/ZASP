// DP + DFS
#include <iostream>
#include <vector>
#define vvi vector<vector<int> >
using namespace std;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int dfs(vvi &bamboos, vvi &dp, int cx, int cy) {
    const int side = bamboos.size();
    
    if (dp[cx][cy] == 0) {
        dp[cx][cy] = 1;
        int max_adjacent = 0;
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (0 <= nx && nx < side && 0 <= ny && ny < side
                && bamboos[nx][ny] > bamboos[cx][cy]) {
                    max_adjacent = max(max_adjacent, dfs(bamboos, dp, nx, ny));
                } 
        }
        dp[cx][cy] += max_adjacent;
    }
    return dp[cx][cy];
}
void update_dp (vvi &bamboos, vvi &dp) {
    const int side = bamboos.size();
    int curr_max_days = 0;

    for (int cx = 0; cx < side; cx++) {
        for (int cy = 0; cy < side; cy++) {
            dfs(bamboos, dp, cx, cy);
        }   
    }
}

int get_max(vvi &dp) {
    int result = 0;
    const int side = dp.size();
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            result = max(result, dp[i][j]);
        }   
    }  
    return result;
}
int main(void) {
    int side;
    scanf("%d", &side);
    vvi bamboos(side, vector<int>(side));
    vvi dp(side, vector<int>(side, 0));
    
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            scanf("%d", &bamboos[i][j]);
        }
    }

    update_dp(bamboos, dp);    
    printf("%d", get_max(dp));
    return 0;
}