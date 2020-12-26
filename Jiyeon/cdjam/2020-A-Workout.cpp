#include <iostream>
#include <vector>
using namespace::std;

/*
* 
* 첨에는 제일 큰 공간 안에 넣을 수 있는 최소 구하고 다시 재귀적으로 계산하는 생각 했는데
* 그렇게 하면 맨 처음에 나누는걸로 고정되어버리니 optimal이 안될듯해서 답봄.
* 역시 N을 키울 때는 작을 때와는 전혀 다른 로직으로 구현해야한다.. 그 핵심 되는 변수를 잘 못찾아내고 있는듯
* short 통과 long 타임아웃. 귀찮아서 그냥 이진탐색 구현 안해서 그랬나봄..
* 졸려서 낼 수정하고 다시 올리기
* -> 이진탐색 구현하는데 더걸림.. 양쪽 경계를 명확히 안세워서 첨에 그냥 left=target했다가 꼬여버림
* 시간복잡도 O(log(10^9)*N)
*/


int main()
{
    int T;
    cin >> T;
    for(int tc=1; tc<=T; tc++) {
        int N, K;
        vector<int> initialDiffs;
        cin >> N >> K;
        int prevM = 0, currM;
        cin >> prevM;
        for(int m=1; m<N; m++) {
            cin >> currM;
            initialDiffs.push_back(currM - prevM);
            prevM = currM;
        }
        
        int ksum, left=1, right=1000000000, target;
        while(left != right) {
            int oldtarget = target;
            target = left + (right-left)/2;
            ksum = 0;
            vector<int>::iterator diff;
            for(diff = initialDiffs.begin(); diff != initialDiffs.end(); diff++) {
                ksum += ((*diff + target-1)/target- 1);
                if(ksum > K) {
                    left = target+1;
                    break;
                }
            }
            if(ksum <= K) {
                right = target;
            }
        }
        
        cout << "Case #" << tc << ": " << left << endl;
    }
}
