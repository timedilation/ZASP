#include <iostream>
using namespace std;

char buf[200010];
int main(void){
    int N;
    long long sum = 0;
    int i=0, j=0;
    long long cities[100000];
    long long distances[100000];
    scanf("%d", &N);
    for (int i=0; i<N-1; i++) scanf("%lld", &distances[i]);
    for (int i=0; i<N; i++) scanf("%lld", &cities[i]);

    for (i=0; i<N-1; i++) {
        long long temp_weight = distances[i] * cities[i];
        sum += temp_weight;
        for (j=i+1; j<N-1; j++) {
            if (cities[i] <= cities[j]) {
                temp_weight = distances[j] * cities[i];
                sum += temp_weight;
                if (j == N-2) {
                    i = N;
                    break;
                }
            }
            else{
                i = j-1;
                break;
            }
        }
    }

    printf("%lld", sum);

    return 0;
}