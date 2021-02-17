#include <iostream>
#include <vector>
#define INT_MAX 987654321
using namespace std;


int main(void) {
    int num_of_houses;
    scanf("%d", &num_of_houses);
    vector<vector<int> > costs(num_of_houses, vector<int>(3));
    for (int i = 0; i < num_of_houses; i++) {
        scanf("%d %d %d", &(costs[i][0]), &(costs[i][1]), &(costs[i][2]));
    }

    int result = INT_MAX;

    // color: 0: red, 1: green, 2: blue
    for (int first_color = 0; first_color < 3; first_color++) {
        vector<vector<int> > dp(num_of_houses, vector<int>(3, INT_MAX));
        dp[0][first_color] = costs[0][first_color];

        for (int house_idx = 1; house_idx < num_of_houses; house_idx++) {
            dp[house_idx][0] = min(dp[house_idx-1][1], dp[house_idx-1][2]) + costs[house_idx][0];
            dp[house_idx][1] = min(dp[house_idx-1][0], dp[house_idx-1][2]) + costs[house_idx][1];
            dp[house_idx][2] = min(dp[house_idx-1][0], dp[house_idx-1][1]) + costs[house_idx][2];
        }
        
        for (int curr_color = 0; curr_color < 3; curr_color++) {
            if (first_color != curr_color){
                result = min(result, dp[num_of_houses-1][curr_color]);
            }
        }   
    }
    
    printf("%d", result);
    
    return 0;
}