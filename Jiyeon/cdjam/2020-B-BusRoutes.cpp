#include <iostream>
#include <vector>
using namespace::std;

/*
* 알고리즘은 O(N)으로 잘 짰는데 D,routes 자료형을 int로 해갖고 long에서 계속 runtime error남
* 그리고 N * long int 의 크기가 1GB를 넘는지 계산을 잘 못해갖고..
* long이 8byte니까 1000*8로 8000bytes~8KB밖에 안됐음.
*/

int main()
{
	int T;
	cin >> T;
	for(int currT=1; currT<=T; currT++) {
		int N;
		long int D;
		cin >> N >> D;
		vector<long int> routes(N);
		for (int i=0; i<N; i++) {
			cin >> routes[i];
		}
		for(int i=N-1; i>=0; i--) {
			D = (D/routes[i]) * routes[i];
		}
		cout << "Case #" << currT << ": " << D << endl;
	}
}
