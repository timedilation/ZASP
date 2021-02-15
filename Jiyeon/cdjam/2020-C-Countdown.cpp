#include <iostream>
using namespace::std;

/*
* main return 1; 로 했더니 제출시 runtime error남...
*/

void countdown(int currT, int N, int K);

int main()
{
	int T;
	cin >> T;
	for(int currT=1; currT<=T; currT++) {
		int N, K;

		cin >> N >> K;
		countdown(currT, N, K);
	}
	return 0;
}

void countdown(int currT, int N, int K)
{
	int prev_n, curr_n, countdown = 1, k_countdown = 0;
	cin >> prev_n;
	for(int i=1; i<N; i++) {
		cin >> curr_n;
		if((prev_n - curr_n) == 1) {
			countdown++;
		} else {
			countdown = 1;
		}
		if ((curr_n == 1) && (countdown >= K)){
			k_countdown++;
		}
		prev_n = curr_n;
	}
	cout << "Case #" << currT << ": " << k_countdown << endl;
}
