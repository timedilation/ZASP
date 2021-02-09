#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#define INT_MAX 987654321
using namespace std;

class MemCost { 
public:
    int memory, cost;
    int operator<(MemCost &other) {
        return this->cost < other.cost;
    }
};

int maxint(long long a, long long b) {
    return a > b ? a : b;
}

int main(void){
    int N, M;
    scanf("%d %d", &N, &M);
    vector<MemCost> v(N);
    vector<int> max_at_cost(10001, 0);
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i].memory);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i].cost);
    }

    int result = INT_MAX;
    for (int j = 0; j < N; j++) {
        for(int curr=10000; curr>=v[j].cost; curr--) {
            if(curr >= v[j].cost) {
                max_at_cost[curr] = maxint(max_at_cost[curr], max_at_cost[curr-v[j].cost] + v[j].memory);
                if (max_at_cost[curr] >= M) {
                    result = curr < result ? curr : result;
                }
            }
        }
    }
    
    printf("%d", result);
    return 0;
}