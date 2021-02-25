#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void) {
    int num_towers;
    scanf("%d", &num_towers);
    stack<pair<int, int> > towers;
    vector<int> receivers(num_towers, 0);
    int highest = 0;

    for (int i = 0; i < num_towers; i++) {
        int tmp = 0;
        scanf("%d", &tmp);
        while (not towers.empty()) {
            if (towers.top().first < tmp) {
                towers.pop();
            }
            else {
                receivers[i] = towers.top().second + 1;
                break;
            }
        }
        towers.push(make_pair(tmp, i));
    }
    for (int it : receivers) {
        printf("%d ", it);
    }

    return 0;
}