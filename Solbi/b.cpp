#include <stdio.h>
#include <iostream>
#include <vector>


using namespace std;

int cnt;

int cut_land(vector <int> v, int start){

	int max = -1; 
	int min = 1001;

	int now = start+1;
	while(v[now] == v[start] && v.size()!= now){
		now ++;
	}
	if(now == v.size()){
		cnt--;
		return now-1;
	}

	if(v[now]> v[start]){
		max = v[now];
		now++;
	}
	else if (v[now]< v[start]){
		min = v[now];
		now++;
	}

	if(max!= -1){
		while(v.size()!= now){

			if(v[now]> max){
				max = v[now];
			}
			else if(v[now]< max){
				if(now != v.size()-1)
					cnt++;
				return now;
			}
			now++;
		}
	}

	else if(min!= 1001){
		while(v.size()!= now){

			if(v[now]< min){
				min = v[now];
			}
			else if(v[now] > min){
				if(now != v.size()-1)
					cnt++;
				return now;
			}
			now++;
		}
	}

	//if get reached

	cnt--;
	return now-1;
}



int main(){

	int T, K, i, j, tmp;
	vector <int> v;

	scanf("%d", &T);

	for(i = 0; i < T; i++){
		v.clear();
		cnt = 0;
		scanf("%d", &K);

		for(j = 0; j<= K; j++){
			scanf("%d", &tmp);
			v.push_back(tmp);
		}
		int index = 0;
		while(index < v.size()-1){
			index = cut_land(v, index);
			// cout<<index<<"****\n";
		}
		if(cnt == -1){
			cnt = 0;
		}
		printf("Case #%d: %d\n", i+1,cnt);

	}

	return 0;
}