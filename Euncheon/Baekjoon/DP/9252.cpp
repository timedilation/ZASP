//dynamic programming + backtracking

// testing input:
// ABBAABABAA
// BACKKKADBDA
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int max_int(int a, int b) {
    return a > b ? a : b;
}
int get_LCS_length(string &A, string &B){
    int longest;//output
	
    // length of input
    int m = A.size(), n = B.size();
    // init first row / column to 0
    for(int i = 0; i <= m; i++)
        dp[i][0] = 0;
    for(int i = 0; i <= n; i++)
        dp[0][i] = 0;
    
    //
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(A[i-1] == B[j-1]) // same character
                dp[i][j] = dp[i-1][j-1] + 1;
            else // differnt character
                dp[i][j] = max_int(dp[i-1][j], dp[i][j-1]);
        }
    }

    longest = dp[m][n];
    return longest;
}

void print_dp_for_debug(string &A, string &B) {
	int m = A.size(), n = B.size();
	
    printf("    ");
    for (auto c : A) {
        printf("%c ", c);
    }
    printf("\n");
    for (int i = 0; i <= n; i++){
        if (i != 0)
            printf("%c ", B[i-1]);
        else printf("  ");
        for (int j = 0; j <= m; j++) {
            printf("%d ", dp[j][i]);
        }
        printf("\n");
    }
}

string backtracking(string &A, string &B){
    string lcs;
	int m = A.size(), n = B.size();
    
    // check changed points
	while(dp[m][n] > 0) {
        if(dp[m][n] == dp[m][n-1]){
            n--;
        }
        else if (dp[m][n] == dp[m-1][n]){
            m--;
        }
        else if (dp[m][n] == dp[m-1][n-1] + 1){
            lcs += A[m-1];
            n--;
            m--;
        }
    }
	
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main(void){
    string A, B;
    cin >> A >> B;

    int longest = get_LCS_length(A, B);
    // print_dp_for_debug(A, B);
    string lcs = backtracking(A, B);
    
    cout << longest << endl;
    cout << lcs;

    return 0;
}