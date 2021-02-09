#include <iostream>
#include <cmath>
using namespace::std;

/*
* short: DP
* short는 DP가 아직 잘 감이 안오는듯 익혀두면 좋을 것 같아서 숏도 풀음
* 첨에 실수한게 마지막 칸 예외를 안두고 싶어서 첨에 오른쪽/아래 맨 끝 열과 행을 다 1로 칠하고
* H-1 W-1인 칸들만 계산했는데 이렇게 하면 1행/1열짜리가 제대로 계산이 안됨
* 그래서 양 끝 열일 경우 아래나 오른쪽 확률만 따라가게 바꿔야 했음.
*
* long: 조합 사용
* long은 비슷하게 생각은 했는데 꼭 지나가야 하는 포인트 안겹치게 나누는 데서 막혀서 아닌가보다했음..
* 겹치지 않게만 고르면 되는데 그 생각을 못함
* 근데 조합을 코드로 구현하는 것도 첨인듯 팩토리얼 계산이랑 큰 수에 로그씌우기 이런거..
* 데이터 사이즈때문에 계속 헤맴 처음에는 factorial을 다 계산한다음에 로그를 씌워서 fact자체가 인티저 범위를 넘어갔고,
* 두번째로는 factorial memo 크기를 10^5로만 제한해서.. L+D니까 2*10^5가 됐어야 함.
* 알고리즘을 알고서도 푸는데 진짜 오래걸렸다
*/

double fact_memo[200001];
int fact_calced;

double logfactorial(int n) {
	if(n > fact_calced) {
		for(int i = fact_calced+1; i <= n; i++) {
			fact_memo[i] = fact_memo[i-1] + log10(i);
		}
		fact_calced = n;
	}
	return fact_memo[n];
}

void long_tc(int currT, int W, int H, int L, int U, int R, int D);
void short_tc(int currT, int W, int H, int L, int U, int R, int D);

int main()
{
	int T;
	cin >> T;
	fact_calced = 1;
	fact_memo[0] = 0;
	fact_memo[1] = 0;
	for(int currT=1; currT<=T; currT++) {
		int W, H, L, U, R, D;

		cin >> W >> H >> L >> U >> R >> D;
		//short_tc(currT, W, H, L, U, R, D);
		long_tc(currT, W, H, L, U, R, D);
	}
	return 1;
}

void short_tc(int currT, int W, int H, int L, int U, int R, int D)
{
		float prob[W][H];

		for(int x=W; x>0; x--) {
			for(int y=H; y>0; y--) {
				if((x == W) && (y == H))
					prob[x-1][y-1] = 1;
				else if((L <= x) && (x <= R) && (U <= y) && (y <= D))
					prob[x-1][y-1] = 0;
				else {
					if(x == W)
						prob[x-1][y-1] = prob[x-1][y];
					else if(y == H)
						prob[x-1][y-1] = prob[x][y-1];
					else
						prob[x-1][y-1] = prob[x][y-1] * 0.5 + prob[x-1][y] * 0.5;
				}
			}
		}
		
		cout << "Case #" << currT << ": ";
		cout.precision(6);
		cout << prob[0][0] << endl;
}

void long_tc(int currT, int W, int H, int L, int U, int R, int D)
{
	double prob = 0.0;

	if(D < H) {
		for(int k=L-2; k>=0; k--) {
			double temp_prob = logfactorial(L+D-2) - logfactorial(k) - logfactorial(L+D-2-k) - (L+D-2)*log10(2);
			temp_prob = pow(10.0, temp_prob);
			prob += temp_prob;
		}
	}
	if(R < W) {
		for(int k=U-2; k>=0; k--) {
			double temp_prob = logfactorial(R+U-2) - logfactorial(k) - logfactorial(R+U-2-k) - (R+U-2)*log10(2);
			temp_prob = pow(10.0, temp_prob);
			prob += temp_prob;
		}
	}

	cout << "Case #" << currT << ": ";
	cout.precision(6);
	cout << prob << endl;
}
