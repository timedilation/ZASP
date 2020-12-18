#include <iostream>
#include <vector>
using namespace::std;

/*
*
* 쉬운문제? 보자마자 어케 해야할지 감이 잡힘
* 최악의 경우 모든 집들을 전부 구매할 수 있는데, 뒤에 나오는 집이 계속 더 제일싸서 앞이랑 계속 비교해야하는경우 O(n^2)
* 넣을 위치 찾는걸 반씩 쪼개서 구현하면 O(nlogn)은 될 것 같은데 귀찮다..
*
*/

int main()
{
	int T;
	cin >> T;
	for(int currT=1; currT<=T; currT++) {
		int N, B, A;
		vector<int> purchased;
		int sum = 0;
		cin >> N >> B;
		while(N--) {
			cin >> A;
			vector<int>::reverse_iterator it = purchased.rbegin();
			while((it != purchased.rend()) && (*it > A)) { it++; }
			purchased.insert(it.base(), A);
			sum += A;
			while(sum > B) {
				sum -= purchased.back();
				purchased.pop_back();
			}
		}
		cout << "Case #" << currT << ": " << purchased.size() << endl;
	}
}
