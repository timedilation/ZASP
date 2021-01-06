#include <iostream>
using namespace::std;

/*
* 와 첨에 계속 short에서 실패해서 대체 뭐가 잘못된거지 했는데
* isIncreased 변수 초기화 안해서 그런거였음.. 초기화 잊지말기
*/

int main()
{
	int T;
	cin >> T;
	for(int currT=1; currT<=T; currT++) {
		int N, peakNum = 0, prev, curr;
		bool isIncreased = false;
		cin >> N >> prev;
		while(--N) {
			cin >> curr;
			if(curr > prev) {
				isIncreased = true;
			} else {
				if(curr < prev && isIncreased)
					peakNum++;
				isIncreased = false;
			}
			prev = curr;
		}
		cout << "Case #" << currT << ": " << peakNum << endl;
	}
}
