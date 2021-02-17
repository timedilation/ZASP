#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int len_of_series, num_of_questions;
    scanf("%d", &len_of_series);
    vector<int> series(2000);
    int start, end;
    vector<vector<bool> > palindrome(len_of_series, vector<bool>(len_of_series, false));

    for (int i = 0; i < len_of_series; i++){
        scanf("%d", &series[i]);
    }

    for (int dif = 0; dif < len_of_series; dif++) {
        for (int start = 0; start + dif < len_of_series; start++) {
            int end = start + dif;
            if (start == end) {
                palindrome[start][end] = true;
            }
            else if (start + 1 == end) {
                palindrome[start][end] = (series[start] == series[end]);
            }
            else {
                palindrome[start][end] = 
                    (series[start] == series[end]) && palindrome[start+1][end-1];
            }
        }
    }
    
    scanf("%d", &num_of_questions);
    for (int i = 0; i < num_of_questions; i++){
        scanf("%d %d", &start, &end);
        printf("%d\n", palindrome[start-1][end-1]);
    }
    
    return 0;   
}