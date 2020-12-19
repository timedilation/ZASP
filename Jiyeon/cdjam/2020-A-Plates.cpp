#include <iostream>
#include <algorithm>
using namespace::std;

/*
* N<=3 일 때는 그냥 모든 조합을 다 테스트할 수 있는데 이제 커지면 조합의 수가 (p+1)Cn이되면서...
* 위의 경우도 구현하긴 했어야 할 것 같은데 넘귀찮다 담부터하는걸로(...)
* 시작부터의 합을 계산해야 할 것 같긴 했는데 P만 변화시키고 N을 변화시킬 생각을 못함
* 결국 답보고 풀었음.. 알골 알아도 실제 구현에서 인덱스/초기화때문에 한참 고생함
* 인덱스 규칙을 확실하게 세워야 할 듯
*/

int main()
{
    int T;
    cin >> T;
    for(int tc=1; tc<=T; tc++) {
        int N, K, P, maxval = 0;
        cin >> N >> K >> P;
        
        int** valsums = (int**) malloc(N * sizeof(int*));
        for(int i=0; i<N; i++)
            valsums[i] = (int*) malloc((K+1) * sizeof(int));
        
        for(int n = 0; n < N; n++) {
            int sum = 0;
            int val;
            valsums[n][0] = 0;
            for(int k=1; k <= K; k++) {
                cin >> val;
                sum += val;
                valsums[n][k] = sum;
            }
        }
        
        int** maxvals = (int**) malloc((N+1) * sizeof(int*));
        for(int i=0; i<=N; i++)
            maxvals[i] = (int*) malloc((P+1) * sizeof(int));
            
        for(int p = 0; p <= P; p++) {
            maxvals[0][p] = 0;
        }
        
        for(int n = 1; n <= N; n++) {
            for(int p = 0; p <= P; p++) {
                int temp_max = 0;
                for(int i = 0; i <= min(K,p); i++) {
                    int sum_i = maxvals[n-1][p-i] + valsums[n-1][i];
                    temp_max = max(temp_max, sum_i);
                }
                maxvals[n][p] = temp_max;
            }
        }
        
        
        cout << "Case #" << tc << ": " << maxvals[N][P] << endl;
        
        for(int i=0; i<N; i++) {
            free(valsums[i]);
            free(maxvals[i]);
        }
        free(maxvals);
        free(valsums);
    }
}