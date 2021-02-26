#include <iostream>
#include <vector>
using namespace::std;

/*
*
* short도 한번 짜보기
* long은 topological sort라는 생각을 못해서 방향은 맞는데 세부 구현에서 헤매다 풀이 봄
* 순서가 있는 정렬에 활용하기!
*/

#define ALPHABET_NUM 26
void build_wall_short();
void build_wall_long();


int main()
{
	int T;
	cin >> T;
	for(int currT=1; currT<=T; currT++) {
		int R, C;

		cin >> R >> C;
		build_wall_short(R, C);
	}
	return 0;
}


void build_wall_short(int R, int C)
{
	char wall[R][C];
	bool checkPoly[ALPHABE_NUM] = {0};
	vector<char> polys;

	for(int i=0;i<R;i++) {
		for(int j=0; j<C; j++) {
			char c;
			cin >> c;
			wall[i][j] = c;
			if(!checkPoly[c - 'A']) {
				checkPoly[c - 'A'] = 1;
				polys.push_back(c);
			}
		}
	}
}

void build_wall_long()
{
	bool isGrounded[R][C] = {0};
	int numPolySquare[26] = {0};
	int isPolyBuild[26] = {0};
	int numPolyGroundSquare[26] = {0};
	for(int i=0;i<R;i++) {
		for(int j=0; j<C; j++) {
			cin >> wall[i][j];
			numPolySquare[wall[i][j]-'A']++;
		}
	}

	bool notchange = false;
	while(!notchange) {
		notchange = true;

		for(int i=R-2; i>=0; i--) {
			for(int j=0; j<C; j++) {
				if(i == R-1) {
					isGrounded[i][j] = true;
				} else {
					isGrounded[i][j] = (wall[i][j] == wall[i+1][j]) || isGrounded[i+1][j];
				}
				if(isGrounded[i][j]) {
					numPolyGroundSquare[wall[R-1][j]-'A']++;
				}

			}
		}

		for(int k=0; k<26; k++) {
			if(numPolySquare[k] == numPolyGroundSquare[k]) {
				for(int i=0;i<R;i++) {
					for(int j=0; j<C; j++) {
					}
				}
			}
		}
	}
}
