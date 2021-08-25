#include <iostream>
#include <vector>
#include <string>
using namespace::std;


int main()
{
	int T;
	cin >> T;
	for(int currT=1; currT<=T; currT++) {
		int N, K;
		string str;
		cin >> N >> K >> str;
		
		int currScore = 0;
		for(int i=0; i<N/2; i++) {
			if(str[i] != str[N-1-i])
				currScore++;
		}
		
		if(currScore > K)
			cout << "Case #" << currT << ": " << currScore - K << endl;
		else
			cout << "Case #" << currT << ": " << K - currScore << endl;
	}

	return 0;
}
