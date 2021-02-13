#include <iostream>
#include <vector>
#include <algorithm>
#define INT_MAX 987654321
using namespace std;

int main(void){
    string input;
    cin >> input;
    int len_input = input.size();
    vector<vector<bool> > is_palindrome(len_input, vector<bool>(len_input, false));
    vector<int> min_size(len_input, INT_MAX);

    for (int dif = 0; dif < len_input; dif++) {
        for (int start = 0; start + dif < len_input; start++) {
            int end = start + dif;
            if (start == end){
                is_palindrome[start][end] = true;
            }
            else if (start + 1 == end) {
                is_palindrome[start][end] = (input[start] == input[end]);
            }
            else {
                is_palindrome[start][end] 
                    = (input[start] == input[end] && is_palindrome[start+1][end-1]);
            }
        }
    }

    for (int end = 0; end < len_input; end++) {
        for (int start = 0; start <= end; start++) {
            if (is_palindrome[start][end]) {
                if (start == 0) min_size[end] = 1;
                else min_size[end] = min(min_size[end], min_size[start-1] + 1);
            }
        }
    }
    
    printf("%d", min_size[len_input-1]);
    
    return 0;
}