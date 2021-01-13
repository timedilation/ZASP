#include <iostream>
#include <vector>
#include <cstdint>
using namespace::std;

/*
* 알고리즘은 맞았는데 uint64_t 저거 때문에 두시간반 고생함..
* 일단 오버플로 나는지 확인을 제대로 안했고,
* 두번째로 곱하는데 앞에 타입 캐스팅을 해주지 않으면 어사인 받는 쪽이 커도 안된다는것을 깨달음
*/

int main()
{
	int T;
	cin >> T;
	for(int currT=1; currT<=T; currT++) {
		vector<vector<unsigned int>*> paren_stack;
		char program[2001];
		vector<unsigned int>* NSEW = new vector<unsigned int>(5, 0);
		cin >> program;
		int stack9=0;

		for(int i=0; i<2000; i++){
			char c = program[i];
			switch(c) {
				case '\0':
					i = 2000;
					break;
				case 'N':
					(*NSEW)[0]++;
					break;
				case 'S':
					(*NSEW)[1]++;
					break;
				case 'E':
					(*NSEW)[2]++;
					break;
				case 'W':
					(*NSEW)[3]++;
					break;
				case '(':
					break;
				case ')': {
					vector<unsigned int>* sub_NSEW= NSEW;
					NSEW = paren_stack.back();
					int repeat = (*NSEW)[4];
					for(int i=0; i<4; i++) {
						uint64_t sub_move = (uint64_t) ((*sub_NSEW)[i]) * repeat + (*NSEW)[i];
						sub_move = sub_move % 1000000000;
						(*NSEW)[i] = sub_move;
					}
					paren_stack.pop_back();
					break;
				}
				case '2' ... '9': {
					(*NSEW)[4] = c - '0';
					paren_stack.push_back(NSEW);
					NSEW = new vector<unsigned int>(5,0);
					break;
				}
			}
		}
		int S = (*NSEW)[1] - (*NSEW)[0];
		int E = (*NSEW)[2] - (*NSEW)[3];
		if(S < 0) S += 1000000000;
		if(E < 0) E += 1000000000;

		cout << "Case #" << currT << ": " << E+1 << ' ' << S+1 << endl;
	}
}
