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
*
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
        
        int minDiff, ksum;
        for(minDiff=1; minDiff <= 1000000000; minDiff++) {
            ksum = 0;
            vector<int>::iterator diff;
            for(diff = initialDiffs.begin(); diff != initialDiffs.end(); diff++) {
                ksum += ((*diff + minDiff-1)/minDiff - 1);
                if(ksum > K)
                    break;
            }
            if(ksum <= K)
                break;
        }
        
        
        
        cout << "Case #" << tc << ": " << minDiff << endl;
    }
}