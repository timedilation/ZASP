#include <iostream>
#include <vector>
#define INT_MAX 987654321
using namespace std;


class RGB {
public:
    int r, g, b;
    RGB() : r(0), g(0), b(0) {}
};

class Case {
public:
    int rr, rg, rb, gr, gg, gb, br, bg, bb;
    Case() {
        rr = rg = rb = gr = gg = gb = br = bg = bb = INT_MAX;
    }
    int get_min () {
        int result = INT_MAX;
        result = min(result, rg);
        result = min(result, rb);
        result = min(result, gr);
        result = min(result, gb);
        result = min(result, br);
        result = min(result, bg);
        return result;
    }
};

int main(void) {
    int num_of_houses;
    scanf("%d", &num_of_houses);
    vector<RGB> costs(num_of_houses, RGB());
    vector<vector<Case> > dp(num_of_houses, vector<Case>(num_of_houses, Case()));

    for (int i = 0; i < num_of_houses; i++) {
        scanf("%d %d %d", &(costs[i].r), &(costs[i].g), &(costs[i].b));
    }

    for (int i = 0; i < num_of_houses; i++) {
        dp[i][i].rr = costs[i].r;
        dp[i][i].gg = costs[i].r;
        dp[i][i].bb = costs[i].r;
    }

    for (int i = 0; i < num_of_houses-1; i++)
    {
        dp[i][i+1].rg = costs[i].r + costs[i+1].g;
        dp[i][i+1].rb = costs[i].r + costs[i+1].b;
        dp[i][i+1].gr = costs[i].g + costs[i+1].r;
        dp[i][i+1].gb = costs[i].g + costs[i+1].b;
        dp[i][i+1].br = costs[i].b + costs[i+1].r;
        dp[i][i+1].bg = costs[i].b + costs[i+1].g;
    }
    
    for (int dif = 2; dif < num_of_houses; dif++) {
        for (int start = 0; start + dif < num_of_houses; start++) {
            int end = start + dif;
            dp[start][end].rr = min(dp[start][end].rr, dp[start][end-1].rb + costs[end].r);
            dp[start][end].rr = min(dp[start][end].rr, dp[start][end-1].rg + costs[end].r);

            dp[start][end].rb = min(dp[start][end].rb, dp[start][end-1].rr + costs[end].b);
            dp[start][end].rb = min(dp[start][end].rb, dp[start][end-1].rg + costs[end].b);

            dp[start][end].rg = min(dp[start][end].rg, dp[start][end-1].rr + costs[end].g);
            dp[start][end].rg = min(dp[start][end].rg, dp[start][end-1].rb + costs[end].g);

            dp[start][end].gr = min(dp[start][end].gr, dp[start][end-1].gg + costs[end].r);
            dp[start][end].gr = min(dp[start][end].gr, dp[start][end-1].gb + costs[end].r);

            dp[start][end].gg = min(dp[start][end].gg, dp[start][end-1].gr + costs[end].g);
            dp[start][end].gg = min(dp[start][end].gg, dp[start][end-1].gb + costs[end].g);

            dp[start][end].gb = min(dp[start][end].gb, dp[start][end-1].gr + costs[end].b);
            dp[start][end].gb = min(dp[start][end].gb, dp[start][end-1].gg + costs[end].b);

            dp[start][end].br = min(dp[start][end].br, dp[start][end-1].bg + costs[end].r);
            dp[start][end].br = min(dp[start][end].br, dp[start][end-1].bb + costs[end].r);

            dp[start][end].bg = min(dp[start][end].bg, dp[start][end-1].br + costs[end].g);
            dp[start][end].bg = min(dp[start][end].bg, dp[start][end-1].bb + costs[end].g);

            dp[start][end].bb = min(dp[start][end].bb, dp[start][end-1].br + costs[end].b);
            dp[start][end].bb = min(dp[start][end].bb, dp[start][end-1].bg + costs[end].b);
        }
        
    }
    
    printf("%d", dp[0][num_of_houses-1].get_min());
    return 0;
}