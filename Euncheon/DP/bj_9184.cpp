// DP 문제. 재귀 대신 DP 쓰기

#include <cstdio>
#include <cstring>
using namespace std;

int main(void){
    int w[21][21][21];
    memset(w, 0, sizeof(w));
    for (int i=0; i<21; i++){
        for(int j=0; j<21; j++) {
            w[0][i][j] = 1;
            w[0][j][i] = 1;
            w[i][0][j] = 1;
            w[j][0][i] = 1;
            w[i][j][0] = 1;
            w[j][i][0] = 1;
        }
    }
    int a, b, c;
    for (int k=2; k<21; k++){
        for (int i=1; i <= k; i++){
            for (int j=1; j <= k; j++){
                for (int m=1; m <= k; m++){
                    if (i < j && j < m) {
                        w[i][j][m] = w[i][j][m-1] + w[i][j-1][m-1] - w[i][j-1][m];
                    }
                    else {
                        w[i][j][m] = w[i-1][j][m] + w[i-1][j-1][m] + w[i-1][j][m-1] - w[i-1][j-1][m-1];

                    }
                }
            }            
        }
    }

    while(true) {
        int a, b, c, result;
        scanf("%d %d %d", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1) break;

        if (a <=0 || b <= 0 || c <= 0) result = 1;
        else if (a > 20 || b > 20 || c > 20) result = w[20][20][20];
        else result = w[a][b][c];

        printf("w(%d, %d, %d) = %d\n", a, b, c, result);
    }
    return 0;
}