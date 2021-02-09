#include <cstdio>
using namespace std;

int coin[101];
int dp[10001];
int min = 0;

int main(void){
    int n, k;
    scanf("%d %d", &n, &k);
    
    for (int i = 1; i <= k; i++){
        dp[i] = 987654321;
    }
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &coin[i]);
        for (int j = coin[i]; j <= k; j++) {
            if(coin[i] <= j) {
                dp[j] = (dp[j] <=  dp[j-coin[i]] + 1) ? dp[j] : dp[j-coin[i]]+1;
            }
        }
    }
     
    printf("%d", dp[k] != 987654321 ? dp[k] : -1); 

    return 0;
}